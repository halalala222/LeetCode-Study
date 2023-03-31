import java.util.ArrayList;
import java.util.List;

/**
 * 想法有问题，因为有的子集没有想到
 */
// class Solution {
// public List<List<Integer>> subsets(int[] nums) {
// List<List<Integer>> result = new ArrayList<>();
// int size = nums.length;
// for (int i = 0; i < size; i++) {
// ArrayList<Integer> subList = new ArrayList<Integer>();
// for (int j = i; j < size; j++) {
// subList.add(nums[j]);
// ArrayList<Integer> newSubList = new ArrayList<Integer>(subList);
// result.add(newSubList);
// }
// }
// result.add(new ArrayList<Integer>());
// return result;
// }
// }

/**
 * 这个好屌，
 */
class Solution1 {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<Integer>());
        // 最外层循环，遍历 nums 中每一个数据
        for (int num : nums) {
            // 遍历当前 result 中的结果，将之前所有的结果都添加当前的 num，将结果添加到 result 中
            for (int i = 0, j = result.size(); i < j; i++) {
                ArrayList<Integer> sub = new ArrayList<Integer>(result.get(i));
                sub.add(num);
                result.add(sub);
            }
        }
        return result;
    }
}

/**
 * 这个也好叼
 * 使用位运算。
 * https://leetcode.cn/problems/power-set-lcci/solution/hui-su-wei-yun-suan-deng-gong-4chong-fang-shi-jie-/
 * [1,2,3]
 * 0 0 0 (0) -> []
 * 0 0 1 (1) -> [3]
 * 0 1 0 (2) -> [2]
 * 0 1 1 (3) -> [2,3]
 * 1 0 0 (4) -> [1]
 * 1 0 1 (5) -> [1,3]
 * 1 1 0 (6) -> [1,2]
 * 1 1 1 (7) -> [1,2,3]
 * 即只要遍历 [0,1 << nums.length - 1] 之间的所有数值，根据其位运算获得是否需要将 nums 中对应的数据添加。
 */
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int subLength = 1 << nums.length;
        List<List<Integer>> result = new ArrayList<>(subLength);
        for (int i = 0; i < subLength; i++) {
            ArrayList<Integer> sub = new ArrayList<Integer>();
            for (int j = 0; j < nums.length; j++) {
                // 通过右移操作符以及 & 1 来判断对应的位上是不是 1 吊
                if (((i >> j) & 1) == 1) {
                    sub.add(nums[j]);
                }
            }
            result.add(sub);
        }
        return result;
    }
}