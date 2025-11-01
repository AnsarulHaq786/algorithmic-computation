
## [525_contiguous_array](https://leetcode.com/problems/contiguous-array/description/)

**simplified problem statement:**
given a binary array, return the maximum length of a contiguos subarray with an equal number of 0 and 1.

```
Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
```

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, n = nums.size();
        map<int, int>hashMap;
        hashMap[0] = -1;
        int currSum = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                currSum--;
            }
            else if(nums[i]==1){
                currSum++;
            }
            if(hashMap.find(currSum)!=hashMap.end()){
                int thatIndex = hashMap[currSum];
                result = max(result, i-thatIndex);
            }
            else{
                hashMap[currSum] = i;
            }
        }
        return result;
    }
};
```