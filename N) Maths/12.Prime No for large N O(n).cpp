#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
bool isPrime(int n){
	if(n==1) return false;
	if(n==2|| n==3) return true;
	if(n%2==0|| n%3==0) return false;
	
	for(int i=5;i*i<=n;i+=6){
		if(n%i==0 || n%(i+2)==0)
		return false;
	}
	return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  cout<<isPrime(n);
  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

