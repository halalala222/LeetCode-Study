#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stdio.h>
#include <memory.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         unordered_set<char> colNums;
//         unordered_set<char> rowNums;
//         unordered_set<char> min1;
//         unordered_set<char> min2;
//         unordered_set<char> min3;
//         unordered_set<char> min4;
//         unordered_set<char> min5;
//         unordered_set<char> min6;
//         unordered_set<char> min7;
//         unordered_set<char> min8;
//         unordered_set<char> min9;
//         int colToalNum;
//         int rowToalNum;
//         int min1ToalNum;
//         int min2ToalNum;
//         int min3ToalNum;
//         int min4ToalNum;
//         int min5ToalNum;
//         int min6ToalNum;
//         int min7ToalNum;
//         int min8ToalNum;
//         int min9ToalNum;
//         //简单的想法，进行暴力
//         // // col
//         // for (int i = 0; i < 9; i++)
//         // {
//         //     for (int j = 0; j < 9; i++)
//         //     {
//         //         if (board.at(i).at(j) != '.') 
//         //         {
//         //             toalNum++;
//         //             colNums.insert(board.at(i).at(j));
//         //         }   
//         //     }
//         //     if (colNums.size() != toalNum) return false;
//         //     colNums.clear();
//         // }
//         // // row
//         // for (int i = 0; i < 9; i++)
//         // {
//         //     for (int j = 0; j < 9; i++)
//         //     {
//         //         if (board.at(j).at(i) != '.') 
//         //         {
//         //             colNums.insert(board.at(i).at(j));
//         //             toalNum++;
//         //         }   
//         //     }
//         //     if (colNums.size() != toalNum) return false;
//         //     colNums.clear();
//         // }
//         // mixin
//         for (int i = 0; i < 9; i++)
//         {
//             printf("------------------------%d\n",i);
//             for (int j = 0; j < 9; j++)
//             {
//                 printf("------------------------%d\n",j);
//                 if (board.at(i).at(j) != '.') 
//                 {
//                     printf("1\n");
//                     colNums.insert(board.at(i).at(j));
//                     colToalNum += 1;
//                 }
//                 if (board.at(j).at(i) != '.') 
//                 {
//                     printf("2\n");
//                     colNums.insert(board.at(j).at(i));
//                     rowToalNum += 1;
//                 }
//                 if (i < 3 && j < 3 && board.at(i).at(j) != '.')
//                 {
//                     printf("3\n");
//                     min1.insert(board.at(j).at(i));
//                     min1ToalNum++;
//                 }
//                 if (i < 3 && 2 < j < 6 && board.at(i).at(j) != '.')
//                 {
//                     printf("4\n");
//                     min2.insert(board.at(j).at(i));
//                     min2ToalNum++;
//                 }
//                 if (i < 3 && 5 < j < 9 && board.at(i).at(j) != '.')
//                 {
//                     printf("5\n");
//                     min3.insert(board.at(j).at(i));
//                     min3ToalNum++;
//                 }
//                 if (2 < i < 6 && j < 3 && board.at(i).at(j) != '.')
//                 {
//                     printf("6\n");
//                     min4.insert(board.at(j).at(i));
//                     min4ToalNum++;
//                 }
//                 if (2 < i < 6 && 2 < j < 6 && board.at(i).at(j) != '.')
//                 {
//                     printf("7\n");
//                     min5.insert(board.at(j).at(i));
//                     min5ToalNum++;
//                 }
//                 if (2 < i < 6 && 5 < j < 9 && board.at(i).at(j) != '.')
//                 {
//                     printf("8\n");
//                     min6.insert(board.at(j).at(i));
//                     min6ToalNum++;
//                 } 
//                 if (5 < i < 9 && 0 < j < 3 && board.at(i).at(j) != '.')
//                 {
//                     printf("9\n");
//                     min7.insert(board.at(j).at(i));
//                     min7ToalNum++;
//                 }
//                 if (5 < i < 9 && 2 < j < 6 && board.at(i).at(j) != '.')
//                 {
//                     printf("10\n");
//                     min8.insert(board.at(j).at(i));
//                     min8ToalNum++;
//                 }
//                 if (5 < i < 9 && 5 < j < 9 && board.at(i).at(j) != '.')
//                 {
//                     printf("11\n");
//                     min9.insert(board.at(j).at(i));
//                     min9ToalNum++;
//                 }
//                 if (rowNums.size() != rowToalNum) return false;
//                 rowNums.clear();
//             }
//             if (colNums.size() != colToalNum) return false;
        
//             colNums.clear();
//         }
//             if (min1.size() != min1ToalNum) return false;
//             if (min2.size() != min2ToalNum) return false;
//             if (min3.size() != min3ToalNum) return false;
//             if (min4.size() != min4ToalNum) return false;
//             if (min5.size() != min5ToalNum) return false;
//             if (min6.size() != min6ToalNum) return false;
//             if (min7.size() != min7ToalNum) return false;
//             if (min8.size() != min8ToalNum) return false;
//             if (min9.size() != min9ToalNum) return false;
//         return true;
//     }
// };

/**
 * 看了下题解，感觉题解说得其实很有道理 ，另外起一个数组来标记出现的次数
 * 如果出现的次数 > 1 的话，表示有重复的，如果没有的话表示没有，这种通过另外数组
 * 标记出现的次数，但是想着使用 set，导致需要多个 set，而不如直接用数组将所有的集合在一起
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // colNums[0][1] 表示第一行数字2出现的次数
        int colNums[9][9];
        // vector<int> singleRow(9,0);
        // vector<vector<int>> colNums(9,singleRow);
        // rowNums[0][1] 表示第一行数字2出现的次数
        int rowNums[9][9];
        // vector<vector<int>> rowNums(9,singleRow);
        // subboxes[0][0][1] 表示分成的9块中第一行第一个小块中数字2出现的次数
        // vector<vector<int>> singleSub(3,singleRow);
        // vector<vector<vector<int>>> subboxes(3,singleSub);
        int subboxes[3][3][9];
        //这样的子 循环的时候 i/3 j/3 就表示其所在的小九宫格中
        memset(rowNums,0,sizeof(rowNums));
        memset(colNums,0,sizeof(colNums));
        memset(subboxes,0,sizeof(subboxes));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board.at(i).at(j) != '.')
                {
                    //这样子 index 会越界
                    // int index = board.at(i).at(j) - 1;
                    int index = board.at(i).at(j) - '0' -1;
                    colNums[i][index]++;
                    rowNums[j][index]++;
                    subboxes[i / 3][j/3][index]++;
                    if (colNums[i][index] > 1 || rowNums[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

