/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        vector<char> leftLetter(s.length()) ;
        unordered_map<char,char> letterMapLetter = {
            {')','('},
            {'}','{'},
            {']','['},
        };
        int top = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (letterMapLetter.count(s[i]))
            {
                if (top == 0 || leftLetter[top -1] != letterMapLetter[s[i]])
                {
                    return false;
                }
                top--;
            }else
            {

                leftLetter[top] = s[i];
                top++;
            }
        }
        return top == 0;
    }
};
// @lc code=end

