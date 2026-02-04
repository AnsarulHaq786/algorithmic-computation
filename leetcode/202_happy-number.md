## [202_happy-number](https://leetcode.com/problems/happy-number/description/)

**simple problem statememt**
given an integer number, the number is happy if,
- sum of each digit of number equals 1, with any number of repeated cycle
- else it is not happy

```
Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
``` 


```cpp
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && seen.find(n)==seen.end()  {
            seen.insert(n);
            int sqSum=0;
            while(n>0) {
                int ext=n%10;
                sqSum+=ext*ext;
                n/=10;
            }
            n=sqSum;
        }
        return n==1;
    }
};
```