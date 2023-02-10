#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

// TC O(n^2)

bool isSorted(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
	if(arr[j]<arr[i])
	return false;
	}
	return true;
	
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int arr[]={4,7,8,9};
  cout<<isSorted(arr,4);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

