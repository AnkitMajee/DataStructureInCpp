#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int countDigit(int n){
	int count=0;
	while(n!=0){
		n=n/10;
		++count;
	}
	return count;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  cout<<countDigit(n);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

