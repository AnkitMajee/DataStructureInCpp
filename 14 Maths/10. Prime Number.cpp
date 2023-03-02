#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
bool isPrime(int n){
	if(n==1)  return false;
	
	for(int i=2;i<n;i++){
		if(n%i==0) return false;
	}
	
return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin>>n;
  cout<<isPrime(n);
return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

