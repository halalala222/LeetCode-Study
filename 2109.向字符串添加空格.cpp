#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2109 lang=cpp
 *
 * [2109] 向字符串添加空格
 */

/**
 * 超时,md
*/
// @lc code=start
class MySolution1 {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_map<int,bool> isSpace;
        int sLength = s.size();
        int i = 0;
        string result;
        for (int i = 0; i < spaces.size(); i++)
        {
            isSpace[spaces.at(i)] = true;
        }
        while (i < sLength)
        {
            if (isSpace[i])
            {
                result.push_back(' ');
            }
            else
            {
                result.push_back(s[i]);
                i++;
            }
        }
        return result;
    }
};
/**
 * 55的时候又超时了,md，变成单循环也超时了，看题解得了
*/
class MySolution2 {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int size = s.size();
        int count = 0;
        for (int i = 0; i < spaces.size(); i++)
        {
            if (!spaces.at(i))
            {
                s = " " + s;
            }
            else
            {
                s = s.substr(0,spaces.at(i)+count) + " " + s.substr(spaces.at(i)+count);
            }
            count++;
        }
        return s;
    }
};

/**
 * 看了下题解，感觉题解是我的一个想法的升级版，他是使用双指针，将我的时间复杂度进行减少了
*/
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int pre = 0;
        string ans;
        //ans.reserve() 应该就是预先分配一定量的内存
        ans.reserve(n + spaces.size());
        for (int i = 0; i < n; i++)
        {
            printf("%d\n",i);
            //这里需要限制 pre < spaces.size() 因为当 pre 到最后一个的时候 pre++ 仍然还是会进入这个 if 条件判断中，
            //所以会导致越界
            if (pre < spaces.size() && i == spaces[pre])
            {
                ans.push_back(' ');
                printf("%d\n",pre);
                pre++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
// @lc code=end

