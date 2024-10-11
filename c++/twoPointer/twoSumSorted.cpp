/*
Modified LeetCode 1. Two Sum Sorted
Given an sorted array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1, sum=0;
        vector<int> ans;
        while(i<j){
            sum=nums[i]+nums[j];
            if(sum==target)
                return {i,j};
            else if(sum>target)
                j--;
            else
                i++;
        }
        return {};
    }
};
