#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a.at(0) <= b.at(0);
    }
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        int size1 = items1.size(), size2 = items2.size();
        unordered_map<int, int> weights;
        for (int i = 0; i < size1; i++)
        {
            vector<int> item = items1.at(i);
            weights[item.at(0)] += item.at(1);
            printf("value : %d,weight : %d       ", item.at(0), weights[item.at(0)]);
        }
        for (int i = 0; i < size2; i++)
        {
            vector<int> item = items2.at(i);
            weights[item.at(0)] += item.at(1);
            printf("value : %d,weight : %d       ", item.at(0), weights[item.at(0)]);
        }
        vector<vector<int>> items;
        for (auto weight : weights)
        {
            vector<int> temp;
            temp.push_back(weight.first);
            temp.push_back(weight.second);
            items.push_back(temp);
        }
        sort(items.begin(),items.end(),cmp);
        return items;
    }
};

/**
 * map 会自动维护 根据【键】的大小进行排序
*/
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (auto &v : items1) {
            mp[v[0]] += v[1];
        }
        for (auto &v : items2) {
            mp[v[0]] += v[1];
        }

        vector<vector<int>> res;
        for (auto &[k, v] : mp) {
            res.push_back({k, v});
        }
        return res;
    }
};
// @lc code=end
