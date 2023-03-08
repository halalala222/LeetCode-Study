#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1096 lang=cpp
 *
 * [1096] 花括号展开 II
 */

// @lc code=start
/**
 * 我超，这个是真吊啊，这个递归，我超拼接起来，我超真的吊啊
 * wc，真的牛逼
*/
//  {{a,z},a{b,c},{ab,z}}
//  {a,a{b,c},{ab,z}} | {z,a{b,c},{ab,z}}
//  {a,ab,{ab,z}} | {a,ac,{ab,z}} | {z,ab,{ab,z}} | {z,ac,{ab,z}}
//  {a,ab,ab} | {a,ab,z} | {a,ac,ab} | {a,ac,z} | {z,ab,ab} | {z,ab,z} | {z,ac,ab} | {z,ac,z}
//  {a,ab,ac,z}
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        return vector<string>(s.begin(), s.end());
    }

private:
    set<string> s;

    void dfs(string exp) {
        int j = exp.find_first_of('}');
        if (j == string::npos) {
            s.insert(exp);
            return;
        }
        int i = exp.rfind('{', j);
        string a = exp.substr(0, i);
        string c = exp.substr(j + 1);
        stringstream ss(exp.substr(i + 1, j - i - 1));
        string b;
        while (getline(ss, b, ',')) {
            dfs(a + b + c);
        }
    }
};
// @lc code=end
