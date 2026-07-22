#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = nullptr;
        int i = 0, j;
        while (l1 != nullptr && l2 != nullptr)
        {
            j = l1->val + l2->val + i;
            i = j / 10;
            j = j % 10;
            ans = new ListNode(j, ans);
            l1 = l1->next, l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            j = l1->val + i;
            i = j / 10;
            j = j % 10;
            ans = new ListNode(j, ans);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            j = l2->val + i;
            i = j / 10;
            j = j % 10;
            ans = new ListNode(j, ans);
            l2 = l2->next;
        }
        if (i)
            ans = new ListNode(i, ans);
        vector<int> answer;
        while (ans != nullptr)
        {
            answer.push_back(ans->val);
            ans = ans->next;
        }
        for (int i = 0; i < answer.size(); i ++)
        {
            ans = new ListNode(answer[i], ans);
        }
        return ans;
    }
};

int main()
{
    Solution o;
    vector<int> n1 = {9, 9, 9, 9, 9, 9, 9}, n2 = {9, 9, 9, 9};
    ListNode *l1 = nullptr, *l2 = nullptr;
    for (int i = 0; i < n1.size(); i ++)
    {
        l1 = new ListNode(n1[i], l1);
    }
    for (int i = 0; i < n2.size(); i ++)
    {
        l2 = new ListNode(n2[i], l2);
    }
   	ListNode * result = o.addTwoNumbers(l1, l2);
    while (result != nullptr)
    {
        cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}