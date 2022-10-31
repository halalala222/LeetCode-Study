/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int> maxLengthNums;
        vector<int> minLengthNums;
        unordered_map<int,bool> isRange;
        int length = min(nums1.size(),nums2.size());
        maxLengthNums = length == nums1.size() ? nums2 : nums1;
        minLengthNums = length == nums1.size() ? nums1 : nums2;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < maxLengthNums.size(); j++)
            {                   
                if (maxLengthNums[j] == minLengthNums[i] && !isRange[j])
                {
                    isRange[j] = true;
                    result.push_back(maxLengthNums[j]);
                    break;
                }
            }
        }
        return result;
    }
};
/*
 * 将其中任意一个数组中的所有数据出现的次数记录下来，
 * 后续循环之后使用 a-- 后置减减的特性进行操作，如果在前数组中该数据还存在则 push 负责不 push
 * 和我的想法目的一样但是操作不同
*/
vector<int> Standardintersect(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> ctr;
    for (int i : a)
        ctr[i]++;
    vector<int> out;
    for (int i : b)
        if (ctr[i]-- > 0)
            out.push_back(i);
    return out;
}
// @lc code=end

