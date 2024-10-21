//You are given an array b of size n and an integer d. 
//For each integer value vl in the range [-10,000, 10,000], the function check(vl, b, n, d)
//calculates the total adjustment cost of transforming all elements in the array to the value vl.
//The adjustment cost is defined as twice the sum of the absolute differences between each element of b and vl.

//The function returns true if the total cost is less than or equal to d, and false otherwise. 
//Your task is to determine how many valid values of vl satisfy this condition.

//Input:
//The first line contains two integers n (the size of the array) and d (the maximum allowable cost).
//The second line contains n integers, the elements of the array b.
//Output:
//Output a single integer, the count of valid values of vl in the range [-10,000, 10,000] such that the total cost of transforming the array to vl does not exceed d.



#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 1000;
 
int n, d;
int b[MAX_N];
 
bool check(int vl, int b[], int n, int d) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        cost += std::abs(b[i] - vl);
    }
 
    cost *= 2;
    if (cost <= d) {
        return true;
    }
    return false; 
}
 
int main() {
    int low = -1e4;
    int high = 1e4;
    int count = 0;
 
    int n, d;
    cin>>n>>d;
 
    for(int i=0;i<n;i++){
 
    	cin>>b[i];
 
    }
 
    // Assuming you've set n, d, and filled the array b[n] somewhere before this point
 
    for (int i = low; i <= high; i++) {
        if (check(i, b, n, d)) {
            count++;
        }
    }
 
    cout << count << std::endl;
 
    return 0;
}
