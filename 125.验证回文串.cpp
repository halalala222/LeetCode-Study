#include <string>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            // isalnum 这个又是什么高级的方法
            if (isalnum(ch)) {
                // 还有 tolower 方法
                sgood += tolower(ch);
            }
        }
        //这个是什么用法没见过
        string sgood_rev(sgood.rbegin(), sgood.rend());
        cout << sgood <<endl;
        return sgood == sgood_rev;
    }
};
/**
 * 原地双指针
 * 
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};

// @lc code=end

