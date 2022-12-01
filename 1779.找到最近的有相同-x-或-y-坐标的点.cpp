#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minResult = INT_MAX; 
        int size = points.size();
        int minIndex = size;
        for (int i = 0; i < size; i++)
        {
            vector<int> position = points.at(i);
            if (position.at(0) == x || position.at(1) == y)
            {
                int tempMin = min((abs(position.at(0) - x) + abs(position.at(1) - y)),minResult);
                // 可以优化的就是，当从小到大遍历的话，可以不用对相等的返回最下标做处理，因为此时的最小下标就是当前小标，所以只要
                // 对小于进行处理即可
                if (tempMin == minResult)
                {
                    minIndex = min(minIndex,i);
                }
                if (tempMin < minResult)
                {
                    minIndex = i;
                    minResult = tempMin;
                }
                
            }
        }
        return minIndex == size ? -1 : minIndex;
    }
};
// @lc code=end

