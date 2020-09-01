//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    
    bool isValid(string s) {
        if(s.length() % 2 == 1) return false;
        if(s.length() == 0) return true;
        stack<char> mystack;
        for(int i = 0; i < s.length(); i++){
            if(mystack.empty()) {
                mystack.push(s[i]);
                continue;
            } else{
                if(mystack.top() == s[i]-1 || mystack.top() == s[i]-2){
                    mystack.pop();
                } else{
                    mystack.push(s[i]);
                }
            }
        }
        if(mystack.empty()) return true;
        else return false;
    }
    
    void run(){
        cout << solution.isValid("([)]");
    }
};