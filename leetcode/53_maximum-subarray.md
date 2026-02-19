## [53_maximum-subarray](https://leetcode.com/problems/maximum-subarray/description/)

**simplified problem statemet:**
given an integer array, find the subarray with the subarray with the largest sum

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0, maxSum=-10000, n=nums.size();

        for(int i=0; i<n; i++) {
            currSum+=nums[i];

            maxSum=max(maxSum, currSum);
            if(currSum<0) currSum=0;
        }
        return maxSum;
    }
};
```
