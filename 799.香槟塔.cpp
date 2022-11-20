#include <stdio.h>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start
/**
 * 这个对题目的理解有问题
*/
class WrongSolution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int totalChampagne = 0;
        double result;
        for (int i = 1; i < query_row + 2; i++)
        {
            totalChampagne += i;
        }
        printf("%d\n",totalChampagne);
        if (poured <= totalChampagne - query_row - 1)
        {
            result = 0.0;
        }
        else if (poured >= totalChampagne)
        {
            result = 1.0;
        }
        else
        {
            printf("333333333333333333333333\n");
            int leftedPoured = poured - (totalChampagne - query_row - 1);
            printf("leftedPoured : %d\n",leftedPoured);
            int totalNum = query_row * 2;
            printf("totalNum : %d\n",totalNum);
            if (query_row == 1)
            {
                result = double(leftedPoured) / totalNum;
            }
            else
            {
                if (query_glass == 0 || query_glass == totalChampagne)
                {
                    result = double(leftedPoured) / totalNum;
                }
                else
                {
                    result = double(leftedPoured) / totalNum * 2;
                }
            }
        }   
        return result;
    }
};

/**
 * 有点懂题解的想法了，根据总流量，表示流经当前杯子是流量为多少，然后下一层就根据上一层的流量是多少来表示当前自己杯子的流量
 * 
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = {double(poured)};
        for (int i = 1; i <= query_row; i++)
        {
            //构建下一层
            vector<double> nextRow(i + 1,0.0);
            //遍历当前层的杯子，如果当前层杯子有流量＞1，即需要流到下一层
            for (int j = 0; j < row.size(); j++)
            {
                double now = row[j];
                if (row[j] > 1)
                {
                    nextRow[j] += (now - 1) / 2;
                    nextRow[j + 1] += (now - 1) / 2;
                }
            }
            row = nextRow;
        }
        //因为记录的是流量，则会大于 1 ，此时的体积为 1.0
        return min(1.0,row[query_glass]);
    }
};
// @lc code=end

