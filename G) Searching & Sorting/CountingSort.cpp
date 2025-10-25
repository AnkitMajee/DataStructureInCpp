#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> &arr) {
    int n = arr.size();
    if(n == 0) return;

    int maxVal = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > maxVal) maxVal = arr[i];

    vector<int> count(maxVal + 1, 0);

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for(int i = 0; i <= maxVal; i++)
        while(count[i]-- > 0)
            arr[index++] = i;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);

    for(int i : arr)
        cout << i << " ";
    return 0;
}
