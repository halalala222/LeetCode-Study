/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            result.push_back(sum);
        }
        return result;
    }
};
// @lc code=end

/*
    题解
    1.在原有数据上进行操作节省内存
*/
class BestSolution {
public:
	vector<int> runningSum(vector<int>& nums) {

		for(int i=1;i<nums.size();i++) nums[i] += nums[i-1];
		return nums;

	}
};
