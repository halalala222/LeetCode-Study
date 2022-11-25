#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
        {
            return vector<vector<int>>(0);
        }
        int count = 1;
        vector<vector<int>> result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (root != nullptr && !nodes.empty())
        {
            int size = nodes.size();
            printf("size : %d\n",size);
            vector<int> rowTemp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *now = nodes.front();
                rowTemp.push_back(now->val);
                if (now->left != nullptr)
                {
                    nodes.push(now->left);
                }
                if (now->right != nullptr)
                {
                    nodes.push(now->right);
                }
                nodes.pop();
            }
            if (count % 2 == 0)
            {
                reverse(rowTemp.begin(),rowTemp.end());
            }
            count++;
            result.push_back(rowTemp);
        }
        return result;
    }
};
// @lc code=end

