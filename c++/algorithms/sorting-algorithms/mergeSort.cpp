#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int i=l, j=m+1;
    vector<int> temp;
    while(i<=m && j<=r) {
        if(arr[i]<arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } 
        else {
            temp.push_back(arr[j]);
            j++;
        } 
    }
    while (i<=m)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j<=r)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0; idx<temp.size(); idx++) {
        arr[idx+l] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m=(l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main() {
    vector<int> a={3, 5, 3, 2, 7, 9, 1, 11, 4};
    int length=a.size(), l=0, r=length-1;
    mergeSort(a, l, r);
    for (int i=0; i<length; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}