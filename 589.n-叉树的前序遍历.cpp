#include<algorithm>
#include<vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
void Show(vector<int>* result,Node *root){
        result->push_back(root->val);
        if (root->children.size() != 0)
        {
            for (int i = 0; i < root->children.size(); i++)
            {
                Show(result,root->children[i]);
            }
        }
}

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        Show(&result,root);
        return result;
    }
};


// @lc code=end

