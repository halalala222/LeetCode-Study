#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
/**
 * 第一反应是递归，感觉这题应该就是用递归
 * 但是有点问题，不过思路应该是没错，但是看了下题解，题解比我想的更好以及给更加简单
*/
// @lc code=start
void Color(vector<vector<int>> image,int targetValue,int sr,int sc,int iLength,int jLength,int value){
    image[sr][sc] = image[sr][sc] == value ? targetValue : image[sr][sc];
    if (sr - 1 >= 0)
    {
        Color(image,targetValue,sr - 1,sc,iLength,jLength,value);
    }
    if (sc - 1 >= 0)
    {
        Color(image,targetValue,sr,sc - 1,iLength,jLength,value);
    }
    if (sr + 1 < iLength)
    {
        Color(image,targetValue,sr + 1,sc,iLength,jLength,value);
    }
    if (sc + 1 < jLength)
    {
        Color(image,targetValue,sr,sc + 1,iLength,jLength,value);
    }
}
class MySolution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iLength = image[0].size();
        int jLength = image.size();
        Color(image,color,sr,sc,iLength,jLength,image[sr][sc]);
        return image;
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        const int h = image.size(), w = image[0].size();
        
        std::function<void(int, int, int)> dfs;
        
        //这玩意是 lambda 表达式？
        dfs = [&](int r, int c, int srcColor) -> void{
          
            if( (r < 0 ) || ( r >=  h ) || ( c < 0) || ( c >= w) 
                         || ( image[r][c] == newColor )          
                         || ( image[r][c] != srcColor )            ){

                // Reject for invalid coordination, repeated traversal, or different color      
                return;
            }


            // update color
            image[r][c] = newColor;


            // DFS to 4-connected neighbors
            dfs( r-1, c, srcColor );
            dfs( r+1, c, srcColor );
            dfs( r, c-1, srcColor );
            dfs( r, c+1, srcColor );

            return;
        };
        // ==================================
        
        dfs( sr, sc, image[sr][sc] );
        
        return image;
        
    }
};
// @lc code=end

