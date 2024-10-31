#include<iostream>
using namespace std;


void quicksort(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = arr[start]; 
    int left = start + 1;
    int right = end;

    while (left <= right) {
        while (left <= end && arr[left] <= pivot) {
            left++;
        }

        while (right > start && arr[right] >= pivot) {
            right--;
        }
        
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }


    swap(arr[start], arr[right]);
    
    quicksort(arr, start, right - 1);
    quicksort(arr, right + 1, end);
}


int main(){
    int arr[] = {1,3,2,54,4};
    int n=5;
    quicksort(arr,0,n);
    for(auto x:arr) cout<<x<<" ";
    return 0;
}
