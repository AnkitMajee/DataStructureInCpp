#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
// tc O(log n) and Space Complexity is O(log n)
int power(int x,int n){
	if(n==0) return 1;
	int temp =power(x,n/2);
	
	temp=temp*temp;
	if(n%2 ==0) return temp;
	else return temp*x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b;
  cin>>a>>b;
  cout<<power(a,b);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

