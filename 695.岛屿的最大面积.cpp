#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
/**
 * 需要将已经计算的过元素就不进行再次递归了，进行一个标记
 * 看了题解的标记，把值设置为 0，因为 0 在限制条件的地方是不会被递归的。节省一个内存空间
 * vector<vector> 使用的时候需要注意，进行一个初始化吧
*/
// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxResult = 0;
        int w = grid.at(0).size();
        int h = grid.size();
        vector<int> row(w,0);
        vector<vector<int>> mark(h,row);
        std::function<int(int, int)> dfs;
        dfs = [&](int r, int c) -> int{
            if ((r < 0) || (r >= h) || (c < 0) || (c >= w) || grid.at(r).at(c) == 0 || mark[r][c] == 1)
            {
                return 0;
            }
            mark[r][c] = 1;
            return dfs(r+1,c) + dfs(r,c+1) + dfs(r-1,c) + dfs(r,c-1) + 1;            
        };
        
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j])
                {
                    maxResult = max(dfs(i,j),maxResult);
                }
                
            }
        }
        return maxResult;
    }
};
/*
 * 有点没懂题解中的深度优先和广度优先的区别。。。。队列和堆栈的区别
 * 真有区别的就是访问元素的顺序，深度优先是使用栈，会让这一块的遍历完才进行，另外一个块。
 * 使用队列的话，会将每一块按照顺序遍历一块中的某阶段元素后遍历另外一块某阶段的元素
*/
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid {{0,0,0,0,0,0,0,0}};
    Solution *s = new Solution;
    s->maxAreaOfIsland(grid);
    return 0;
}
