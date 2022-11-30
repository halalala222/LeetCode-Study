#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
/**
 * 焯，超时l
*/
// class FreqStack
// {
// public:
//     vector<int> data;
//     unordered_map<int,int> count;
// public:
//     FreqStack()
//     {
//         this->data = vector<int> (0);
//     }

//     void push(int val)
//     {
//         this->data.push_back(val);
//         count[val]++;
//     }

//     int pop()
//     {
//         vector<int> intResult;
//         bool isDone = false;
//         int result = 0;
//         int maxCount = -1,size = this->data.size();
//         for (auto i = this->count.begin(); i != this->count.end(); i++)
//         {
//             maxCount = max(maxCount,i->second);
//         }
//         for (auto i = this->count.begin(); i != this->count.end(); i++)
//         {
//             if(maxCount == i->second) intResult.push_back(i->first);
//         }
//         int countSize = intResult.size();
//         for (int i = 0; i < this->data.size(); i++)
//         {
//             printf("%d  ",this->data.at(i));
//         }
//         printf("\n");
//         for (int i = 0; i < intResult.size(); i++)
//         {
//             printf("%d  ",intResult.at(i));
//         }
//         printf("\n");
//         for (int i = size - 1; i > -1 && !isDone; i--)
//         {
//             for (int j = 0; j < countSize; j++)
//             {
//                 if (this->data.at(i) == intResult.at(j)) {
//                     this->count[data.at(i)]--;
//                     result = this->data.at(i);
//                     this->data.at(i) = -1;
//                     isDone = true;
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };

/**
 * 看了下题解，感觉挺牛的这个想法，使用 cnt 来维护一个 map
 * 每个数据出现的次数，
 * 根据出现次数，每个出现次数定一个栈，然后入栈，出栈，都是按照模拟的
 * 入栈出栈，所以到时候如果有多个相同的，就不用担心顺序问题，以及保证
 * 每个大小都能有出去的机会
*/
class FreqStack {
    unordered_map<int, int> cnt;
    vector<stack<int>> stacks;
public:
    void push(int val) {
        if(cnt[val] == stacks.size()) 
            stacks.push_back({});
        stacks[cnt[val]].push(val);
        cnt[val]++;
    }

    int pop() {
        int val = stacks.back().top();
        stacks.back().pop();
        if (stacks.back().empty())
        {
            stacks.pop_back();
        }
        cnt[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end
