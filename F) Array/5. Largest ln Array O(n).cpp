#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int getLargest(int arr[],int n){
	int res=0;
	for(int i=1;i<n;i++)
	if(arr[i]>arr[res])
	res=i;
	
	return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int arr[]={5,6,3,2,3};
  cout<<getLargest(arr,5);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

