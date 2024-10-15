// Leet Code 1: Two Sum
// one pass unordered hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int cmp;
        for(int i=0; i<nums.size(); i++){
            cmp = target - nums[i];
            if(map.count(cmp)){
                return {map[cmp], i};
                break;
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
