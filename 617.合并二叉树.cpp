/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
 * []
 * [1]
*/
/**
 * 题解的第二个方法可能和我的有点像，但是实现可能不一样把
*/
void Traverse(TreeNode* root1,TreeNode* root2) {
    if (root1 != nullptr)
    {
        if (root2 != nullptr)
        {
            root1->val += root2->val;
            if (root1->left == nullptr && root2->left != nullptr)
            {
                root1->left = root2->left;
                root2->left = nullptr;
            }
            if (root1->right == nullptr && root2->right != nullptr)
            {
                root1->right = root2->right;
                root2->right = nullptr;
            }
            Traverse(root1->left,root2->left);
            Traverse(root1->right,root2->right);            
        }            
        Traverse(root1->left,nullptr);
        Traverse(root1->right,nullptr);          
    }
}
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //对于这种情况直接返回 nullptr
        if (root1 == nullptr)
        {
            return root2;
        }      
        Traverse(root1,root2);
        return root1;
    }
};

/**
 * 我擦，这个递归好叼，直接添加条件判断如果，
 * 如果此时有一个节点为 nullptr 则直接返回另外的节点
 * 如果都不为空，则创建一个新的节点，
 * 即不是在某一个树上进行操作，而是新建了一个树，不断的往树中添加节点
 * 吊
*/
class StandardSolution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};
// @lc code=end

