## [136_single-number](https://leetcode.com/problems/single-number/description/)

**simplified problem statement:**
given and non empty array, find the single number whose duplicate does not exist

```
Input: nums = [2,2,1]
Output: 1
```

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> duplicacy;
        for(int i=0; i<n-1; i++) {
            int x=nums[i]^nums[i+1];
            duplicacy.push_back(x);
            if(x) return nums[i];
            i++;
        }
        return nums[n-1];
    }
};
```