/* 

Question

Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

Note: You can assume both the strings s1 & s2 are non-empty.

Constraints:
1 ≤ |s1.size()|,|s2.size()| ≤ 105

Input: s1 = "listen", s2 = "silent"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.

Input: s1 = "allergy", s2 = "allergic"
Output: false
Explanation: Characters in both the strings are not same, so they are not anagrams. .*


#include<iostream>
using namespace std;


bool isAnagram(string& s1, string& s2) {

        // Your code here
        unordered_map <char,int> ump1;
        unordered_map <char,int> ump2;
        
        for(auto c1 : s1)
            ump1[c1]++;
        for (auto c2 : s2 )
            ump2[c2]++;
        if(ump1==ump2)
            return true;
        return false;
        
    }


int main()
{
	string s1, s2;
	cout<<"Enter two strings s1 and s2";
	cin>>s1>>s2;
	bool ans = isAnagram (s1,s2);
	if(ans==true)
		cout<<"The entered two strings are anagrams";
	else
		cout<<"The entered two strings are not anagrams";
	return 0;
}
	