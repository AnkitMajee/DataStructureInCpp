#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int maxDiff(int arr[],int n){
	int res=arr[1]-arr[0];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			res=max(res,(arr[j]-arr[i]));
		}		
	}
	return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  cout<<maxDiff(arr,n);
  return 0;
}





//Goto tools > Editor Option > Snippets >Default Source Code

