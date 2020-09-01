//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//
//例如，给出 n = 3，生成结果为：
//
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]

#ifdef t0022

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        dp("", 2 * n, 0, 0);
        return result;
    }
    
    void dp(string a, int index, int cntl, int cntr){
        if(a.length() == index){
            result.push_back(a);
            return;
        } else{
            if(cntl < index / 2){
                dp(a + '(', index, cntl+1, cntr);
            }
            if(cntr < cntl){
                dp(a + ')', index, cntl, cntr+1);
            }
        }
    }
    
    void run()
    {
        vector<string> result = generateParenthesis(3);
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << endl;
        }
        return 0;
    }

};

#endif

