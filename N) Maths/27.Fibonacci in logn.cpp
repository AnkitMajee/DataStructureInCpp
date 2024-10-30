// Question Explanation:
// The task is to calculate the nth Fibonacci number efficiently, where n can be very large (up to 10^18).
// Since the sequence grows exponentially, a naive approach would be inefficient.
// We'll use matrix exponentiation to compute this in logarithmic time (O(log n)), 
// as matrix exponentiation allows us to calculate the nth term in the Fibonacci sequence quickly.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e9 + 7;

// Utility functions
int binExp(int a, int b, int mod = M, int ans = 1) {
    for (; b; b >>= 1, a = 1LL * a * a % mod)
        if (b & 1) ans = 1LL * a * ans % mod;
    return ans;
}

ll mod_add(ll a, ll b, ll m = M) {
    return (a % m + b % m) % m;
}

ll mod_sub(ll a, ll b, ll m = M) {
    return ((a % m - b % m) + m) % m;
}

ll mod_mul(ll a, ll b, ll m = M) {
    return ((a % m) * (b % m)) % m;
}

ll mod_inv(ll a, ll m = M) {
    return binExp(a, m - 2, m);
}

ll mod_div(ll a, ll b, ll m = M) {
    return mod_mul(a, mod_inv(b, m), m);
}

using vll = vector<ll>;
using vlll = vector<vll>;

// Matrix class for matrix exponentiation
class Matrix {
public:
    vlll vec;
    Matrix() {
        vec = vlll(2, vll(2));
    }
    
    Matrix operator *(Matrix &mat) {
        Matrix matans;
        for (ll i = 0; i < 2; i++) {
            for (ll j = 0; j < 2; j++) {
                ll sum = 0;
                for (ll k = 0; k < 2; k++) {
                    sum = mod_add(sum, mod_mul((this->vec[i][k]), (mat.vec[k][j])));
                }
                matans.vec[i][j] = sum;
            }
        }
        return matans;
    }
};

// Function to calculate the nth Fibonacci number using matrix exponentiation
ll ans(ll n) {
    Matrix mat;
    mat.vec = {{1, 1}, {1, 0}};
    Matrix result;
    result.vec = {{1, 0}, {0, 1}}; // Identity matrix

    while (n > 0) {
        if (n & 1) result = result * mat;
        mat = mat * mat;
        n >>= 1;
    }
    return result.vec[0][1];
}

// Solution function
void solve() {
    ll n;
    cin >> n;
    cout << ans(n) << endl;
}

// Main function
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
