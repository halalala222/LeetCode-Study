/*
 * @lc app=leetcode.cn id=1041 lang=java
 *
 * [1041] 困于环中的机器人
 */
/**
 * 想到的 key
 * 如果一次指令后回到原点
 * 没有注意到的 key
 * 1.不存在一次指令中中途循环，因为指令一定会完成的。
 * 2.如果方向不在初始的正北方向也会导致循环，在指令执行后，会饶一圈后重新回到原点。
 */
// @lc code=start
class Solution {
    public boolean isRobotBounded(String instructions) {
        int[] northDirection = new int[] { 0, 1 };
        int[] southDirection = new int[] { 0, -1 };
        int[] westDirection = new int[] { -1, 0 };
        int[] eastDirection = new int[] { 1, 0 };
        int[][] direction = new int[][] { northDirection, eastDirection, southDirection, westDirection };
        int currentDicrection = 0;
        int[] currentIndex = new int[] { 0, 0 };
        int n = instructions.length();
        for (int i = 0; i < n; i++) {
            char instruction = instructions.charAt(i);
            if (instruction == 'G') {
                int[] pace = direction[(currentDicrection)];
                currentIndex[0] += pace[0];
                currentIndex[1] += pace[1];
            }
            if (instruction == 'L') {
                int nextDicreciton = currentDicrection - 1;
                currentDicrection = (nextDicreciton + 4) % 4;
            }
            if (instruction == 'R') {
                int nextDicreciton = currentDicrection + 1;
                currentDicrection = nextDicreciton % 4;
            }
        }
        return (currentDicrection != 0 || (currentIndex[0] == 0 && currentIndex[1] == 0));
    }
}

/**
 * 会更加优雅的处理。
 * dist = new int[4]
 * dist[0] -> 北方行走的距离
 * dist[1] -> 东方行走的距离
 * dist[2] -> 南方行走的距离
 * dist[3] -> 西方行走的距离
 */
class anwserSolution {
    public boolean isRobotBounded(String instructions) {
        int k = 0;
        int[] dist = new int[4];
        for (int i = 0; i < instructions.length(); ++i) {
            char c = instructions.charAt(i);
            if (c == 'L') {
                k = (k + 1) % 4;
            } else if (c == 'R') {
                k = (k + 3) % 4;
            } else {
                ++dist[k];
            }
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || (k != 0);
    }
}
// @lc code=end
