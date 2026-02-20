## [169_majority-element](https://leetcode.com/problems/majority-element/description/)

**simplified problem statement**

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elements;
        int n=nums.size();

        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)  elements[nums[i]]++;

        auto it=elements.begin();

        for(const auto& ele: elements) {
            if(ele.second>n/2) return ele.first;
        }

        return -1;
    }
};
```