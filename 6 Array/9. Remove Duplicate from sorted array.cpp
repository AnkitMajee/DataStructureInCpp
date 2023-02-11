#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/********************************************** TC->O(n) SC-> O(n) ******************************************************/
int revDup(int arr[],int n){
	int temp[n];
	temp[0]=arr[0];
	int res=1;
	for(int i=1;i<n;i++){
		if(temp[res-1]!=arr[i]){
			temp[res]=arr[i];
			res++;
		}
	}
	for(int i=0; i<res;i++){
		arr[i]=temp[i];
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
  
  revDup(arr,n);
  
  for(int i=0;i<n;i++){
  	cout<<arr[i]<<" ";
  }
  cout<<endl;

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

