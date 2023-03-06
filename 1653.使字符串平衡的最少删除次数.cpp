#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */

/**
 *
 */
// @lc code=start
class Solution
{
public:
    int minimumDeletions(string s)
    {
        // int size = s.size(), firstab = 0, firstba = 0, result1 = 0, result2 = 0;
        // if (size == 1)
        //     return 0;
        // for (int i = 0; i < size; i++)
        // {
        //     if ((i < size - 1) && s.at(i) == 'a' && s.at(i + 1) == 'b' && !firstab)
        //         firstab = i + 1;
        //     if ((i < size - 1) && s.at(i) == 'b' && s.at(i + 1) == 'a' && !firstba)
        //         firstba = i + 1;
        // }
        // for (int i = firstab; i < size && firstab != 0; i++)
        // {
        //     if (s.at(i) == 'a')
        //         result1++;
        // }
        // for (int i = 0; i < firstab; i++)
        // {
        //     if (s.at(i) == 'b')
        //         result1++;
        // }
        // for (int i = firstba; i < size && firstba != 0; i++)
        // {
        //     if (s.at(i) == 'a')
        //         result2++;
        // }
        // for (int i = 0; i < firstba; i++)
        // {
        //     if (s.at(i) == 'b')
        //         result2++;
        // }
        // return min(result1, result2);
        /**
         * 没有想法，但是现在知道了，是我的思考方式错误了，因为并不是第一个 ab 或者 第一 ba 的时候是最小值
         * 应该是遍历每一个间隔，求出间隔中的最小值。
         * 而且题解的解法很吊
        */
        int righta = 0,leftb = 0,result = 0;
        /**
         * 统计所有 a 的个数
        */
        for(char c : s)
        if (c == 'a')
        {
            righta++;
        }
        /**
         * result 的初始值，为当间隔线在 0 之前时，要去除掉 [0,size] 的所有 a；
        */
        result = righta;
        for(char c : s)
        {
            if(c == 'a')
            /**
             * 这里是最巧妙的，如果 c 的 index = 0，表示此时的分隔线在 0 后，既要统计 [1,size] 的所有 a，这个时候
             * 如果当前为 a 那么需要的 righta 就是不断递减过来的
            */
                righta--;
            if(c == 'b')
                leftb++;
            result = min(result,leftb + righta);
        }
        return result;
       
    }
};
// @lc code=end
