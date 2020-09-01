/**
 * @brief 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * @param argc
 * @param argv
 * @return 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x){
        int flag = 1;
        long xx = x;
        if(xx < 0) {
            xx = -xx;
            flag = -1;
        }
        stringstream ss;
        ss << xx;
        string input = ss.str();
        int i = 0, j = input.length() - 1;
        while(i < j){
            char temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++; j--;
        }
        xx = flag * atol(input.c_str());
        if(xx > INT32_MAX || xx < INT32_MIN) return 0;
        return xx;
    }

    int reverse_back(int x) {
        int flag = 1;
        long long input = x, num = 0;
        if(input < 0) {
            input = -input;
            flag = -1;
        }
        while(input){
            num = num * 10 + input % 10;
            input /= 10;
        }
        num *= flag;
        if(num > INT32_MAX || num < INT32_MIN) return 0;
        return num;
    }
    
    void run()
    {
        Solution solution;
        cout << solution.reverse(-2147483648);
        
        return 0;
    }

};

