#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    if (head == 0 || head->next == 0) return head;
    struct ListNode *smalls=0, *bigs=0, *snow=0, *bnow=0, *now=head;
    
    while (now != 0){
        if (now->val < x){
            if (smalls != 0){
                snow->next = now;
                snow = snow->next;
            }else{
                smalls = now;
                snow = now;
            }
        }else{
            if (bigs != 0){
                bnow->next = now;
                bnow = bnow->next;
            }else{
                bigs = now;
                bnow = now;
            }
        }
        now = now->next;
    }
    if (smalls != 0){
        head = smalls;
        snow->next = bigs;
        if (bnow != 0)
            bnow->next = 0;
    }else{
        head = bigs;
        bnow->next = 0;
    }
    return head;
}

int main() {
    struct ListNode n1 = {1, NULL}, n2 = {4, NULL}, n3 = {3, NULL},
                    n4 = {2, NULL}, n5 = {5, NULL}, n6 = {2, NULL};
    n1.next = &n2; n2.next = &n3; n3.next = &n4;
    n4.next = &n5; n5.next = &n6;

    printf("x=3 前: ");
    for (struct ListNode* p = &n1; p; p = p->next)
        printf("%d ", p->val);

    struct ListNode* head = partition(&n1, 3);

    printf("\nx=3 后: ");
    for (struct ListNode* p = head; p; p = p->next)
        printf("%d ", p->val);
    return 0;
}