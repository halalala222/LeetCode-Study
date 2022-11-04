/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
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
/*
 * 一开始想的使用递归，但是看了题解后，感觉好像确实是循环就可以了。
 * 因为在不断的像队列中 push 元素，最终直到队列中没有元素就结束就好了，又想了一下，还是有点不对劲
 * 如下，会导致指针有问题，但是不想看了.
*/
// void Show(vector<vector<int>>* result, queue<TreeNode*>* tempQueue,vector<int> tempResult,vector<TreeNode *> oneLevelTreeNode){
//     while (!tempQueue->empty())
//     {
//         TreeNode* templateTreeNode = tempQueue->front();
//         tempResult.push_back(templateTreeNode->val);
//         oneLevelTreeNode.push_back(templateTreeNode);
//         tempQueue->pop();
//     }
//     for (int i = 0; i < oneLevelTreeNode.size(); i++)
//     {
//         if (oneLevelTreeNode[i]->left != nullptr)
//         {
//             tempQueue->push(oneLevelTreeNode[i]->left);
//         }
//         if (oneLevelTreeNode[i]->right != nullptr)
//         {
//             tempQueue->push(oneLevelTreeNode[i]->right);
//         }
//     }
//     result->push_back(tempResult);
//     tempResult.clear();
//     oneLevelTreeNode.clear();
//     Show(result,tempQueue,tempResult,oneLevelTreeNode);
// }
/*
 * 使用循环卡在了怎么保证出队列的都是当前层，但是看了题解之后理解了，可以在 while 每次循环内部，
 * size = 队列的 size，后续使用 for 循环变量当前层的所有节点。原因在于使用 size + for 可以保证
 * 每一层的所有节点全部出队列，即每次 while 循环都是对于对应一层节点。
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> oneLevelTreeNodes;
        if (root == nullptr){ return result;}
        oneLevelTreeNodes.push(root);
        while (!oneLevelTreeNodes.empty())
        {
            int size = oneLevelTreeNodes.size();
            vector<int> oneLevelNode;
            for (int i = 0; i < size; i++)
            {
                TreeNode* nowNode = oneLevelTreeNodes.front();
                oneLevelNode.push_back(nowNode->val);
                if (nowNode->left != nullptr)
                {
                    oneLevelTreeNodes.push(nowNode->left);
                }
                if (nowNode->right != nullptr)
                {
                    oneLevelTreeNodes.push(nowNode->right);
                }
                 oneLevelTreeNodes.pop();
            }
            result.push_back(oneLevelNode);
        }
        return result;
    }
};


// @lc code=end

