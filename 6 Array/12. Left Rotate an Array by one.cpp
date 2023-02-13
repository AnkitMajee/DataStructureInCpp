#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/********************************************** TC->O(n) SC-> O(1)******************************************************/

int LRotateOne(int arr[],int n){
	int temp=arr[0];
	for(int i=1;i<n;i++){
		arr[i-1]=arr[i];
	
	}
	arr[n-1]=temp;
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
  
  LRotateOne(arr,n);
  
  for(int i=0;i<n;i++){
  	cout<<arr[i]<<" ";
  }
  cout<<endl;

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

