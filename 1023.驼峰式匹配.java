import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1023 lang=java
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
// class Solution {
//     public List<Boolean> camelMatch(String[] queries, String pattern) {
//         String upperChar = "";
//         int size = pattern.length();
//         for(int i = 0;i < size;i++){
//             if(Character.isUpperCase(pattern.charAt(i))){
//                 upperChar += pattern.charAt(i);
//             }
//         }
//         List<Boolean> result = new ArrayList<Boolean>();
//         for(String query : queries){
//             int length = query.length();
//             String queryUpperChar = "";
//             for(int i = 0;i < length;i++){
//                 if(Character.isUpperCase(query.charAt(i))){
//                     queryUpperChar += query.charAt(i);
//                 }
//             }
//             System.out.printf("queryUpperChar : %s,upperChar : %s", queryUpperChar,upperChar);
//             result.add(queryUpperChar.equals(upperChar));
//         }
//         return result;
//     }
// }
/**
 * 感觉可能是没有读懂题目，而且示范用例也怪怪的。
 */
class StandardSolution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        int size = pattern.length();
        List<Boolean> result = new ArrayList<Boolean>();
        for(String query : queries){
            boolean flag = true;
            int p = 0;
            int n = query.length();
            for(int i = 0;i < n;i++){
                if(p < size && pattern.charAt(p) == query.charAt(i)){
                    p++;
                }else if(Character.isUpperCase(query.charAt(i))){
                    flag = false;
                    break;
                }                    
            }
            if(p < size){
                flag = false;
            }
            result.add(flag);
        }
        return result;
    }
}
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        int size = pattern.length();
        List<Boolean> result = new ArrayList<Boolean>();
        for(String query : queries){
            boolean flag = true;
            int p = 0;
            int n = query.length();
            for(int i = 0;i < n;i++){
                if(p < size && pattern.charAt(p) == query.charAt(i)){
                    p++;
                }else if(Character.isUpperCase(query.charAt(i))){
                    flag = false;
                    break;
                }                    
            }
            if(p < size){
                flag = false;
            }
            result.add(flag);
        }
        return result;
    }
}

// @lc code=end

