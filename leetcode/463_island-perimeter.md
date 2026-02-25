## [463_island-perimeter](https://leetcode.com/problems/island-perimeter/description/)

**simplified problem statement:**
given n*m grid,
there is land(1), water(0).
find out the perimenter of land if, land is island.

```
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
```

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int count=0;

        for(int i=0; i<rows; i++) {
            int cols = grid[i].size();
            for(int j=0; j<cols; j++) {

                if(grid[i][j]) {
                    count+=4;
                    if(j>0 && grid[i][j-1]) count-=2;
                    if(i>0 && grid[i-1][j]) count-=2;
                }
            }
        }
        return count;
    }
};
```