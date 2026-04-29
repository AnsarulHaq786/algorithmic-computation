#[42_trapping-rain-water](https://leetcode.com/problems/trapping-rain-water/)

**simplified problem statement:**
given list of numbers are hight of block with the width of 1 unit, compute how much unit of water it can trap

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

** optimal solution
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
        
        for(int i=1; i<n; i++) {
            leftMax[i]=max(leftMax[i-1], height[i]);
        }
        
        for(int i=n-2; i>=0; i--) {
            rightMax[i]=max(rightMax[i+1], height[i]);
        }
        
        int ans=0;
        for(int i=0; i<n; i++) {
            ans+=min(leftMax[i], rightMax[i])-height[i];
        }
        
        return ans;
    }
};
```

** two pointer approach
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lmax=0, rmax=0;
        int l=0, r=n-1;
        int ans=0;
        
        while(l<r) {
            lmax=max(lmax, height[l]);
            rmax=max(rmax, height[r]);
        
            if(lmax<rmax) {
                ans+=lmax-height[l];
                l++;
            }
            else {
                ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};
```