/*
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
 * 找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long result = INT_MAX;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l, r;
        for(int i = 0; i < n; i++){
            l = i + 1; r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    return target;
                } 
                if(abs(result - target) > abs(sum - target)){
                    result = sum;
                }
                if(sum > target){
                    r--;
                } else {
                    l++;
                }
            }
        }
        return result;
    }
    
    void run()
    {
        int target =  1;
        vector<int> nums = {-1, 2, 1, -4};
        Solution solution;
        cout << solution.threeSumClosest(nums, target);
        return 0;
    }
};



