#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define int long long int
int countZero(int n){
	int fact=1;
	for(int i=2;i<=n;i++){
		fact=fact*i;
	}
	int res=0;
	while(fact%10==0){
		res++;
		fact=fact/10;
	}
	return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  cout<<countZero(n);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

