#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int deleteEle(int arr[],int n,int x){
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==x)
		break;
	}
	if(i==n)
	return n;
	
	for(int j=i;j<n-1;j++)
	arr[j]=arr[j+1];
	
	return (n-1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,x;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  cin>>x;
  for(int i=0;i<n;i++){
  	cout<<deleteEle(arr,n,x);
  }
  

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

