//Find the longest common subsequence for the given two string

//input:- S1="ABCDGH" S2="AEDFHR"
//output:- 3

//Explaination:- S1="A__D_H" S2="A_D_H_"
//common sub sequence length is 3 (ADH)


#include <bits/stdc++.h>

using namespace std;


//Normal Resursion Approach
int lcs(string s1,string s2, int m,int n){
	//base case
	if(m==0||n==0){
		return 0;
	}
	//when both last character same
	if(s1[m-1]==s2[n-1]){
		return 1+lcs(s1,s2,m-1,n-1);
	}
	//when last character not same
	else{
		return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
	}
}

// DP approach for Memoization
int lcsMemoization(string s1,string s2, int m,int n){
	vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
	
	//base case
	if(memo[m][n]!=-1){
		return memo[m][n];
	}
	
	//when both last character same
	if(m==0||n==0){
		memo[m][n]=0;
	}
	//when last character not same
	else{
		if(s1[m-1]==s2[n-1]){
			memo[m][n]=1+lcsMemoization(s1,s2,m-1,n-1);
		}else{
			memo[m][n]=max(lcsMemoization(s1,s2,m-1,n),lcsMemoization(s1,s2,m,n-1));
		}
	}
	return memo[m][n];
}

int main() {
  string s1,s2;
  cin>>s1>>s2;
  int m=s1.length(),n=s2.length();
  int res1=lcs(s1,s2,m,n);
  int res2=lcsMemoization(s1,s2,m,n);
  cout<<"Normal Resursion Approach:- "<<res1<<'\n';
  cout<<"DP approach for Memoization:- "<<res2<<'\n';
  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

