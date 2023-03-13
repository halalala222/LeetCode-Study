#include <vector>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> numsCount1;
        unordered_set<int> numsCount2;
        for (int num : nums1)
        {
            numsCount1.insert(num);
        }
        for (int num : nums2)
        {
            numsCount2.insert(num);
        }
        vector<int> result;
        for (auto it = numsCount1.cbegin(); it != numsCount1.cend(); it++)
        {
            if (numsCount2.find(*it) != numsCount2.end())
            {
                result.push_back(*it);
            }
        }
        return result;
    }
};

/**
 * 做法比我更加优雅
 * 1. 通过存储一个 set ，后续直接遍历数组，可以知道是否是两个数组中都出现过的数字
 * 2. 通过 set 存储结果之后，直接使用迭代器转换为 vector 都没有见过
 */
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
/**
 * 那有同学可能问了，遇到哈希问题我直接都用set不就得了，用什么数组啊。
 * 直接使用set 不仅占用空间比数组大，而且速度要比数组慢，set把数值映射到key上都要做hash计算的。
 * 不要小瞧 这个耗时，在数据量大的情况，差距是很明显的。
*/
// @lc code=end
