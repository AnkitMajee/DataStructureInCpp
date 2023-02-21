#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define int long long int
int fact(int n){
	int res=1;
	for(int i=2;i<=n;i++){
		res=res*i;
	}
	return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  cout<<fact(n);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

