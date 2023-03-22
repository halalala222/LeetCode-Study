import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1626 lang=java
 *
 * [1626] 无矛盾的最佳球队
 */

/**
 * 看了下题解，发现有点吊，有一点没有发现
 * 今天起加入光荣进化
 */
// @lc code=start
class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int n = scores.length;
        int[][] people = new int[n][2];
        for (int i = 0; i < n; i++) {
            people[i] = new int[] { scores[i], ages[i] };
        }
        // lamda 有点忘记了
        int res = 0;
        Arrays.sort(people, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int[] dp = new int[n];
        // dp[0] = people[0][0];
        for (int i = 0; i < n; i++) {   
            for (int j = i - 1; j >= 0; j--) {
                if(people[j][1] <= people[i][1]){
                    dp[i] = Math.max(dp[i], dp[j]);
                }
            }
            dp[i] += people[i][0];
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
// @lc code=end
