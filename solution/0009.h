/**
 * @brief 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x){
        int y = 0;
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        
        while(x > y){
            y = y * 10 + x % 10;
            x = x / 10;
        }
        
        return x == y || (x == (y / 10));
    }

    bool isPalindrome_bak(int x) {
        stringstream ss;
        ss << x;
        string input = ss.str();
//        cout << input;
        int i = 0, j = input.length() - 1;
        while(i < j){
            if(input[i] != input[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    void run()
    {
        Solution solution;
        cout << solution.isPalindrome(1213121);
        return 0;
    }
};


