## [239_sliding-window-maximum](https://leetcode.com/problems/sliding-window-maximum/description/)

**simplified problem statement**
find maximum element from the widow size k, and slide window by 1

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

```cpp
class Solution {
    public:
    vector<int> slidingWindowMaximum(vector<int> nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i<num.size(); i++) {
            // remove element out of window
            if(!dq.empty() && dq.front()==i-k)
                dq.pop_front();
            
            // remove smaller element
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            
            // add element
            dq.push_back(nums[i]);
            
            // skip k elements first
            // store result
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
}
```