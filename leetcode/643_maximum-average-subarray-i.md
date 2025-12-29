## [643_maximum-average-subarray-i](https://leetcode.com/problems/maximum-average-subarray-i/description/)

**simplified problem statement:**
given an integer array,
find the maximum sum contagious sub-array of length k

```
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
```


```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0; i<k; i++) {
            sum+=nums[i];
        }
        int j=0;
        double maxSum=sum;
        while(j!=nums.size()-k) {
            sum=sum-nums[j]+nums[k+j];
            maxSum=max(sum, maxSum);
            j++;
        }
        return maxSum/k;
    }
};
```