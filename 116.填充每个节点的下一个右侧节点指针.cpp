#include <queue>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/**
 * 很简单的一个想法，就是层序遍历后，存入一个数组中，之后在数组中进行处理。
*/
class MySolution {
public:
    Node* connect(Node* root) {
        queue<Node*> nodes;
        if (root == nullptr) return nullptr;        
        nodes.push(root);
        while (!nodes.empty())
        {
            int size = nodes.size();
            vector<Node*> tempNodes;
            for (int i = 0; i < size; i++)
            {
                Node* nowNode = nodes.front();
                tempNodes.push_back(nowNode);
                if (nowNode->left != nullptr)
                {
                    nodes.push(nowNode->left);
                }
                if (nowNode->right != nullptr)
                {
                    nodes.push(nowNode->right);
                }
                nodes.pop();
            }
            for (int i = 0; i + 1< size; i++)
            {
                tempNodes[i]->next = tempNodes[i+1];
            }
        }
        return root;
    }
};

/**
 * 看了下题解的第一种方法，很吊
 * 大概的思路就是使用递归，通过图片可以知道
 * 当前节点的 left->next = right
 * 当前节点的 right->next = now->next->left
 * 这样子就可以进行递归，使用前序遍历就可以解决
*/

class StandardSolution1 {
public:
    Node* connect(Node* root) {
        if (root == NULL)
        {
            return root;
        }
        if (root->left != NULL)
        {
            root->left->next = root->right;
        }
        if (root->right != NULL && root->next != NULL)
        {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

/**
 * 题解的第二个方法也挺牛的，
 * 只需要遍历左边，因为左边节点如果为空的表示当前二叉树已经遍历完成
 * 使用双指针进行控制
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *pre = root,*curr;
        while (pre)
        {
            curr = pre;
            while (curr && curr->left)
            {
                curr->left->next = curr->right;
                //这里不用担心 right 为 nullptr 是因为，这个是个完全二叉树
                if (curr->next) curr->right->next = curr->next->left;
                //使用 next 将 curr 当前所在层的所有节点都遍历
                curr = curr->next;
            }
            //pre移动到下一层
            pre = pre->left;
        }
        return root;
    }
};

// @lc code=end

