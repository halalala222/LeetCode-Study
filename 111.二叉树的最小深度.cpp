#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
/**
 * 最初得版本，会导致单边树无法递归到，导致错误，单边树会会找 null 那边然后 0 + 1
*/
/**
 * int deep(TreeNode* root){
        if (root == nullptr)
        {
            return 0;
        }
        return min(deep(root->left),deep(root->right)) + 1;
    }
    int minDepth(TreeNode* root) {
        return deep(root);
    }
*/
class Solution {
public:
    int deep(TreeNode* root){
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left != nullptr && root->right == nullptr)
        {
            return deep(root->left) + 1;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            return deep(root->right) + 1;
        }
        return min(deep(root->left),deep(root->right)) + 1;
    }
    int minDepth(TreeNode* root) {
        return deep(root);
    }
};


// @lc code=end
/**
 * 题解的做法比我好，
 * 如果 min(L,R)为0会导致则返回 MAX(L,R)则表示，如果其中一个子节点为 null 则返回另外一个节点的遍历，因为此时 null 节点不会有叶子节点
 * 如果不为 0 则返回最小值
 * 但是和我的想法一样，不过我是通过判断是否是 null，这个直接一起判断更好
*/
int minDepth(TreeNode* root) {
    if (!root) return 0;
    int L = minDepth(root->left), R = minDepth(root->right);
    return 1 + (min(L, R) ? min(L, R) : max(L, R));
}