
#include<iostream>
using namespace std;

int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n=nums.size();
    if(n==1) return nums[0];
    vector<int> duplicacy;
    for(int i=0; i<n-1; i++) {
        int x=nums[i]^nums[i+1];
        duplicacy.push_back(x);
        if(x) return nums[i];
        i++;
    }
    return nums[n-1];
}

int main() {
    vector<int> arr={2,2,1};
    int ans= singleNumber(arr);
    cout<<ans;
    return 0;
}
   