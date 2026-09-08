#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == 0 || head->next == 0 || k <= 1) return head;
    struct ListNode *now = head, *newhead = 0;
    int len = 0;
    while (now != 0)  len++, now = now->next;
    if (len < k) return head;
    struct ListNode *preTail = 0, *pre, *nt, *newTail;
    int i = 1;
    now = head;
    pre = 0;
    len = (len / k) * k;
    while (i <= len){
        if (i % k == 1){
            newTail = now;
        }
        nt = now->next;
        now->next = pre;
        pre = now;
        now = nt;
        if (!(i % k)){
            if (preTail) preTail->next = pre;
            else newhead = pre;
            preTail = newTail;
            newTail->next = now;
            pre = 0;
        }
        i++;
    }
    preTail->next = now;
    return newhead;
}

int main() {
    struct ListNode n1 = {1, NULL}, n2 = {2, NULL}, n3 = {3, NULL},
                    n4 = {4, NULL}, n5 = {5, NULL};
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;

    int k = 1;
    printf("k=%d 前: ", k);
    for (struct ListNode* p = &n1; p; p = p->next)
        printf("%d ", p->val);

    struct ListNode* head = reverseKGroup(&n1, k);

    printf("\nk=%d 后: ", k);
    for (struct ListNode* p = head; p; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    struct ListNode m1 = {1, NULL}, m2 = {2, NULL}, m3 = {3, NULL},
                    m4 = {4, NULL}, m5 = {5, NULL};
    m1.next = &m2; m2.next = &m3; m3.next = &m4; m4.next = &m5;

    k = 3;
    printf("k=%d 前: ", k);
    for (struct ListNode* p = &m1; p; p = p->next)
        printf("%d ", p->val);

    head = reverseKGroup(&m1, k);

    printf("\nk=%d 后: ", k);
    for (struct ListNode* p = head; p; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    return 0;
}