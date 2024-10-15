#include<iostream>

using namespace std;

// Problem Statement: 
// Given int x return the sqaure root of the integer as integer

int SquareRoot(int x){
    int ans = 0, l = 0, h = x;
    while (l<=h){
        int mid = (h+l)/2;
        if (mid*mid<=x){
            ans = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return ans;
}

int main(){
    cout<<SquareRoot(4)<<endl;//Prints 2
    cout<<SquareRoot(9)<<endl;//Prints 3
    cout<<SquareRoot(16)<<endl;//Prints 4
}