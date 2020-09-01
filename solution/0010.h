/**
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 动态规划
    bool isMatch(string s, string p) {
        int m = s.length() + 1;
        int n = p.length() + 1;
        bool dp[100][100] = {{false, false}};
        
        dp[0][0] = true;
        // 偶数位判断是不是 *
        for(int j = 2; j < n; j = j + 2){
            dp[0][j] = dp[0][j - 2] && p[j-1] == '*';
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }
        return dp[m-1][n-1];
    }
    
    void  run() {
        Solution solution;
        cout << solution.isMatch("mississippi", "mis*is*p*.");
        return 0;
    }
};


