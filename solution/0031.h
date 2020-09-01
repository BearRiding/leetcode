//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
//如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
//必须原地修改，只允许使用额外常数空间。
//
//以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1

#ifdef t0031

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        findNext(nums, nums.size(), nums.size()-2);
        return;
    }
    
    void findNext(vector<int>& nums, int total, int current){
        // 如果还是倒序，继续递归
        if(nums[current] >= nums[current+1]){
            // 如果已经到了最头上了，则直接返回
            if(current == 0){
                sort(nums.begin(), nums.end());
                return;
            }
            else{
                return findNext(nums, total, current-1);
            } 
        } 
        // 否则寻找该串下的下一个排序
        else{
            int cmin = nums[current+1];
            int nmin = current + 1;
            for(int i = current+2; i < total; i++){
                if(nums[i] > nums[current] && cmin > nums[i]){
                    cmin = nums[i];
                    nmin = i;
                }
            }
            nums[nmin] = nums[current];
            nums[current] = cmin;
            sort(nums.begin()+current+1, nums.end());
        }
    }
    
    void print(vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << "  ";
        }
        cout << endl;
    }
    
    void run(){
        vector<int> nums = {5,1,1};
        nextPermutation(nums);
        print(nums);
    }
};

#endif