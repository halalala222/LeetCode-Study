/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
/*
    看了题解，与我的想法有点差距，我想的是在一个有序链表的基础上，将另一个链表进行拼接
    但是实现起来失败了。
    题解想的是：给一个新的节点，将这个节点进行循环俩个链表的节点，继续链下去
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* preLoad = new ListNode(-1);
        ListNode* pre = preLoad;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                pre->next = list2;
                list2 = list2->next;
            }
            else
            {
                pre->next = list1;
                list1 = list1->next;
            }
            pre = pre->next;
        }
        pre->next = list1 == nullptr ? list2 : list1;
        return preLoad->next;
    }
};
// @lc code=end

