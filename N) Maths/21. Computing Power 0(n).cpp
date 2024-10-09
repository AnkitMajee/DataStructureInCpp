#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int power(int x,int y){
	int res=1;
	for(int i=0;i<y;i++)
	res=res*x;
return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x,n;
  cin>>x>>n;
  cout<<power(x,n);

return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

