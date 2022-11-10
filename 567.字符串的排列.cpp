#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 * "adc"
 * "dcda" 会出现问题，
 * 所以还是得使用滑动窗口
 */

// @lc code=start
// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int minIndex = 1e6;
//         int n1 = s1.length();
//         int n2 = s2.length();
//         unordered_set<char> isRightChar;
//         unordered_set<char> appearedChar;
//         for (int i = 0; i < n1; i++)
//         {
//             isRightChar.insert(s1[i]);
//             int charIndex = s2.find_first_of(s1[i]);
//             if (charIndex != string::npos)
//             {
//                 minIndex = min(minIndex,charIndex);
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         for (int j = minIndex; j < minIndex + n1  ; j++)
//         {
//             printf("j : %d\n",j);
//             printf("isRightChar : %d\n",isRightChar.count(s2[j]));
//             printf("appearedChar : %d\n",!appearedChar.count(s2[j]));
//             if (isRightChar.count(s2[j]) && !appearedChar.count(s2[j]))
//             {
//                 appearedChar.insert(s2[j]);
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
/**
 * "abcdxabcde"
 * "abcdeabcdx"
 * 出现得问题，因为由于没有考虑到是出现次数，所有判断条件需要改变，改成是否还能出现。即只判断了是否出现
 * 使用 map 会出现问题，导致比如说都是符合得时候，无法将数据重新复原
 * 看了题解，感觉这版改成使用 vector 应该能行，但是有点过于复杂，条件判断上
*/
// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int minIndex = 1e6;
//         int n1 = s1.length();
//         int n2 = s2.length();
//         int count = 0;
//         unordered_set<char> isRightChar;
//         unordered_map<char,int> appearedChar;
//         for (int i = 0; i < n1; i++)
//         {
//             isRightChar.insert(s1[i]);
//             appearedChar[s1[i]] +=1 ;
//             int charIndex = s2.find_first_of(s1[i]);
//             if (charIndex != string::npos)
//             {
//                 minIndex = min(minIndex,charIndex);
//             }
//         }
//         int j = minIndex - 1;
//         int i = minIndex;
//         printf("%d\n",i);
//         for (; i < n2; i++)
//         {
//             if (i != minIndex)
//             {
//                 appearedChar.erase(s2[i - 1]);
//             }
//             while (j + 1 < n2)
//             {
//                 printf("j : %d\n",j);
//                 printf("i : %d\n",i);
//                 printf("isRightChar : %d\n",isRightChar.count(s2[j + 1]));
//                 printf("appearedChar : %d\n",appearedChar.count(s2[j + 1]));
                
//                 if (appearedChar.count(s2[j + 1]) > 0 && isRightChar.count(s2[j + 1]))
//                 {
//                     printf("YES\n");
//                     appearedChar[s2[j + 1]]--;
//                     j++;
//                 }
//                 else
//                 {
//                     break;
//                 }
                
//             }
//             count = max(count,j - i + 1);
//             printf("count : %d\n",count);
//         }
//         printf("final j : %d\n",j);
//         printf("final i : %d\n",i);
//         return count == n1 ? true : false;
//     }
// };

/**
 * 还是看看高雅得题解吧
*/

/**
 * 使用 vector 将 s2 中出现得次数存储起来，将 s1 中，要出现的次数存储起来。
 * 因为窗口的长度是一样的，所以使用长度一定的滑动窗口
*/
class StandardSolution1 {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = n; i < m; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
};

/**
 * 复杂想法的题解，有点难理解这个题解，以后再来理解
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i) {
            --cnt[s1[i] - 'a'];
        }
        int left = 0;
        for (int right = 0; right < m; ++right) {
            int x = s2[right] - 'a';
            ++cnt[x];
            while (cnt[x] > 0) {
                --cnt[s2[left] - 'a'];
                ++left;
            }
            if (right - left + 1 == n) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

