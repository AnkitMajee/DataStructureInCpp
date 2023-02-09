#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int search(int arr[],int n,int x){
	for(int i=0;i<n;i++){
		if(arr[i]==x)
		return i;
	}
	return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int arr[]={5,6,7,8};
  cout<<search(arr,4,7);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

