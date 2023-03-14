/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

/**
 * 其实这个感觉有点考数学了，如果其实是无限循环的话并不能说一定就会出现重复的数字，因为数字是无限多的，例子也是无限多的，
 * 前提就是在于你需要知道这个数学
 * 感觉能得出这个结论是在于，知道循环一定是某一串数字的循环，
 * 喔因为是 int 整数类型，就会导致如果是无限循环的话，就一定会出现重复的数据，受教了
*/
// @lc code=start
/**
 * 使用 set 集合。通过 set 判断是否出现过该数字，如果出现过就表示要进入循环了，
 * return false
*/
/**
 * 使用快慢指针，这个很叼，用快慢指针来判断是否循环，如果 slow = falst 表示一定有循环，可能是 1 导致的。
 * 因为 1 会陷入 1 1 1 1 1 1 的循环。如果不是 1 导致的话，就表示不是快乐数
 * fast 
*/
class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while (n > 0)
        {
            int num = n % 10;
            sum += num * num;
            n /= 10;
        }
        
    }
    bool isHappy(int n) {
        /**
         * 初始化，slow 和 fast 在同一个起点上
        */
        int slow = n,fast = n;
         do{
            slow = getSum(slow);
            /*
                fast 要比 slow 都走一步，所以 fast 进行两次求和
            */
            fast = getSum(fast);
            fast = getSum(fast);
        }while(slow != fast);
        return slow == 1;
    }
};
// @lc code=end

