#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
 * 最后的例子使用 long long 查过限制了
*/
class MySolution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long l1Num = 0,l2Num = 0;
        ListNode* result = new ListNode(-1);
        ListNode* nodes = result;
        ListNode* temp;        
        // ListNode* curL1 = l1,*curL2 = l2;
        int count = 0;
        while (l1)
        {
            l1Num = l1Num + pow(10,count) * l1->val;
            l1 = l1->next;
            count++;
        }
        count = 0;
        while (l2)
        {
            l2Num = l2Num + pow(10,count) * l2->val;
            l2 = l2->next;
            count++;
        }
        long long resultNum = l1Num + l2Num;
        printf("%d\n",resultNum);
        if (!resultNum)
        {
            return new ListNode(0);
        }
        
        while (resultNum)
        {
            result->next = new ListNode(int(resultNum % 10));
            resultNum /= 10;
            result = result->next;
            printf("%d\n",resultNum);
        }
        return nodes->next;
    }
};

/**
 * 根据第一想法来进行修改的
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* nodes = result;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val;
            if (sum >= 10)
            {
                if (l1->next && l2->next)
                {
                    l1->next->val += 1;
                }
                else if (l1->next && !(l2->next))
                {
                    l2->next = new ListNode(1);
                }
                else
                {
                    l1->next = new ListNode(1);
                }
                sum -= 10;
            }
            result->next = new ListNode(sum);  
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        result->next = l1 ? l1 : l2; 
        return nodes->next;
    }
};
// @lc code=end

