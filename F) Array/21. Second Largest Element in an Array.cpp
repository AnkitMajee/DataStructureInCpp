#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int arr[], int n)
{
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main()
{
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int secondLargest = findSecondLargest(arr, n);

    if (secondLargest == INT_MIN)
    {
        cout << "No second largest element exists." << endl;
    }
    else
    {
        cout << "Second largest element is: " << secondLargest << endl;
    }

    return 0;
}