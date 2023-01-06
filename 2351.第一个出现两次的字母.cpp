#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_map<char, int> count;
        char result;
        for (auto c : s)
        {
            count[c]++;
            if (count[c] > 1)
            {
                result = c;
                break;
            }
        }
        return result;
    }
};

/**
 * 使用 hashset 也是不错的，如果这个 set 中存在那么就直接返回
 */
class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_set<char> seen;
        for (char ch : s)
        {
            if (seen.count(ch))
            {
                return ch;
            }
            seen.insert(ch);
        }
        // impossible,but must return result
        return ' ';
    }
};

// @lc code=end
