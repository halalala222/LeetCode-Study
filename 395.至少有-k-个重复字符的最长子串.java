import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=395 lang=java
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
// class Solution {
//     public int longestSubstring(String s, int k) {
//         HashSet<Character> lessKChar = new HashSet<Character>();
//         int[] letterCount = new int[26];
//         int right = 0, res = 0, size = s.length();
//         for (int left = 0; left < size; left++) {
//             if (left != 0) {
//                 Character leftChar = s.charAt(left - 1);
//                 lessKChar.add(leftChar);
//                 letterCount[s.charAt(left - 1) - 'a']--;
//             } else {
//                 lessKChar.add(s.charAt(left));
//                 letterCount[s.charAt(left) - 'a'] = 1;
//             }
//             while (!lessKChar.isEmpty() && right + 1 < size) {
//                 if (letterCount[s.charAt(right + 1) - 'a'] < k - 1) {
//                     lessKChar.add(s.charAt(right + 1));
//                     right++;
//                 } else {
//                     lessKChar.remove(s.charAt(right + 1));
//                     letterCount[s.charAt(right - 1) - 'a']--;
//                     right++;
//                 }
//             }

//             res = Math.max(res, right - left - 1);
//         }
//         return res;
//     }
// }

/**
 * 滑的不是很好.但是这滑，真的很叼。
 */
class Solution {
    public int longestSubstring(String s, int k) {
        int result = 0, size = s.length();
        char[] sChars = s.toCharArray();
        int[] letterCount = new int[26];
        for (int p = 1; p <= 26; p++) {
            Arrays.fill(letterCount, 0);
            for (int i = 0, j = 0, total = 0, sum = 0; i < size; i++) {
                int rightCharASCII = sChars[i] - 'a';
                letterCount[rightCharASCII]++;
                if (letterCount[rightCharASCII] == 1) {
                    total++;
                }
                if (letterCount[rightCharASCII] == k) {
                    sum++;
                }
                while (total > p) {
                    int leftCharASCII = sChars[j++] - 'a';
                    letterCount[leftCharASCII]--;
                    if (letterCount[leftCharASCII] == 0) {
                        total--;
                    }
                    if (letterCount[leftCharASCII] == k - 1) {
                        sum--;
                    }
                }
                if (total == sum)
                    result = Math.max(result, i - j + 1);
            }
        }
        return result;
    }
}
class Solution1 {
    public int longestSubstring(String s, int k) {
        int ans = 0;
        int n = s.length();
        char[] cs = s.toCharArray();
        int[] cnt = new int[26];
        for (int p = 1; p <= 26; p++) {
            Arrays.fill(cnt, 0);
            // tot 代表 [j, i] 区间所有的字符种类数量；sum 代表满足「出现次数不少于 k」的字符种类数量
            for (int i = 0, j = 0, tot = 0, sum = 0; i < n; i++) {
                int u = cs[i] - 'a';
                cnt[u]++;
                // 如果添加到 cnt 之后为 1，说明字符总数 +1
                if (cnt[u] == 1) tot++;
                // 如果添加到 cnt 之后等于 k，说明该字符从不达标变为达标，达标数量 + 1
                if (cnt[u] == k) sum++;
                // 当区间所包含的字符种类数量 tot 超过了当前限定的数量 p，那么我们要删除掉一些字母，即「左指针」右移
                while (tot > p) {
                    int t = cs[j++] - 'a';
                    cnt[t]--;
                    // 如果添加到 cnt 之后为 0，说明字符总数-1
                    if (cnt[t] == 0) tot--;
                    // 如果添加到 cnt 之后等于 k - 1，说明该字符从达标变为不达标，达标数量 - 1
                    if (cnt[t] == k - 1) sum--;
                }
                // 当所有字符都符合要求，更新答案
                if (tot == sum) ans = Math.max(ans, i - j + 1);
            }
        }
        return ans;
    }
}
// @lc code=end
