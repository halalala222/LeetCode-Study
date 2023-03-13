#include <vector>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */

// @lc code=start
class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int result = 0;
        for (int opponentEnergy : energy)
        {
            result += opponentEnergy;
        }
        // result += 1 - initialEnergy;
        /**
         * 如果所有的精力值比初始精力值小的话，不需要训练
        */
        result = result < initialEnergy ? 0 : result + 1 - initialEnergy;
        printf("result : %d\n", result);
        for (int opponentExperience : experience)
        {
            printf("initialExperience : %d,opponetExperience : %d\n", initialExperience, opponentExperience);
            if (initialExperience <= opponentExperience)
            {
                printf("1\n");
                result += (opponentExperience - initialExperience + 1);
                initialExperience = opponentExperience + 1;
            }
            // else
            // {
            //     printf("2\n");
            //     initialExperience += opponentExperience;
            // }
            initialExperience += opponentExperience;
            printf("result : %d\n", result);
        }
        return result;
    }
};
// @lc code=end
