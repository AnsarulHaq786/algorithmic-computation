#include<iostream>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n=arr.size();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]<arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

int main() {
    vector<int> arr={4, 5, 3, 1, 2};
    bubbleSort(arr);
    for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
}