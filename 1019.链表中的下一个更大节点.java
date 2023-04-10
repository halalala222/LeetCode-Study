import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

/*
 * @lc app=leetcode.cn id=1019 lang=java
 *
 * [1019] 链表中的下一个更大节点
 */
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * 直接暴力也可以通过……………… cool，不用二分也可以通过…………
 */
class Solution1 {
    public int[] nextLargerNodes(ListNode head) {
        ArrayList<Integer> nodesValues = new ArrayList<Integer>();
        while (head != null) {
            nodesValues.add(head.val);
            head = head.next;
        }
        int size = nodesValues.size();
        int[] result = new int[size];
        for (int i = 0; i < size; i++) {
            int currentValue = nodesValues.get(i);
            for (int j = i + 1; j < size; j++) {
                int preValue = nodesValues.get(j);
                if (preValue > currentValue) {
                    result[i] = preValue;
                    break;
                }
            }
        }
        return result;
    }
}

/**
 * 题解用的单调栈，学习一下，我测，单调栈实在是太叼了
 * 
 */

class Solution {
    public int[] nextLargerNodes(ListNode head) {
        ArrayList<Integer> nodesValue = new ArrayList<Integer>();
        while (head != null) {
            nodesValue.add(head.val);
            head = head.next;
        }
        int size = nodesValue.size();
        /**
         * stack 维护的是一个当前 index = i，在 index > i 的区间内 >= values[i + 1] 的值的一个从栈底递减到栈顶的一个堆栈
         * 对于 index = i 来说，如果堆栈不为空，以及如果栈顶的元素 <= value[i] 表示栈顶元素不是所求得数，
         * 将栈顶元素出栈，此时栈顶元素增加，如果还不是那么继续出栈，直到堆栈为空或者栈顶元素 > value[i]
         * 因为如果 index > i 中没有比 value[i] 更大的元素，那么留在堆栈没有任何作用，因为只有比 value[i] 更大才可能成为
         * index < i 的下一个最大元素。
         */
        Deque<Integer> stack = new ArrayDeque<Integer>();
        int[] result = new int[size];
        for (int i = size - 1; i >= 0; i--) {   
            int currentValue = nodesValue.get(i);
            while (!stack.isEmpty() && stack.peek() <= currentValue) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                result[i] = stack.peek();
            }
            stack.push(currentValue);
        }
        return result;
    }
}
// @lc code=end
