import java.lang.reflect.Proxy;

/*
 * @lc app=leetcode.cn id=831 lang=java
 *
 * [831] 隐藏个人信息
 */

// @lc code=start
class Solution {
    public String maskPII(String s) {
        boolean is_email = s.contains("@");
        String result = "";
        if (is_email) {
            String[] emailData = s.split("@");
            for (int i = 0; i < emailData.length; i++) {
                emailData[i] = emailData[i].toLowerCase();
            }
            result += emailData[0].charAt(0) + "*****" + emailData[0].charAt(emailData[0].length() - 1) + "@"
                    + emailData[1];
        } else {
            String phoneNum = "";
            for (int i = 0; i < s.length(); i++) {
                if ('0' <= s.charAt(i) && s.charAt(i) <= '9') {
                    phoneNum += s.charAt(i);
                }
            }
            int country_code = phoneNum.length() - 10;
            if (country_code > 0) {
                result += "+";
                for (int i = 0; i < country_code; i++) {
                    result += "*";
                }
                result += "-";
            }
            result += "***-***-";
            result += phoneNum.substring(phoneNum.length() - 4, phoneNum.length());
        }
        return result;
    }
}
// @lc code=end
