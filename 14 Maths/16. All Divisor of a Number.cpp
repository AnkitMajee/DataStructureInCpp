#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

// TC-> 0(n)

int printDivisor(int n){
	for(int i=1;i<n;i++)
	if(n%i ==0){
		cout<<i<<" ";
	}
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  cout<<printDivisor(n);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

