#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
bool isPrime(int n){
	if(n==1) return false;
	
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
		return false;
	}
	return true;
}
int printPrime(int n){
	for(int i=2;i<=n;i++){
		if(isPrime(i))
		cout<<i<<" ";
	}
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  printPrime(n);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

