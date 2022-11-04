#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int min = 0;
        if (target < nums[0] || target > nums[nums.size() - 1])
        {
            return -1;
        }
        // printf("left : %d",left);
        // printf("right : %d",right);
        while (left <= right)        
        {
            min = (left + right) / 2;
            // printf("min : %d",min);
            // printf("left : %d",left);
            // printf("right : %d",right); 
            if (target == nums[min])
            {
                return min;
            }
            if (target < nums[min])
            {
                right = min - 1;
            }
            if (target > nums[min])
            {
                left = min + 1;
            }
        }

        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    printf("-------------------start-------------------");
    vector<int> test;
    test.push_back(-1);
    test.push_back(0);
    test.push_back(3);
    test.push_back(5);
    test.push_back(9);
    test.push_back(12);
    for (int i = 0; i < test.size(); i++)
    {
        printf("%d",test[i]);
    }
    
    Solution *s = new(Solution);
    int num = s->search(test,9);
    printf("num : %d",num);
    return 0;
}
