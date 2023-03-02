#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int lcm(int a,int b){
	int res=max(a,b);
	while(true){
		if(res%a==0 && res%b==0) return res;
		res++;
	}
	return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b;
  cin>>a>>b;
  cout<<lcm(a,b);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

