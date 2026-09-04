#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || head == NULL) return head;
    int len = 0;
    struct ListNode* now = head;
    while (now->next) {
        len++;
        now = now->next;
    }
    len++;
    if (len < 1) return head;
    k = len - (k % len);
    now->next = head;
    for (int i = 0; i < k; i++){
        now = now->next;
    }
    head = now->next;
    now->next = 0;
    return head;
}

int main() {
    struct ListNode n1 = {1, NULL}, n2 = {2, NULL}, n3 = {3, NULL},
                    n4 = {4, NULL}, n5 = {5, NULL};
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;

    struct ListNode* head = rotateRight(&n1, 5);

    for (struct ListNode* p = head; p; p = p->next)
        printf("%d ", p->val);
    return 0;
}