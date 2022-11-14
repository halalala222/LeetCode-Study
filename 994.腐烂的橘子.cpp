#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
/**
 * 我的想法是先BFS，进行层数的增加，
 * 然后遍历层数，如果还有橙子存活的话，就返回 -1，没有的话，就返回最大层数即可
*/

/**
 * 看了眼题解，发现想法和我差不多，但是他是先将橘子的数量统计出来之后再进行 -- 
 * 这样子能够更快更方便，不用使用循环进行遍历找出是否还有新鲜橘子
 * 最大数也不用通过循环遍历找到其中的最大值，只要在每次把最大值赋值为当前层数即可
 * 之后通过判断是否还有新鲜橘子，返回 -1 还是层数
*/
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid.at(0).size();
        int maxInt = 0;
        vector<int> rowResult(w,0);
        vector<vector<int>> result(h,rowResult);
        queue<pair<int,int>> q;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid.at(i).at(j) == 2)
                {
                    q.emplace(i,j);
                }
            }
        }
        while (!q.empty())
        {
            auto [nowI,nowJ] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextI = nowI + dirs[i][0];
                int nextJ = nowJ + dirs[i][1];
                if (nextI >= 0 && nextI < h && nextJ >= 0 && nextJ < w && (grid[nextI][nextJ] == 1))
                {
                    result[nextI][nextJ] = result[nowI][nowJ] + 1;
                    grid[nextI][nextJ] = 2;
                    q.emplace(nextI,nextJ);
                }
            }
        }
        for (int i = 0; i < h; i++)
        {
             for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
                if (grid[i][j] == 2)
                {
                    maxInt = max(result[i][j],maxInt);
                }
            }
        }
        return maxInt;
    }
};
// @lc code=end

