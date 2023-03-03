#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    string printBin(double num)
    {
        string result = "0.";
        int count = 0;
        while (num != 0.0)
        {
            printf("count : %d", count);
            num *= 2;
            printf("num : %lf\n", num);
            if (num >= 1.0)
            {
                result.push_back('1');
                count++;
                num -= 1.0;
            }
            else
            {
                result.push_back('0');
                count++;
            }
            if (count > 31)
            {
                return "ERROR";
            }
        }
        return result;
    }
};