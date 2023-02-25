#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
 */
struct TreeNode
{
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
 * 有想到从玩家一选的节点的所关联的三个节点中选择最大的那个即可，但是觉得好像要遍历三次就放弃了。
 * 但是 dfs 可以可以，获取该节点的左节点和右节点，可以通过关系算出来父节点，
 * left + right + parent + 1 = n;
 * 算出来之后可以 player1 + player2 = n;
 * player2 > player1 -> n < 2players;
 * 只要一次遍历就可以了其实。
 * 看了下对应的遍历，好像确实不用找到。player1 的 x 的是哪个节点
 * 再使用后序遍历的递归的时候，低轨到当前节点如果 val = x，对应的结果就是 x 的左子树和右子树的长度，因为递归的结果是一层一层返回给上一层的
 */
/**
 * 没有找到对应的数量上的关系，没有了解到对应递归的含义，并不用找到 player1 的节点，在遍历的时候就可以知道其左子树和右子树的个数
*/
class Solution
{
public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        int left, right;
        function<int(TreeNode *)> dfs = [&](TreeNode *node)
        {
            if (node == nullptr)
                return 0;
            int ls = dfs(node->left);
            int rs = dfs(node->right);
            if (node->val == x)
                left = ls, right = rs;
            return ls + rs + 1;
        };
        dfs(root);
        return max({left, right, n - 1 - left - right}) * 2 > n;
    }
};
// @lc code=end
