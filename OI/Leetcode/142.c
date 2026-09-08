#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == 0 || head->next == 0) return 0;
    struct ListNode *slow = head, *fast = head;
    while (fast != 0 && fast->next != 0){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow){
            slow = head;
            while (slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return 0;
}

int main() {
    struct ListNode n1 = {3, NULL}, n2 = {2, NULL},
                    n3 = {0, NULL}, n4 = {-4, NULL};
    n1.next = &n2; n2.next = &n3; n3.next = &n4;
    n4.next = &n2;  // 环入口在 n2 (val=2)

    struct ListNode* entry = detectCycle(&n1);
    if (entry)
        printf("环入口: %d\n", entry->val);
    else
        printf("无环\n");
    return 0;
}