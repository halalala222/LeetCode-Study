#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

/**
 * 题解也用了俩个循环
 * 但是题解内存更优，因为是++和--一起用，如果其中有一个不为0，表示数量不同
 * 少一个 map 使用
*/
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int sSize = s.length();
        int tSize = t.length();
        unordered_map<char,int> sCount;
        unordered_map<char,int> tCount;
        if (tSize != sSize)
        {
            return false;
        }
        for (int i = 0; i < sSize; i++)
        {
            sCount[s.at(i)]++;
            tCount[t.at(i)]++;
        }
        for (int i = 0; i < sSize; i++)
        {
            if (sCount[s.at(i)] != tCount[s.at(i)]) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};
// @lc code=end

