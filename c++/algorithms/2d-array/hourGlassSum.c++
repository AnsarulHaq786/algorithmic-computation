#include <iostream>
#include <vector>
using namespace std;

int main()
{    
    vector<vector<int>> arr={{-1,-1,0,-9,-2,-2},{-2,-1,-6,-8,-2,-5},{-1,-1,-1,-2,-3,-4},{-1,-9,-2,-4,-4,-5},{-7,-3,-3,-2,-9,-9},{-1,-3,-1,-2,-4,-5}};
    int maxSum=-63;
    for(int l=0; l<4; l++) {
        for(int k=0; k<4; k++) {
            int currSum=0;
            for(int i=l; i<l+3; i++) {
                for(int j=k; j<k+3; j++) {
                    if(i==l+1 && j!=k+1){
                        continue;
                    }
                    currSum=currSum+arr[i][j];
                }
            }
            maxSum=max(maxSum,currSum);
        }
    }
    cout<<maxSum;
    return 0;
}