#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
/**
 * 出现的问题：
 * 1.每次循环后未将 unordered_map 进行清空
 * 解决方法：使用 isExit.clear() 清空 map 中的键值对
 * 2.当 " " 会导致出现问题，未进入循环，直接 return 0，但是这种情况需要 return 1
 * 解决方法：进行判断 length <= 1 的时候直接 return length
*/
/**
 * 暴力循环,确实低效
*/
/**
 * Your runtime beats 5.02 % of cpp submissions
 * Your memory usage beats 5.01 % of cpp submissions (158.6 MB)
*/
// @lc code=start
class MySolution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        int maxSubStrlength = 0;
        unordered_map<char,bool> isExit;
        if (length <= 1)
        {
            return length;
        }
        
        for (int i = 0; i < length -1; i++)
        {
            string subStr = "";
            int subStrLength = 0;
            for (int j = i; j < length; j++)
            {
                if (!isExit[s[j]])
                {
                    subStrLength++;
                    subStr.push_back(s[j]);
                    isExit[s[j]] = true;
                }
                else
                {
                    break;
                }
            }
            printf("subStrlength : %d",subStrLength);
            isExit.clear();
            maxSubStrlength = maxSubStrlength > subStrLength ? maxSubStrlength : subStrLength;
        }
        return maxSubStrlength;
    }
};
/**
 * 题解的方法名字叫做：滑动窗口
 * 有点懂这个想法了，在上一次遍历中，将左边界左移，但是右边界不移动的话，此范围内一定是无重复的
 * 此时，再将右边界不断的右移扩展右边界，将边界扩大，直到出现重复的元素。而且此时维护已出现元素
 * 不需要进行清空，只需要一直维护即可
 * 刚开始的左右边界位置也很🐂
 * 左边界的初始位置为 0 ，右边界的初始位置为 -1,表示并未开始移动右边界，即左右边界内的元素个数为0；
 * 当左右边界相等时，表示此中只有一个元素。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int right = -1;
        int ans = 0;
        unordered_set<char> isExit;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                // i != 0 表示左边界已经移动了，此时需要将左边界上一个位置的元素从已出现的 set 中删除
                isExit.erase(s[i - 1]);
            }
            // right + 1 < n，表示，右边界移动到下一个位置
            while (right + 1 < n && !isExit.count(s[right + 1]))
            {
                isExit.insert(s[right + 1]);
                right++;
            }
            // right - i + 1 未当前左右边界内的元素个数
            ans = max(ans,right - i + 1);
        }
        return ans;
    }
};
// @lc code=end

