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
