
## [11_container-with-most-water](https://leetcode.com/problems/container-with-most-water/)

**siplified problem statement:**
given the array of height of pole in certain order, find the maximum area that could be possible, base is the distance between those two poles.

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```


```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int currArea = 0, maxArea = 0;
        while(left < right){
            if(height[left] < height[right]){
                currArea = height[left] * (right-left);
                left++;
            }
            else{
                currArea = height[right] * (right-left);
                right--;
            }
            if(maxArea < currArea){
                maxArea = currArea;
            }
        }
        return maxArea;
    }
};
```


