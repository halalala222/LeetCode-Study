/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
/*
 * 题目的考点在于观察能力，由于没有仔细观察到下一位如果是比当前位小的
 * 的时候，是可以使用减的在数值上并没用影响 
*/
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char,int> charMapInt;
        charMapInt['I'] = 1;
        charMapInt['V'] = 5;
        charMapInt['X'] = 10;
        charMapInt['L'] = 50;
        charMapInt['C'] = 100;
        charMapInt['D'] = 500;
        charMapInt['M'] = 1000;
        for (int i = 0; i < s.length(); i++){
            if (i < s.length() - 1 && charMapInt[s[i]] < charMapInt[s[i + 1]]){
                sum -= charMapInt[s[i]];
            }
            else {
                sum += charMapInt[s[i]];
            }
        }
        return sum;
    }
};

// @lc code=end
