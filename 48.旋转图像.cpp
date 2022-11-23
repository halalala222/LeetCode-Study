#include <vector>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

/**
 * 想到使用一个同样大小的数组，存储是否交换过，这样在对所有进行遍历的时候不用担心是否缺少或者重复遍历
 * 想错了这个东西不是交换，而是一个替换另外一个
 * 但是想不到什么好的办法，也不知道该如何循环
 * 感觉可能是使用递归
*/
/**
 *  看了下题解，使用翻转挺牛的 
 */ 
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        //水平旋转
        for (int i = 0; i < size / 2; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("i : %d,j : %d\n",i,j);
                int temp = matrix[i][j];
                matrix[i][j] = matrix[size - 1 - i][j];
                matrix[size - 1 - i][j] = temp; 
            }
        }
        //对角线旋转
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;   
            }
        }
    }
};
// @lc code=end

