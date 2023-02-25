#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
class Solution
{
public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        unordered_map<string, vector<int>> timeMap;
        for (int i = 0; i < keyName.size(); i++)
        {
            string name = keyName.at(i);
            string time = keyTime.at(i);
            // 这里没有进行字符转换成为 int
            int hour = (time.at(0) - '0') * 10 + (time.at(1) - '0');
            int minute = (time.at(3) - '0') * 10 + (time.at(4) - '0');
            timeMap[name].emplace_back(hour * 60 + minute);
        }
        vector<string> result;
        for (auto &[name, times] : timeMap)
        {
            sort(times.begin(), times.end());
            for (int i = 2; i < times.size(); i++)
            {
                int difference = times.at(i) - times.at(i - 2);
                if (difference <= 60)
                {
                    result.emplace_back(name);
                    break;
                }
            }
        }
        // 没有按照字典排序
        sort(result.begin(), result.end());
        return result;
    }
};
// class Solution {
// public:
//     vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
//         unordered_map<string, vector<int>> timeMap;
//         int n = keyName.size();
//         for (int i = 0; i < n; i++) {
//             string name = keyName[i];
//             string time = keyTime[i];
//             int hour = (time[0] - '0') * 10 + (time[1] - '0');
//             int minute = (time[3] - '0') * 10 + (time[4] - '0');
//             timeMap[name].emplace_back(hour * 60 + minute);
//         }
//         vector<string> res;
//         for (auto &[name, list] : timeMap) {
//             sort(list.begin(), list.end());
//             int size = list.size();
//             for (int i = 2; i < size; i++) {
//                 int time1 = list[i - 2], time2 = list[i];
//                 int difference = time2 - time1;
//                 if (difference <= 60) {
//                     res.emplace_back(name);
//                     break;
//                 }
//             }
//         }
//         sort(res.begin(), res.end());
//         return res;
//     }
// };

// @lc code=end
