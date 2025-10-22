
## [1089_duplicate-zeros](https://leetcoede.com/duplicate-zeros)

**siplified problem statement:**
given a fixed length integer array,
duplicate each occurrence of zero,
shifting the remaining elemenst to the right

```
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
```


```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int length=arr.size();
        for(int i=0; i<length; i++) {
            if(!arr[i]) {
                for(int j=length-1; j>i; j--) {
                    arr[j]=arr[j-1];
                }
                i++;
            }
        }
    }
};
```