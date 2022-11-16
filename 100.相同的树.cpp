/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
 * 递归官方写法比我更好
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        // 下面俩个 if 其实是同一个意思，就是说其中如果有一个是 nullptr 则返回 false
        // if (p == nullptr && q != nullptr)
        // {
        //     return false;
        // }
        // if (p != nullptr && q == nullptr)
        // {
        //     return false;
        // }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        
        if (p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
/**
 * 官方题解的另外一个方法是，维护俩个队列，根据队列中的每个节点，一个节点一个节点进行判断比较
*/
// @lc code=end

