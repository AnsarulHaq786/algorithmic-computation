## [303_range_sum_query_immutable](https://leetcode.com/problems/range-sum-query-immutable)

**simplified problem statement**
given an integer array,
for a given range of index calulate the commulative sum for many such case

```
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]
```

```cpp
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
```