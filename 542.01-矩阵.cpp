#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
/**
 * 又递归次数超过了,服了,md
*/
class MySolution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int h = mat.size();
        int w = mat.at(0).size();
        vector<int> rowResult(w,0);
        vector<vector<int>> result(h,rowResult);
        vector<vector<int>> zero(h,rowResult);
        vector<vector<int>> mark  = zero;
        std::function<int(int, int)> dfs;
        dfs = [&](int r, int c) -> int{
            if ((r < 0) || (r >= h) || (c < 0) || (c >= w) || mark.at(r).at(c) == 1)
            {
                return 1e5;
            }
            else if (mat.at(r).at(c) == 0)
            {
                mark.at(r).at(c) = 1;
                return 0;
            }
            else
            {
                mark[r][c] = 1;
                int button = dfs(r+1,c);
                int top = dfs(r - 1,c);
                int right = dfs(r,c+1);
                int left = dfs(r,c-1);
                int  minInt = min(min(min(button,top),left),right);
                printf("r : %d,c : %d,minInt : %d\n",r,c,minInt);
                return minInt + 1;
            }          
        };
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (mat.at(i).at(j))
                {
                    result.at(i).at(j) = dfs(i,j);
                    mark = zero;
                }
            }
        }
        return result;
    }
};

/**
 * 看了题解广度优先搜索之后，超级零的想法
 * 现在有点想明白了，
 * 广度优先所有相当于从某个节点上，遍历相邻的节点，遍历完相邻的节点之后，再遍历相邻节点的相邻节点
 * 超级零的意思相当于，超级零遍历其相邻节点为所有的 0 节点，此时将所有 0 节点，入队列
*/
/**
 * 使用队列，
*/
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int h = mat.size();
        int w = mat.at(0).size();
        vector<int> rowNodes(w,0);
        vector<vector<int>> mark(h,rowNodes);
        vector<vector<int>> result(h,rowNodes);
        //相当于超级零出队列后，将超级零相邻的元素（即，所有0值）如队列
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (mat.at(i).at(j) == 0)
                {
                    q.emplace(i,j);
                    mark.at(i).at(j) = 1;
                }
            }            
        }
        while (!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int nextI = i + dirs[d][0];
                int nextJ = j + dirs[d][1];
                if (nextI >= 0 && nextI < h && nextJ >= 0 && nextJ < w && !mark.at(nextI).at(nextJ))
                {
                    //result[nextI][nextJ] += 1;
                    //这里不能使用 += 1，而应该使用，当前遍历节点的层数为其上一个节点的距离+1以此来表示层数
                    result[nextI][nextJ] = result[i][j] + 1;
                    mark.at(nextI).at(nextJ) = 1;
                    q.emplace(nextI,nextJ);
                }
            }
        }
        return result;
    }
};
// @lc code=end

