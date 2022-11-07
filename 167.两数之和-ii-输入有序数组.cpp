#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
/**
 * 暴力循环在最后一个 test case 超时了，第19个case也会超时
*/
class SolutionOfTimeLimitExceeded {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int temp;
        vector<int> result;
        int n = numbers.size();
        for (int i = 0; i < n ; i++)
        {
            temp = target - numbers[i];
            for (int j = i + 1; j < n; j++)
            {
                if (numbers[j] > temp)
                {
                    break;
                }
                if (numbers[j] == temp)
                {
                    result.push_back(i + 1);
                    result.push_back(j + 1);
                }
                
            }
            
        }
        return result;
    }
};
/**
 * 双指针，
 * 题解：https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solution/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/
 * 题解的图很清晰，感觉如果使用双循环暴力，一次确实是只能遍历其中的一个单元格
 * 但是如果使用如图的双指针，一次可以将一行都进行扫描到
 * 对于为什么 i < j：原因是因为 index1 < index2 使用双指针，i 和 j 分别对应着 index1 和 index2
 * 对于题解中的图，表示着，循环遍历的 i j 对应的单元格
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> result;
        while (i < j)
        {
            if (numbers[i] + numbers[j] > target)
            {
                j --;
            }
            if (numbers[i] + numbers[j] < target)
            {
                i++;
            }
            if (numbers[i] + numbers[j] == target)
            {
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
            }
        }
        return result;
    }
};
/*
 * 官方题解还给了一个方法，固定第一个数，对于第二个数使用二分查找进行，快速查找，
 * 从而减低时间效率。
*/
class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};

// @lc code=end

