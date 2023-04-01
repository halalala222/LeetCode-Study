import java.lang.reflect.Proxy;

/*
 * @lc app=leetcode.cn id=831 lang=java
 *
 * [831] 隐藏个人信息
 */

// @lc code=start
class MySolution {
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

class Solution {
    //处理得好好，可以不用使用循环，只给定四个可以直接选择这个前缀。
    String[] country = {"", "+*-", "+**-", "+***-"};

    public String maskPII(String s) {
        //可以直接找到下标，如果有的话
        int at = s.indexOf("@");
        if (at > 0) {
            //可以直接全部变成小写
            s = s.toLowerCase();
            return (s.charAt(0) + "*****" + s.substring(at - 1)).toLowerCase();
        }
        //直接使用正则把不是数字的直接全部置换成空的字符串
        s = s.replaceAll("[^0-9]", "");
        return country[s.length() - 10] + "***-***-" + s.substring(s.length() - 4);
    }
}

// @lc code=end
