#[88_merge-sorted-array](https://leetcode.com/problems/merge-sorted-array/description/)

**simplified problem statement**

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, idx=m+n-1;

        while(j>=0) {
            if(i>=0 && nums1[i]>nums2[j]) {
                nums1[idx]=nums1[i];
                idx--; i--;
            }
            else {
                nums1[idx]=nums2[j];
                idx--; j--;
            }
        }
    }
};
```