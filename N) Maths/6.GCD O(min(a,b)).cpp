#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

// TC-> 0(min(a,b))
int gcd(int a,int b){
	int res=min(a,b);
	while(res>0){
		if(a%res==0 && b%res==0){
			break;
		}
		res--;
	}
	return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b;
  cin>>a>>b;
  cout<<gcd(a,b);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

