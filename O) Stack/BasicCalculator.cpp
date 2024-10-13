#include<iostream>
#include<stack>
#include<vector>
#include<string.h>

using namespace std;

// Problem Statement:
// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:
// Input: s = "1 + 1"
// Output: 2

// Example 2:
// Input: s = " 2-1 + 2 "
// Output: 3

// Example 3:
// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23

string solve(string s, int &index, int len){
    stack<string> st;
    string num = "";
    char x;
    for (int i= index; i < len; i++){
        x = s[i];
        num = "";
        if (x == ' '){
            continue;
        }
        if ((x-48)>=0 && (x-48)<=9){
            while((x-48)>=0 && (x-48)<=9 && i<len){
                num.push_back(x);
                i++;
                x = s[i];
            }
            i--;
            x = s[i];
        }
        else if (x == '+' || x == '-'){
            if (st.empty()){
                st.push("0");
            }
            num.push_back(x);
            st.push(num);
            continue;
        }
        if (x == '('){
            index = i + 1;
            num = solve(s, index, len);
            i = index;
        }
        else if (x == ')'){
            index = i;
            return st.top();
        }
        if (!st.empty()){
            if (st.top() == "+"){
                st.pop();
                int a = std::stoi(st.top());
                int b = std::stoi(num);
                int temp = a + b;
                st.pop();
                st.push(to_string(temp));
            }
            else if (st.top() == "-"){
                st.pop();
                int a = std::stoi(st.top());
                st.pop();
                int temp = a - std::stoi(num);
                st.push(to_string(temp));
            }
        }
        else {
            st.push(num);
        }
    }
    return st.top();
}
int calculate(string s) {
    int index = 0;
    return std::stoi(solve(s, index, s.length()));
}

int main(){
    // Example 1: 
    string s = "1 + 1";
    cout<<calculate(s)<<endl;
    s = " 2-1 + 2 ";
    cout<<calculate(s)<<endl;
    s = "(1+(4+5+2)-3)+(6+8)";
    cout<<calculate(s)<<endl;
}