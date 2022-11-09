#include <stdio.h>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * 不优雅的，先转置后进行列表的删除，通过循环找到删除位置的前一个节点，
 * 由于边界设定问题，倒是如果删除位置是1的话，就会出现问题，这样子的话，需要多位置为1进行单独处理
*/
class MySolution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* pre = head;
        ListNode* cur = nullptr;
        while (pre != nullptr)
        {
            ListNode* next = pre->next;
            pre->next = cur;
            cur = pre;
            pre = next;
        }
        return cur;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* reverseList = reverse(head);
        ListNode* reverseHead = reverseList;
        int i;
        for (i = 1; i < n - 1; i++)
        {
            ListNode *next = reverseHead->next;
            if (next != nullptr)
            {
                reverseHead = next;
            }
        }
        if (n == 1)
        {
            return reverse(reverseList->next);
        }
        
        ListNode* next = reverseHead->next;
        if (next == nullptr)
        {
            reverseList = nullptr;
        }
        else
        {
            reverseHead->next = next->next;
        }
        return reverse(reverseList);
    }
};
/**
 * 官方提供的第一个方法，应该也不是优雅的方法，但是是能够想得到的方法
 * 看了题解，题解是新建在head之前添加了一个 value = 0 的节点，这样子就能够避免到
 * 第一个无法删除的问题。所以都需要对第一个头进行判断，以及循环边界问题。所以加一个节点感觉更好
*/

class StandardSolution1 {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

/*
 * 官方提供的使用栈进行解决，这个挺牛的，和我的转置想法一样，都是想从后往前数第几个
 * 而且加一个前驱节点之后边界问题就很好处理。
*/
class StandardSolution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* cur = dummy;
        stack<ListNode*> stk;
        while (cur != nullptr)
        {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; i++)
        {
            stk.pop();
        }
        cur = stk.top();
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

/*
 * 快慢双指针，这是我没有想到的做法
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* fast = head;
        ListNode* slow = dummy;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            slow = fast->next;
        }
        slow->next = slow->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

