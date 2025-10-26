#include <iostream>
#include <vector>
using namespace std;

// Function to find the smallest missing element using binary search
int findSmallestMissingElement(const vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return start;
    }

    int mid = start + (end - start) / 2;

    // Check if the mid element is equal to its index
    if (arr[mid] == mid)
    {
        // Search in the right half
        return findSmallestMissingElement(arr, mid + 1, end);
    }
    else
    {
        // Search in the left half
        return findSmallestMissingElement(arr, start, mid - 1);
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 6, 9, 11, 15};
    int n = arr.size();

    int smallestMissing = findSmallestMissingElement(arr, 0, n - 1);
    cout << "The smallest missing element is: " << smallestMissing << endl;

    return 0;
}