#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int reverse(int arr[],int low,int high){
	while(low<high){
		swap(arr[low],arr[high]);
		low++;
		high--;
	}
}
int LRotateOne(int arr[],int n,int d){
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,d;
  cin>>n>>d;
  int arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  
  LRotateOne(arr,n,d);
  
  for(int i=0;i<n;i++){
  	cout<<arr[i]<<" ";
  }
  cout<<endl;

  return 0;
}
/*
input
5 2
1 2 3 4 5

output
3 4 5 2 1

After 1st Reversal 
arr=[2 1 3 4 5]    reverse upto d place
After 2nd Reversal
arr=[2 1 5 4 3]    reverse after d place
After 3rd Reversal
arr=[3 4 5 2 1]    reverse whole arr

*/,





//Goto tools > Editor Option > Snippets >Default Source Code

