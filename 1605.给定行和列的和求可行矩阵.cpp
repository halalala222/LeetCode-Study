#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

/**
 * 没有一点思路，但是有感觉不难这个题
 */
// @lc code=start
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int row = rowSum.size(), col = colSum.size();
        vector<int> rowResult(col, 0);
        vector<vector<int>> result(row, rowResult);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i] -= result[i][j];
                colSum[j] -= result[i][j];
            }
            
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = 0, j = 0; i < m && j < n; ) {
            int rs = rowSum[i], cs = colSum[j];
            if (rs < cs) { // 去掉第 i 行，往下走
                colSum[j] -= rs;
                mat[i++][j] = rs;
            } else { // 去掉第 j 列，往右走
                rowSum[i] -= cs;
                mat[i][j++] = cs;
            }
        }
        return mat;
    }
};  
// @lc code=end
