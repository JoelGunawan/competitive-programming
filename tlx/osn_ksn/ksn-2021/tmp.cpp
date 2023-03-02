#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check_prime(int n) {
    bool is_prime = true;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            is_prime = false;
        }
    }
    return is_prime;
}
const int lim = 1e5 + 5;
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int fh(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
};
void tc(int n) {
    if(n < 1) {
        cout << "Input Tidak Sesuai" << endl;
        return;
    }
    // vector<int> primes;
    // int cur = 2;
    // {3, 2, 4, 1} -> 4
    // {2, 3, 5, 7, 11} -> 5
    /*
    while(primes.size() < n) {
    bool is_prime = true;
    // for i in primes
    for(auto i : primes) {
        if(cur % i == 0)
            is_prime = false;
    }
    if(is_prime)
        primes.push_back(cur);
    ++cur;
    }
    cout << primes.back() << endl;
    */
    int cur = 1, found_primes = 0;
    while(found_primes < n) {
        if(check_prime(++cur))
            ++found_primes;
    }
    cout << cur << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i <= 1000; ++i)
        tc(i);
}