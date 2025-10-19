## [1_two-sum](https://leetcode.com/problems/two-sum/)

**siplified problem statement:**
given an integer array,
return the two indices that sums to the target

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```


```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int cmp;
        for(int i=0; i<nums.size(); i++){
            cmp = target - nums[i];
            if(map.count(cmp)){
                return {map[cmp], i};
                break;
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
```