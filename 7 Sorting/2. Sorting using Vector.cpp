#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  vector<int> v={50,27,19,90,30};
  sort(v.begin(),v.end());
  for(int x:v){
  	cout<<x<<" ";
  }
  cout<<endl;
  sort(v.begin(),v.end(),greater<int>());
  for(int x:v){
  	cout<<x<<" ";
  }

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code
