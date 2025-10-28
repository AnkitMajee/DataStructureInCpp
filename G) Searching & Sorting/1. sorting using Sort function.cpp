#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[] = {10, 20, 30, 5, 7};

  sort(arr, arr + 5);

  for (int x : arr)
    cout << x << " ";
  sort(arr, arr + 5, greater<int>());
  cout << endl;

  for (int x : arr)
    cout << x << " ";

  return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code