/**
 * @class Solution
 * @author bearking
 * @date 05/11/2019
 * @file main.cpp
 * @brief 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        unordered_map<char, int> mymap;
        int length[s.length() + 1] = {1};
        mymap[s[0]] = 0;
        for(int i = 1; i < s.length(); i++){
            if(mymap.find(s[i]) == mymap.end()){
                length[i] = length[i - 1] + 1;
                mymap[s[i]] = i;
            } else{
                int x = mymap.at(s[i]);
                mymap[s[i]] = i;
                if(x >= i - length[i-1]){
                    length[i] = i - x;
                } else{
                    length[i] = length[i-1] + 1;
                }
            }
//            print(length, s.length());
        }
        int max = length[0];
        for(int i = 1; i < s.length(); i++){
            if(length[i] > max){
                max = length[i];
            }
        }
//        cout << max;
        return max;
    }
    
    void run()
    {
        Solution Solution;
        Solution.lengthOfLongestSubstring("abcabcbb");
        return 0;
    }

    
private: 
    void print(int a[], int l){
        for(int i = 0; i < l; i++){
            cout << a[i] << "  ";
        }
        cout << endl;
    }
};


