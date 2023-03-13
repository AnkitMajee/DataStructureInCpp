#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/********************************************** TC->O(n^2)******************************************************/


int leader(int arr[],int n){
	for(int i=0;i<n;i++){
		bool flag=false;
		for(int j=i+1;j<n;j++){
			if(arr[i]<=arr[j]){
				flag =true;
				break;
			}
		}
		if(flag==false){
			cout<<arr[i]<<" ";
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

