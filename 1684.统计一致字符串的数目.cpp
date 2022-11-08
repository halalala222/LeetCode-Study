#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

/*
 * 简单粗暴的暴力解法
*/
// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> isRight;
        int count = 0;
        for (int i = 0; i < allowed.size(); i++)
        {
            if (!isRight[allowed[i]])
            {
                isRight[allowed[i]] = true;
            }
            
        }
        for (int i = 0; i < words.size(); i++)
        {
            bool isAllowed = true;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (!isRight[words[i][j]])
                {
                    isAllowed = false;
                    break;
                }
                
            }
            if (isAllowed)
            {
                count++;
            }
            
        }
        return count;
    }
};
// @lc code=end

