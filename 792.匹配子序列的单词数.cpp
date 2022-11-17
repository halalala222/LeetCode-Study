#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */
/**
 * 暴力解法，寻找是否是子序列使用的是循环 s ，判断 t 中 s[i] 出现的位置
 * 如果出现的 index 能够一直增加，则表示是字串，否则不是
*/
// @lc code=start
class Solution {
public: 
    bool isSubStr(string s,string t){
        int maxIndex = 0;
        if (s.length() > t.length())
        {
            return false;
        }
        if (s == t)
        {
            return true;
        }
        for (int i = 0; i < s.length(); i++)
        {
            int index;
            if (maxIndex != 0)
            {
                index = t.find(s[i],maxIndex+1);
            }
            else
            {
                index = t.find(s[i]);
            }
            if (index == 0 || index > maxIndex)
            {
                maxIndex = index;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int size = words.size();
        int result = 0;
        for (int i = 0; i < size; i++)
        {
            if(isSubStr(words[i],s)) result++;
        }
        return result;
    }
};
// @lc code=end

