/**
 * @brief 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * @param argc
 * @param argv
 * @return 
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        int p[2 * s.length()+1][s.length()+1] = {0};
        int maxn[2 * s.length()+1] = {0};
        for(int i = 0; i < 2 * s.length() - 2; i++){
            if(i % 2 == 0)
                p[i][0] = 1;
        }
        for(int i = 0; i < 2 * s.length() - 2; i++){
            if(i % 2 == 0) {
                int temp = i / 2;
                for(int j = 1; j < s.length(); j++){
                    if(temp - j < 0 || temp + j >= s.length() || s[temp - j] != s[temp + j]){
                        break;
                    }
                    else if(s[temp - j] == s[temp + j]) {
                        p[i][j] = p[i][j-1] + 2;
                        maxn[i] = p[i][j];
                    }
                }
            } else {
                int temp1 = i / 2;
                int temp2 = i / 2 + 1;
                for(int j = 1; j < s.length(); j++){
                    if(temp1 < 0 || temp2 < 0 || temp1 >= s.length() || temp2 >= s.length() || s[temp1] != s[temp2]){
                        break;
                    }
                    else if(s[temp1] == s[temp2]) {
                        p[i][j] = p[i][j-1] + 2;
                        maxn[i] = p[i][j];
                        temp1--; temp2++;
                    }
                }
            }
        }
        int result = 1;
        int resultpos = 0;
        for(int i = 0; i < 2 * s.length() - 2; i++){
            if(maxn[i] > result){
                result = maxn[i];
                resultpos = i;
            }
        }
//        for(int i = 0; i < 2*s.length()-2;i++){
//            cout << maxn[i] << "\t";
//        }
//        cout << endl;
        string out;
        if(resultpos % 2 == 0)
            out =  s.substr(resultpos / 2 - result / 2, result);
        else
            out =  s.substr(resultpos / 2 - result / 2 + 1, result);
        cout << result << "\t" << resultpos << "\t" << out;
        return out;
        
    }
    
    void run()
    {
        string s = "cbbd";
        cout << s << endl;
        Solution solution;
        solution.longestPalindrome(s);
        return 0;
    }
};

