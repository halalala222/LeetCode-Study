#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */
/**
 * 想复杂了，可以不用 position，每一个都可以直接 push_back 就可以了
 * 以及可以每一个维护一个 k，让 k 不断的增加进行遍历到一个没出现的即可
 */
// @lc code=start
// class Solution
// {
// public:
//     vector<string> getFolderNames(vector<string> &names)
//     {
//         unordered_map<string, int> namesCount;
//         unordered_map<string, int> namesPosition;
//         for (int i = 0; i < names.size(); i++)
//         {
//             string name = names.at(i);
//             int isExited = namesCount.count(name);
//             if (isExited)
//             {

//                 int count = namesCount[name];
//                 printf("%s : %d\n", name.c_str(), count);
//                 namesCount[name]++;
//                 name.push_back('(');
//                 name.push_back(count + '0');
//                 name.push_back(')');
//                 namesPosition[name] = i;
//                 namesCount[name] += 1;
//             }
//             else
//             {
//                 printf("%s\n", name.c_str());
//                 namesCount[name] += 1;
//                 namesPosition[name] = i;
//                 int index = name.find_last_of('(');
//                 if (index != -1)
//                 {
//                     string baseName = name.substr(0, index);
//                     int baseNameIsExited = namesCount.count(baseName);
//                     if (baseNameIsExited)
//                     {
//                         printf(" baseName : %s\n", baseName.c_str());
//                         namesCount[baseName] += 1;
//                     }
//                 }
//             }
//         }
//         vector<string> result(names.size());
//         for (auto &n : namesCount)
//         {
//             string name = n.first;
//             int position = namesPosition[name];
//             result.at(position) = name;
//         }
//         return result;
//     }
// };

class Solution
{
public:
    string addSuffix(string name, int k)
    {
        return name + '(' + to_string(k) + ')';
    }

    vector<string> getFolderNames(vector<string> &names)
    {
        unordered_map<string, int> nextKOfDirectory;
        vector<string> result;
        for (auto name : names)
        {
            int isExited = nextKOfDirectory.count(name);
            if (!isExited)
            {
                nextKOfDirectory[name] = 1;
                // 因为没有出现过直接将结果 push
                result.push_back(name);
            }
            else
            {
                int k = nextKOfDirectory[name];
                // 递增 k ，找到对应的最小的未出现的 k
                while (nextKOfDirectory.count(addSuffix(name,k)))
                {
                    ++k;
                }
                // 当前最小值为 k，下一个值为 k + 1
                nextKOfDirectory[name] = k + 1;
                nextKOfDirectory[addSuffix(name,k)] = 1;
                result.push_back(addSuffix(name,k));
            }
        }
        return result;
    }
};
// @lc code=end
