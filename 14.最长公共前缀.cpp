/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
bool comp(string s1,string s2){
    return s1.length() < s2.length();
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(),comp);
        string lengthMinStr = strs[0];
        string resultStr = "";
        for (int i = 0; i < lengthMinStr.length(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != lengthMinStr[i])
                {
                    return resultStr;
                }
                
            }
            resultStr += lengthMinStr[i];
        }
        return resultStr;
    }
};
// @lc code=end
