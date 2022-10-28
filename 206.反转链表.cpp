/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <algorithm>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * 根据题解的双指针进行书写
*/
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = head;
        ListNode *cur = nullptr;
        while (pre != nullptr)
        {
            ListNode *next = pre->next;
            pre->next = cur;
            cur = pre;
            pre = next;
        }
        return cur;
    }
};
// @lc code=end

