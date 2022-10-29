/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> isExit;
        while (head != nullptr)
        {
            if (isExit.count(head))
            {
                return head;
            }
            isExit[head] = true;
            head = head->next;
        }
        return nullptr;
    }
};
/*
 * 使用 set 集合，没见过 cpp 的 set 下次可以使用一下
*/
class StandardSinglePtrSolution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr)
        {
            if (visited.count(head))
            {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

class DoublePtrSolution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};

// @lc code=end

