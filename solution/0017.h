/**
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const vector<vector<char>> vec = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> res;
    vector<string> letterCombinations(string digits) {        
        if(digits.size() != 0){
            findCombine(digits, 0, "");
        }
        for(long i = 0; i < res.size(); i++){
            cout << res[i] << "  ";
        }
        return res;
    }
    
    void findCombine(string digits, long index, string s){
        if(index == digits.length()){
            res.push_back(s);
            return ;
        }
        for(int i = 0; i < vec[digits[index]-'0'].size(); i++){
            findCombine(digits, index+1, s+vec[digits[index]-'0'][i]);
        }
    }
    

    
    vector<string> letterCombinations_back(string digits) {
        vector<string> strs;
        long layer = 0;
        vector<long> deep;
        long length = 0;    
        vector<long> a;
        length = digits.size();
        deep.resize(length, 0);
        
        if(digits == "") return strs;
        if(digits.size() == 1){
            int n = digits[0] - '0';
            for(int i = 0; i < vec[n].size(); i++){
                string temp = "";
                strs.push_back(temp + vec[n][i]);
            }
            return strs;
        }
        
        for(long i = 0; i < length; i++){
            a.push_back(digits[i] - '0');
        }
        // 检测 a 是否正确
//        for(long i = 0; i < a.size(); i++){
//            cout << a[i];
//        }
//        cout << endl;        
        
        while(layer >= 0){
//            printf("layer %d  deep[layer] %d  a[layer] %d  deep[length-1] %d\n", layer, deep[layer], a[layer], deep[length-1]);
            if(layer < length && deep[layer] >= vec[a[layer]].size()){
                for(long i = layer; i < length; i++){
                    deep[i] = 0;
                }
                layer--;
                if(layer >= 0)
                    deep[layer]++;
                continue;
            }
            if(layer == length - 1){
                string result_before = "";
                for(long i = 0; i < length-1; i++){
                    result_before += vec[a[i]][deep[i]];
                }
//                cout << result_before <<  "  ";
                for(long i = 0; i < vec[a[layer]].size(); i++){
//                    cout << result_before + vec[a[layer]][i] << "  ";
                    strs.push_back(result_before + vec[a[layer]][i]);
                }
//                cout << endl;
                layer--;
                if(layer >= 0)
                    deep[layer]++;
                
                continue;
            }
            layer++;
        }
//        for(long i = 0; i < strs.size(); i++){
//            cout << strs[i] << "  ";
//        }
        return strs;
    }
    void run()
    {
        Solution solution;
        solution.letterCombinations("23");
        return 0;
    }

};

