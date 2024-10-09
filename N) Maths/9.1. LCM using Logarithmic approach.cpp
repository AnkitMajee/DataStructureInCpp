#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

//TC -> 0(log(min(a,b)))

int gcd(int a,int b){               // 0(log(min(a,b)))
	while(a!=b){
		if(a>b) a=a-b;
		else b=b-a;
	}
	return a;
}

int lcm (int a,int b){                // 0(1)
	return (a*b)/gcd(a,b);
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

