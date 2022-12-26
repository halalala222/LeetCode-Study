#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1754 lang=cpp
 *
 * [1754] 构造字典序最大的合并字符串
 */
/**
 * word1 = "abcabc", word2 = "abdcaba"
 * "abdcabcabcaba"
 *
 * 实例二中提示需要注意如果俩个相等的话，需要进行处理
 */
// // @lc code=start
// class Solution
// {
// public:
//     string largestMerge(string word1, string word2)
//     {
//         string result = "";
//         int size1 = word1.size(), size2 = word2.size(), left1 = 0, left2 = 0;
//         while (left1 < size1 && left2 < size2)
//         {
//             printf("2222222222222222222\n");
//             if (word1.at(left1) == word2.at(left2))
//             {
//                 int i = left1 + 1, j = left2 + 1;
//                 string temp = "";
//                 temp.push_back(word1.at(left1));
//                 for (; i < size1 && j < size2; i++, j++)
//                 {
//                     printf("left1 : %d,left2 : %d\n", left1, left1);
//                     printf("word1 : %c,word2 : %c\n", word1.at(i), word2.at(j));
//                     printf("33333333333333333333333\n");
//                     if (word1.at(i) == word2.at(j))
//                     {
//                         temp.push_back(word1.at(i));
//                         printf("char : %c\n", word1.at(i));
//                         continue;
//                     }
//                     else
//                     {
//                         printf("i : %d,j : %d\n", i, j);
//                         if (word1.at(i) > word2.at(j))
//                         {
//                             left1 = i;
//                         }
//                         else
//                         {
//                             left2 = j;
//                         }
//                         result.append(temp);
//                         break;
//                     }
//                 }
//                 if (i == size1 || j == size2)
//                 {
//                     i == size1 ? left1 = size1 : left2 = size2;
//                     result.append(temp);
//                 }
//             }
//             else
//             {
//                 if (word1.at(left1) > word2.at(left2))
//                 {
//                     result.push_back(word1.at(left1));
//                     left1++;
//                 }
//                 else
//                 {
//                     result.push_back(word2.at(left2));
//                     left2++;
//                 }
//             }
//         }
//         if (left1 == size1)
//         {
//             for (int i = left2; i < size2; i++)
//             {
//                 result.push_back(word2.at(i));
//             }
//         }
//         else
//         {
//             for (int i = left1; i < size1; i++)
//             {
//                 result.push_back(word1.at(i));
//             }
//         }
//         return result;
//     }
// };
/**
 * wc，看了下题解的第一个方法，是我没有想到的，不用自己进行推断，直接使用提供的字符串字典比较就好了
 * 然后进行移动位置，选择对应字典最大的字符串中的首字母，因为如果是有相同的话，提供的字符串比较也会提供出一个值，根据这个值
 * 取得其首字母
*/
class Solution {
public:
    string largestMerge(string w1, string w2) {
        string ans;
        while (w1.length() || w2.length()) {
            string& w = w1 > w2 ? w1 : w2;
            ans += w[0];
            w = w.substr(1);
        }
        return ans;
    }
};
/**
 * 另外的一个方法，到时候再说吧
*/
// @lc code=end
