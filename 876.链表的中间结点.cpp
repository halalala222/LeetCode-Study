/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> ptrs;
        int listLength = 0;
        int middleIndex = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ptrs.push_back(cur);
            listLength += 1;
            cur = cur->next;
        }
        return ptrs[listLength / 2];
    }
};
/*
 * 这个想法没有想到过，使用一个 fast 指针每次走 slow 走的路程的俩倍
 * 然后限制条件为 fast 和 fast-> next 都不为空指针才会继续循环
 * 对于 fast 的条件限制：因为当节点数为奇数的时候 fast = fast->next->next 到最后刚到能够达到节点的最后一个节点。此时应当结束循环（fast->next = nuillptr）
 * 对于 fast-> 的条件限制：因为当节点数为偶数的时候 fast = fast->next->next 到最后会循环到最后一个节点的next处为 null，此时应当结束循环（fast = nullptr）
*/
class StandardSolution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end

