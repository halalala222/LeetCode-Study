#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

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

class Solution {
public:
    int maxDepth(Node* root) {
        std::function<int(Node*)> dfs;
        dfs = [&](Node* node) -> int{
            int minInt = 0;
            if (node == nullptr)
            {
                return 0;
            }
            for (int i = 0; i < node->children.size(); i++)
            {
                minInt =max(minInt,dfs(node->children.at(i)));
            }
            return minInt+1;
        };
        return dfs(root);
    }
};
//在语法上比我更加的优雅。
class StandardSolution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        int max_depth = 1;
        for(int i=0;i<root->children.size();i++){
            max_depth = max(max_depth, 1 + maxDepth(root->children[i]));
        }
        return max_depth;
    }
};
// @lc code=end

