#include<vector>
#include<algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result;
        for (int i = 1; i < n - 1; i++)
        {
            vector<int> row;
            for (int j = 1; j < n - 1; j++)
            {
                int n1 = grid.at(i - 1).at(j - 1);
                int n2 = grid.at(i).at(j - 1);
                int n3 = grid.at(i + 1).at(j - 1);
                int n4 = grid.at(i - 1).at(j);
                int n5 = grid.at(i).at(j);
                int n6 = grid.at(i + 1).at(j);
                int n7 = grid.at(i - 1).at(j + 1);
                int n8 = grid.at(i).at(j + 1);
                int n9 = grid.at(i + 1).at(j + 1);
                row.push_back(max(max(max(max(n1,n2),max(n3,n4)),max(max(n5,n6),max(n7,n8))),n9));    
            }
            result.push_back(row);
        }
        return result;
    }
};
// @lc code=end

