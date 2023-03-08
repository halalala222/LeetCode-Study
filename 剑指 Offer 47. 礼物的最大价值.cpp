class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        /**
        * 贪心失败，打算用动态规划
        **/
        // if(!grid.size())
        //     return 0;
        // int col = grid.size(),row = grid.at(0).size(),i = 0,j = 0,result = grid.at(0).at(0);
        // while(i < col && j < row)
        // {
        //     int nextColNum = 0,nextRowNum = 0;
        //     printf("i : %d,j : %d \n",i,j);
        //     if(i < col - 1)
        //         nextColNum = grid.at(i + 1).at(j);
        //     if(j < row - 1 )
        //         nextRowNum = grid.at(i).at(j + 1);
        //     int maxNum = max(nextColNum,nextRowNum);
        //     printf("maxNum : %d\n",maxNum);
        //     maxNum == nextColNum ? i++ :j++;
        //     result += maxNum;
        // }
        // return result;
        // int col = grid.size();
        // if(!col)
        //     return 0;
        // int row = grid.at(0).size();
        // int size = row * col;
        // vector<int> dp;
        // int i = 0;
        // for(vector<int> colGrid : grid){
        //     for(int item : colGrid){
        //         dp.push_back(item);
        //     }
        // }
        // for(int i = 1;i < size;i++){
        //     if(i + row < size)
        //         dp[i] = max(dp[i + 1],dp[i + row]) + dp[i];
        // }
        // return dp[size -1];
        /**
        * 想错了 
        **/
        int col = grid.size(),row = grid.at(0).size();
        vector<int> colGrid(row,0);
        vector<vector<int>> dp(col,colGrid);
        dp.at(0).at(0) = grid.at(0).at(0);
        for(int i = 0;i < col;i++){
            for(int j = 0;j < row;j++){
                if(i > 0)
                    dp.at(i).at(j) = max(dp.at(i).at(j),dp.at(i - 1).at(j) + grid.at(i).at(j));
                if(j > 0)
                    dp.at(i).at(j) = max(dp.at(i).at(j),dp.at(i).at(j - 1) + grid.at(i).at(j));
            }
        }
        return dp.at(col - 1).at(row - 1);
    }
};