#include <string>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */

// @lc code=start
/**
 * 5525
 * 2555 b
 * 2454 a
 * 2353 a
 * 5323 b
 * 5222 a
 * 5121 a
 * 2151 b
 * 2050 a
 * 5020 b
 * 5929 a
 * 5828 a
 * 5727 a
 * 5626 a
 * 5525 a
 *
 * 74
 * 47
 * 42
 * 24
 * 29
 * 24
 * 29
 * 24
 *
 * 0011
 * 0516
 * 0011
 *
 *
 * 通过案例可以知道如果每次取 a b 操作中最小的数，就会进入到一个循环中，
 * 答案会在循环中出现
 */
/**
 * 题解使用暴力的 BFS 进行暴力模拟，看起来感觉是可以。
 */
class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        unordered_set<string> appearedString;
        queue<string> allString;
        string result = s;
        allString.push(s);
        while (!allString.empty())
        {
            string currentString = allString.front();
            // 每次拿到的进行比较即可
            result = min(result, currentString);
            allString.pop();
            string operateorA = currentString, operateorB;
            int size = currentString.size();
            for (int i = 1; i < size; i += 2)
            {
                operateorA.at(i) = (operateorA.at(i) + a - '0') % 10 + '0';
            }
            // 学到了使用 substring 进行轮转
            operateorB = currentString.substr(b, size) + currentString.substr(0, b);
            // if (!appearedString.count(operateorA))
            // {
            //     appearedString.insert(operateorA);
            //     allString.push(operateorA);
            // }
            // if (!appearedString.count(operateorB))
            // {
            //     appearedString.insert(operateorB);
            //     allString.push(operateorB);
            // }
            // 高雅的语法，学习一下。
            for (auto &t : {operateorA, operateorB})
            {
                if (!appearedString.count(t))
                {
                    appearedString.insert(t);
                    allString.emplace(t);
                }
            }
        }
        return result;
    }
};

/**
 * 这个枚举真的吊，累加最多10次，这个我还在想是否有一个一定固定的，
 * 但是其实好像如果是取最大的保证每个情况都可以枚举完，其中有多的循环次数可以忍受
*/
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n; ++i) {
            s = s.substr(n - b) + s.substr(0, n - b);
            for (int j = 0; j < 10; ++j) {
                for (int k = 1; k < n; k += 2) {
                    s[k] = (s[k] - '0' + a) % 10 + '0';
                }
                if (b & 1) {
                    for (int p = 0; p < 10; ++p) {
                        for (int k = 0; k < n; k += 2) {
                            s[k] = (s[k] - '0' + a) % 10 + '0';
                        }
                        ans = min(ans, s);
                    }
                } else {
                    ans = min(ans, s);
                }
            }
        }
        return ans;
    }
};

// @lc code=end
