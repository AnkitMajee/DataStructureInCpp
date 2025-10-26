#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxNO = 0;
    for (int i = 0; i < n; i++)
    {
        maxNO = max(maxNO, arr[i]);
    }

    cout << maxNO << endl;

    return 0;
}