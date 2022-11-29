#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */
/**
 * 下面的算法失败了
 * "10010100"
 * 5
 * 3
 * 
class Solution {
public:
    int minOperations(string s) {
        int size = s.size(),result = 0;
        for (int i = 0; i + 1 < size; i++)
        {
            if (s.at(i) == s.at(i + 1))
            {
                s.at(i + 1) = s.at(i) == '1' ? '0' : '1';
                result++;
            }
        }
        return result;
    }
};
*/
/**
 * 重新想了一下，只有俩种可能，
 * 第一种：01010101.....01
 * 第二种：10101010.....10
 * 即要将字符串变成如上俩中形式，只要获得其中俩中形式中最小值即可
 * 89/89 cases passed (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 49.07 % of cpp submissions (6.8 MB)
 * hhhhhh
 * 但是题解比我的更好，因为这俩中需要的操作都是相反的，所以可以通过一个操作数推断出另外的操作数
 * 
*/
// @lc code=start
class Solution {
public:
    int minOperations(string s) {
        int size = s.size(),result1 = 0,result2 = 0;
        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 1)
            {
                s.at(i) == '0' ? result2++ : result1++;
            }
            else
            {
                s.at(i) == '0' ? result1++ : result2++;
            }
        }
        return min(result1,result2);
    }
};
class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != ('0' + i % 2)) {
                cnt++;
            }
        }
        return min(cnt, (int)s.size() - cnt);
    }
};
// @lc code=end

