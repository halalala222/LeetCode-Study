import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=2404 lang=java
 *
 * [2404] 出现最频繁的偶数元素
 */

// @lc code=start
class Solution {
    public int mostFrequentEven(int[] nums) {
        HashMap<Integer, Integer> appearedNum = new HashMap<Integer, Integer>();
        int maxCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                System.out.println(num);
                Integer count = appearedNum.get(num);
                if (count == null) {
                    appearedNum.put(num, 1);
                    count = 1;
                } else {

                }
                appearedNum.put(num, count + 1);
                maxCount = Math.max(maxCount, count + 1);
            }
        }
        if (appearedNum.isEmpty()) {
            return -1;
        }
        int minNum = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : appearedNum.entrySet()) {
            if (entry.getValue() == maxCount) {
                minNum = Math.min(minNum, entry.getKey());
            }
        }
        return minNum;
    }
}

class Solution1 {
    public int mostFrequentEven(int[] nums) {
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for (int num : nums) {
            if (num % 2 == 0) {
                // 6 学到了，这个这么吊传入一个 lambda 然后使用 .applay 方法，将 oldValue,value sum 了
                count.merge(num, 1, Integer::sum);
            }
        }
        int ans = -1,max = 0;
        for(var e : count.entrySet()){
            int num = e.getKey(),value = e.getValue();
            // 6 这一步的逻辑也学到了。
            if(value > max || (value == num && ans > num)){
                ans =num;
                max = value;
            }
        }
        return ans;
    }
}
// @lc code=end
