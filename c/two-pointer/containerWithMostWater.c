/*
Leet 11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/
int maxArea(int* height, int heightSize) {
 int maxArea = 0, currArea;
 int i = 0;
 int j = heightSize-1;
 while(i<j){
    currArea = 0;
    if(height[i]<height[j]){
        currArea = height[i] * (j-i);
        i++;
    }
    else{
        currArea = height[j] * (j-i);
        j--;
    }
    if(currArea>maxArea)
        maxArea = currArea;
 }
 return maxArea;
}
