#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int getlargest(int arr[],int n){
	for(int i=0;i<n;i++){
		bool flag=true;
		for(int j=0;j<n;j++){
			if(arr[j]>arr[i]){
				flag=false;
				break;
			}
		}
		if(flag==true)
		return i;
	}
	return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int arr[]={5,6,3,2,3};
  cout<<getlargest(arr,5);
  

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

