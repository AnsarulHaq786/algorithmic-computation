#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int i=low-1, j;
    int pivot=arr[high];
    for(j=low; j<high; j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[],int low, int high) {
    if(low<high) {
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int arr[] = {5, 3, 2, 6, 4, 1, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
