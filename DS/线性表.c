#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

Status InitList(SqList *L) {
    L->length = 0;
    return OK;
}

Status DestroyList(SqList *L) {
    L->length = 0;
    return OK;
}

Status ClearList(SqList *L) {
    L->length = 0;
    return OK;
}

Status ListEmpty(SqList L) {
    return L.length == 0 ? OK : ERROR;
}

int ListLength(SqList L) {
    return L.length;
}

Status GetElem(SqList L, int i, ElemType *e) {
    if (i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) {
    int pos = LocateElem(L, cur_e);
    if (pos <= 1)
        return ERROR;
    *pre_e = L.data[pos - 2];
    return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) {
    int pos = LocateElem(L, cur_e);
    if (pos == 0 || pos >= L.length)
        return ERROR;
    *next_e = L.data[pos];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) {
    int j;
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (L->length == MAXSIZE)
        return OVERFLOW;
    for (j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    int j;
    if (i < 1 || i > L->length)
        return ERROR;
    *e = L->data[i - 1];
    for (j = i; j < L->length; j++)
        L->data[j - 1] = L->data[j];
    L->length--;
    return OK;
}

Status ListTraverse(SqList L) {
    int i;
    if (L.length == 0) {
        printf("线性表为空。\n");
        return OK;
    }
    for (i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
    return OK;
}

int main() {
    SqList L;
    int choice, pos;
    ElemType e;

    InitList(&L);

    do {
        printf("\n========= 线性表菜单 =========\n");
        printf("1. 插入元素\n");
        printf("2. 删除元素\n");
        printf("3. 查找元素\n");
        printf("4. 获取元素\n");
        printf("5. 求前驱\n");
        printf("6. 求后继\n");
        printf("7. 判断是否为空\n");
        printf("8. 求表长\n");
        printf("9. 清空线性表\n");
        printf("10. 遍历输出\n");
        printf("0. 退出\n");
        printf("==============================\n");
        printf("请选择操作: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入插入位置和元素值: ");
            scanf("%d %d", &pos, &e);
            if (ListInsert(&L, pos, e) == OK)
                printf("插入成功。\n");
            else
                printf("插入失败。\n");
            break;
        case 2:
            printf("请输入删除位置: ");
            scanf("%d", &pos);
            if (ListDelete(&L, pos, &e) == OK)
                printf("删除成功，删除的元素为: %d\n", e);
            else
                printf("删除失败。\n");
            break;
        case 3:
            printf("请输入要查找的元素值: ");
            scanf("%d", &e);
            pos = LocateElem(L, e);
            if (pos)
                printf("元素 %d 在第 %d 个位置。\n", e, pos);
            else
                printf("未找到元素 %d。\n", e);
            break;
        case 4:
            printf("请输入要获取的位置: ");
            scanf("%d", &pos);
            if (GetElem(L, pos, &e) == OK)
                printf("第 %d 个元素的值为: %d\n", pos, e);
            else
                printf("获取失败。\n");
            break;
        case 5:
            printf("请输入元素值: ");
            scanf("%d", &e);
            {
                ElemType pre_e;
                if (PriorElem(L, e, &pre_e) == OK)
                    printf("元素 %d 的前驱为: %d\n", e, pre_e);
                else
                    printf("无前驱或元素不存在。\n");
            }
            break;
        case 6:
            printf("请输入元素值: ");
            scanf("%d", &e);
            {
                ElemType next_e;
                if (NextElem(L, e, &next_e) == OK)
                    printf("元素 %d 的后继为: %d\n", e, next_e);
                else
                    printf("无后继或元素不存在。\n");
            }
            break;
        case 7:
            if (ListEmpty(L) == OK)
                printf("线性表为空。\n");
            else
                printf("线性表非空。\n");
            break;
        case 8:
            printf("线性表长度为: %d\n", ListLength(L));
            break;
        case 9:
            ClearList(&L);
            printf("线性表已清空。\n");
            break;
        case 10:
            ListTraverse(L);
            break;
        case 0:
            printf("退出程序。\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
        }
    } while (choice != 0);

    DestroyList(&L);
    return 0;
}