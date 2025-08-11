#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex=i;
        for (int j=i+1; j<n; j++) {
            if (arr[j]<arr[minIndex]) {
                minIndex=j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[7]={5, 10, 3, 12, 88, 1, 11};
    int length=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, length);
    for (int i=0; i<length; i++)
        cout<<arr[i]<<" ";
    return 0;
}