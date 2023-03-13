#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        int size = words.size();
        /**
         * 想错了，感觉早上脑袋不清醒，没有好好看题，读不懂题目
         */
        // unordered_map<string, int> wordCount;
        // unordered_map<string, int> count;
        // vector<string> result;
        // int size = words.size();
        // for (auto word : words)
        // {
        //     for (auto c : word)
        //     {
        //         string s = "";
        //         s.push_back(c);
        //         if (!count[s])
        //             wordCount[s] += 1;
        //     }
        // }
        // for (auto &word : wordCount)
        // {
        //     if (word.second == size)
        //     {
        //         result.push_back(word.first);
        //     }
        // }
        // return result;
        vector<int> hash(26, INT_MAX);
        for (int i = 0; i < size; i++)
        {
            vector<int> tmepHash(26, 0);
            for (auto ch : words.at(i))
            {
                tmepHash[ch - 'a']++;
            }
            for (int j = 0; j < 26; j++)
            {
                hash[j] = min(hash[j], tmepHash[j]);
            }
        }
        vector<string> result;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < hash.at(i); j++)
            {
                string s = "";
                s.push_back(i + 'a');
                result.push_back(s);
            }
        }
        return result;
    }
};
// @lc code=end
