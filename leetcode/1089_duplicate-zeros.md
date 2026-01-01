
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

**brute force**
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

**two pointer**
```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        vector<int> newArr(n);
        
        int i=0, j=0;
        while(j<n) {
            newArr[j++]=arr[i];
            if(arr[i]==0 && j<n) newArr[j++]=0;
            i++;
        }
        for(int i=0; i<n; i++) arr[i]=newArr[i];
        
    }
};
```