## [560_subarray-sum-equals-k](https://leetcode.com/problems/subarray-sum-equals-k/)

**simplified problem statement**
given an sorted integer array, find the total no. of subarray whose sum is equal to k.

```
Input: nums = [1,2,3], k = 3
Output: 2
```

```cpp
class Solution {
public:
    int subarraySum(Vector<int>&nums, int k) {
        int n=nums.size();
        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1; i<n; i++) {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        int count=0;
        for(int i=0; i<n; i++) {
            if(prefixSum[i]==k) count++;
            int j=0;
            while(j<i) {
                if(prefixSum[i]-prefixSum[j]==) count++;
                j++;
            }
        }
        return count;
    }
}
```