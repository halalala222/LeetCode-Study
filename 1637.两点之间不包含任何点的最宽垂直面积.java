import java.util.ArrayList;
import java.util.Comparator;
import java.util.Arrays;;

/*
 * @lc app=leetcode.cn id=1637 lang=java
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */

 /*
  * easy
  */
// @lc code=start
class Solution1 {
    public int maxWidthOfVerticalArea(int[][] points) {
        ArrayList<Integer> pointsx = new ArrayList<Integer>();
        int maxWidth = 0;
        for (int[] point : points) {
            pointsx.add(point[0]);
        }
        pointsx.sort(Comparator.naturalOrder());
        for (int i = 1; i < pointsx.size(); i++) {
            maxWidth = Math.max(maxWidth, (pointsx.get(i) - pointsx.get(i - 1)));
        }
        return maxWidth;
    }
}
class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        // 使用一个 lambda 优雅，就直接按照 x 下标进行排序了。
        Arrays.sort(points, (a, b) -> a[0] - b[0]);
        int mx = 0;
        for (int i = 1; i < points.length; i++) {
            mx = Math.max(points[i][0] - points[i - 1][0], mx);
        }
        return mx;
    }
}

// @lc code=end
