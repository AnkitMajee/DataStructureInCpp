#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int countDigit(long n){
	if(n==0)
		return 0;	
	return 1+countDigit(n/10);
	
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long n;
  cin>>n;
  cout<<countDigit(n);
  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

