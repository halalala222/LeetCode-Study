#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
 * 尝试递归，失败 md。递归怎么能解
 * 想了下，感觉应该是我想过多了，多想了过多的一层，
 * 递归的思路就是俩条一起，只对当前俩个节点负责，其余继续使用递归进行判断
 * 因为此层和下一层的想法应当都是一样的，所以递归只需要在意其中一层即可
*/
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (root == nullptr)
//         {
//             return true;
//         }
        
//         std::function<bool(TreeNode*,TreeNode*)> func1;
//         func1 = [&](TreeNode* left,TreeNode* right) -> bool{
//             if (left == nullptr && right == nullptr)
//             {
//                 printf("-------------1-------------\n");
//                 return true;
//             }
//             if (left == nullptr || right == nullptr)
//             {
//                 printf("-------------2-------------\n");
//                 return false;
//             }
//             if (left->val != right->val)
//             {
//                 return false;
//             }
//             if (left->left == nullptr && right->right == nullptr)
//             {
//                 printf("-------------3-------------\n");
//                 return true;
//             }
//             if (left->right == nullptr && right->left == nullptr)
//             {
//                 printf("-------------5-------------\n");
//                 return true;
//             }
//             if (left->left == nullptr || right->right == nullptr)
//             {
//                 printf("-------------6-------------\n");
//                 return false;
//             }
//             if (left->right == nullptr || right->left == nullptr)
//             {
//                 printf("-------------7-------------\n");
//                 return false;
//             }
            
//             if (left->right->val != right->left->val)
//             {
//                 printf("-------------8-------------\n");
//                 return false;
//             }
//             if (left->left->val != right->right->val)
//             {
//                 printf("-------------9-------------\n");
//                 return false;
//             }
//             return func1(left->left,right->right) && func1(left->right,right->left);
//         };
//         return func1(root->left,root->right);
//     }
// };

class Solution {
public:
    bool check(TreeNode* left,TreeNode* right){
        //俩个节点都为空，返回 true
        if (!left && !right) return true;
        //俩个节点中有一个为 true 则返回 false，表示俩个中有一个空一个非空
        if (!left || !right) return false;
        return left->val == right->val && check(left->right,right->left) && check(left->left,right->right);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};
// @lc code=end

