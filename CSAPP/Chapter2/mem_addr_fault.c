/**
 * CSAPP Demo: 访问远大于物理内存的虚拟地址会发生什么？
 *
 * 核心知识点：虚拟内存、页表、MMU、缺页异常、SIGSEGV
 *
 * 我们尝试读写虚拟地址 2^42（约 4 TB）。
 * 即使你的电脑有 4 TB 物理内存，这个地址也没有被映射到任何页表条目，
 * 因为它从未被 malloc/mmap/brk 分配过。
 *
 * 执行流程：
 *   CPU 尝试访问地址 → MMU 查页表 → PTE 无效（未映射）
 *   → 硬件缺页异常 → OS 缺页处理程序检查
 *   → 发现地址不在任何映射区域（栈/堆/数据段/代码段）
 *   → 发送 SIGSEGV → 进程终止（或被信号 handler 捕获）
 *
 * 编译：gcc mem_addr_fault.c -o mem_addr_fault && ./mem_addr_fault
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/* 2^42 = 4,398,046,511,104 = 0x40000000000
 * 这是有效的 48 位虚拟地址，但没有任何物理页映射给它 */
#define TARGET_ADDR  ((void *)0x40000000000ULL)
#define KB           (1024ULL)
#define MB           (KB * 1024)
#define GB           (MB * 1024)
#define TB           (GB * 1024)

/* 虚拟地址层级的标记位 */
#define VA_BITS      48      /* x86-64 典型虚拟地址位数 */

static void segfault_handler(int sig)
{
    printf("\n===========================================\n");
    printf(" 捕获信号 %d (SIGSEGV) - 段错误！\n", sig);
    printf("===========================================\n\n");

    printf("┌─ 发生了什么？─────────────────────────────────────────┐\n");
    printf("│ 1. 程序试图读写虚拟地址 0x40000000000 (2^42)         │\n");
    printf("│ 2. CPU 的 MMU（内存管理单元）将 VA 转为 PA          │\n");
    printf("│ 3. MMU 遍历页表（Page Table Walk），查找对应 PTE     │\n");
    printf("│ 4. PTE 的 Present 位 = 0 → 该虚拟页不在物理内存中  │\n");
    printf("│ 5. CPU 触发缺页异常（Page Fault），陷入 OS 内核     │\n");
    printf("│ 6. OS 检查该地址是否应被映射（lookup VMA）          │\n");
    printf("│ 7. 该地址不在任何 VMA 区域 → 非法访问               │\n");
    printf("│ 8. OS 发送 SIGSEGV 给进程                           │\n");
    printf("└───────────────────────────────────────────────────────┘\n\n");

    printf("  ● 地址 0x40000000000 = %llu 字节 = %llu TB\n",
           0x40000000000ULL, 0x40000000000ULL / TB);
    printf("  ● 你的物理内存：    远小于 4 TB\n");
    printf("  ● 关键是：这个地址从未被 malloc/brk/mmap 分配过\n");
    printf("  ● 结论：访问未映射的虚拟地址 → 段错误\n\n");

    /* 如果 signal handler 返回不 exit，程序会重新执行 fault 指令，
     * 再次触发信号 → 无限循环。所以必须退出。 */
    printf("按 Ctrl+C 退出（或等待自动退出）...\n");
    _exit(1);
}

static void print_mapping_info(void)
{
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║     CSAPP 实验：虚拟内存访问未映射地址                    ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");

    printf("[系统信息]\n");
    printf("  虚拟地址位数:        %d 位\n", VA_BITS);
    printf("  虚拟地址空间大小:    %llu 字节 (%llu TB)\n",
           1ULL << VA_BITS, (1ULL << VA_BITS) / TB);
    printf("  目标虚拟地址:        %p (2^42)\n", TARGET_ADDR);
    printf("  目标地址值:          %llu 字节 = %llu GB = %llu TB\n\n",
           0x40000000000ULL, 0x40000000000ULL / GB, 0x40000000000ULL / TB);

    printf("[2^42 地址的页表分解]\n");
    printf("  对于 x86-64 四级页表（4K 页大小）：\n");
    printf("    VPN[3] (PML4):   位 39-47 → 索引 %d (0x%x)\n",
           (int)(0x40000000000ULL >> 39) & 0x1FF,
           (unsigned)(0x40000000000ULL >> 39) & 0x1FF);
    printf("    VPN[2] (PDPT):   位 30-38 → 索引 %d (0x%x)\n",
           (int)(0x40000000000ULL >> 30) & 0x1FF,
           (unsigned)(0x40000000000ULL >> 30) & 0x1FF);
    printf("    VPN[1] (PD):     位 21-29 → 索引 %d (0x%x)\n",
           (int)(0x40000000000ULL >> 21) & 0x1FF,
           (unsigned)(0x40000000000ULL >> 21) & 0x1FF);
    printf("    VPN[0] (PT):     位 12-20 → 索引 %d (0x%x)\n",
           (int)(0x40000000000ULL >> 12) & 0x1FF,
           (unsigned)(0x40000000000ULL >> 12) & 0x1FF);
    printf("    VPO (页内偏移):  位 0-11  → 偏移 %d (0x%x)\n\n",
           (int)(0x40000000000ULL & 0xFFF),
           (unsigned)(0x40000000000ULL & 0xFFF));

    printf("[写入 /proc/self/maps 查看当前进程的 VMA]\n");
    printf("  该地址 0x40000000000 不在以下任何区域中！\n");
    printf("  所以 MMU 查页表时，PML4E 本身就已为空（未分配页表下级）\n\n");
}

int main(void)
{
    /* 注册 SIGSEGV 信号处理函数 */
    signal(SIGSEGV, segfault_handler);

    print_mapping_info();

    printf("════════════════════════════════════════════════════════════\n");
    printf("现在尝试向 0x40000000000 (2^42) 写入一个字节...\n");
    printf("     *(volatile char *)0x40000000000 = 'A';\n");
    printf("════════════════════════════════════════════════════════════\n\n");
    fflush(stdout);

    /* ====== 触发缺页错误的指令 ====== */
    *(volatile char *)TARGET_ADDR = 'A';

    /* ====== 永不执行到这里 ====== */
    printf("！！！写入成功！这个地址居然被映射了（非常罕见）！！！\n");
    printf("读取值：%c\n", *(volatile char *)TARGET_ADDR);

    printf("\n按任意键退出...\n");
    system("pause");
    return 0;
}
