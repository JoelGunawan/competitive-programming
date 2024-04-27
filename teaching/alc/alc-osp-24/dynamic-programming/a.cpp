#include <bits/stdc++.h>
using namespace std;
// kompleksitas f(n) adalah O(2^N) -> O(N)
int memo[100005];
int f(int n) {
    // kalo memo sudah diisi, langsung pakai nilai dri memonya
    if(memo[n] != -1)
        return memo[n];

    if(n == 1 || n == 2) {
        memo[n] = 1;
        return memo[n];
    }
    else {
        memo[n] = f(n - 1) + f(n - 2);
        return memo[n];
    }
}
int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    cout << f(n) << endl;
}