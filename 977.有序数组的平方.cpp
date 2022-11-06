#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
/*
 * 暴力排序
*/
class MySolution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};
/*
 * 使用平方，按照升序排序，原本负数集合是按照降序排序，原本非负数集合是按照升序排序
 * 之后只要找到分界线，然后分界线俩边进行比较之后将小的一方 push 到结果容器里面即可
*/
/*
 * 需要注意的地方：
 * 1.循环边界问题：while(left >= 0 || right < n) : 只有 left < 0 && right >= n 才会结束循环，表示所有的数都已经进行遍历过
 * 2.其中出现的情况问题：由于为了全部遍历完，会导致有一边已经完全遍历，但是另一边并没有所以需要进行判断 
*/
class StandardSolution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int dividingLine = 0;
        int left = 0,right = 0;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                dividingLine = i;
            }
            else 
            {
                break;
            }
        }
        printf("%d",dividingLine);
        left = dividingLine;
        right = dividingLine + 1;
        while (left > -1 || right < nums.size())
        {
            if (left < 0)
            {
                result.push_back(nums[right] * nums[right]);
                right++;
            }
            else if (right > nums.size() - 1)
            {
                result.push_back(nums[left] * nums[left]);
                left--;
            }
            else if (nums[left] * nums[left] > nums[right] * nums[right])
            {
                result.push_back(nums[right] * nums[right]);
                right++;
            }
            else{
                result.push_back(nums[left] * nums[left]);
                left--;
            }
        }
        return result;
    }
};
/*
 * 同样是根据升序的规律进行优化，
 * 使用双指针，从最左边&最右边，向中间递归。将其中最大的按照逆序放入到提前定长的vector
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int left = 0,right = n - 1,index = n - 1; left <= right;) 
        {
            if (nums[left]*nums[left] > nums[right]*nums[right])
            {
                result[index] = nums[left] * nums[left];
                ++left;
            }
            else
            {
                result[index] = nums[right] * nums[right];
                --right;
            }
            index--;
        }
        return result;
    }    
};

// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> example;
    example.push_back(-4);
    example.push_back(-1);
    example.push_back(0);
    example.push_back(3);
    example.push_back(10);
    Solution *s = new Solution;
    s->sortedSquares(example);
    return 0;
}

