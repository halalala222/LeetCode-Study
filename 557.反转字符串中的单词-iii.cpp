#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
 

/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
/*
 * 一种在 golang 中非常好实现的方法，但是 C++ 竟然没有 split 函数
 * 想法是将 str 根据 ' ' 进行分割，分割后使用循环，对单个进行转置
 * 写完之后，发现时间复杂度和空间复杂度非常高，有点低效
*/
// @lc code=start
vector<string> split(const string& str) {
    istringstream ss(str);
    vector<string> words;
    string word;
    while(ss >> word) {
        words.push_back(word);
    }
    return words;
}

class Solution {
public:
    string reverseWords(string s) {
        string strResult;
        auto result = split(s);
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << endl;
            for (int left = 0,right = result[i].length() - 1; left <= right;)
            {
                swap(result[i][left++],result[i][right--]);
            }
            if (i != result.size() - 1)
            {
                result[i].push_back(' ');
            }            
            cout << result[i] << endl;
            strResult.append(result[i]);
        }
        return strResult;
    }
};
// @lc code=end
/*
 * 使用的是 reverse 和双指针，j 用来探是否为空格，用来判断是否是一个单词
 * 最后一行 reverse(s.begin() + i, s.end()); 表示的是最后一个单词无法被转置
 * 根据循环条件来看
*/
class StandardSolution {
public:
    string reverseWords(string& s) {
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};