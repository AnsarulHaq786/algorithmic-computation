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
    selectionSort(arr, 7);
    for (int i=0; i<7; i++)
        cout<<arr[i]<<" ";
    return 0;
}