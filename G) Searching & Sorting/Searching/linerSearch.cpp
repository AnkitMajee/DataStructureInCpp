//Code for linear search to find is a element is in array or not.

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int size, int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;
    cout<<"Enter Size of Array:";
    cin>>size;

    vector<int> arr;
    cout<<"Enter element of Array:";
    for (int i=0;i<size;i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }

    int target;
    cout<<"Enter the Target element:";
    cin>>target;

    int result = linearSearch(arr, size, target);
    if(result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found!" << endl;
    }

    return 0;
}