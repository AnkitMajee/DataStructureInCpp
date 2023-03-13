#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int leader(int arr[],int n){
	int curr_ldr=arr[n-1];
	cout<<curr_ldr<<" ";
	for(int i=n-1;i>0;i--){
		if(curr_ldr<arr[i]){
			curr_ldr=arr[i];
			cout<<curr_ldr<<" ";
		}
	}
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
  
  leader(arr,n);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

