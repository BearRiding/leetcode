//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) return 0;
        if(nums[0] > target) return 0;
        if(nums[size-1] < target) return size;
        
        int result = findOne(nums, 0, size-1, target);
        return result;
    }
    
    int findOne(vector<int>& nums, int down, int up, int target){
        int middle = (up + down) / 2;
        if(nums[middle] == target){
            return middle;
        } 
        if(down == up) return down;
        
        if(nums[middle] < target) 
            return findOne(nums, middle + 1, up, target);
        else 
            return findOne(nums, down, up -1, target);
    }
    
    void run(){
        vector<int> vec = {1,3,5,6};
        int result = searchInsert(vec, 7);
        cout << result << endl << "454";
    }
};
