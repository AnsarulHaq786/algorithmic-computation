/*
Leet Code 303. Range Sum Query - Immutable
Given an integer array nums, handle multiple queries of the following type:

1. Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the NumArray class:
    -NumArray(int[] nums) Initializes the object with the integer array nums.

    -int sumRange(int left, int right)Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

class NumArray {
vector<int> a;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        a.push_back(nums[0]);
        for(int i=1; i<n; i++){
            a.push_back(nums[i] + a[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        int sum;
        if(left==0)
            sum = a[right];
        else
            sum = a[right]-a[left-1];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */