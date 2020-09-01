/**
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:           
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        if(nums.empty() || nums.size() < 3) return result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l, r;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) return result;
            if(i != 0 && nums[i] == nums[i-1]) continue;
            l = i + 1; r = n - 1;
            while(l < r){
                int temp = nums[i] + nums[l] + nums[r];
                if(temp == 0){
                    vector<int> op = {nums[i], nums[l], nums[r]};
                    result.push_back(op);
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++; r--;
                } else if(temp > 0){
                    r--;
                } else{
                    l++;
                }
            }
        }
        return result;
    }
    
    void run()
    {
        Solution solution;
        vector<int> sum = {0,0,0};
        vector<vector<int>> result_end = solution.threeSum(sum);
        for(int i = 0; i < result_end.size(); i++){
            printf("%d  %d  %d\n", result_end[i][0], result_end[i][1], result_end[i][2]);
        }
        return 0;
    }

};


