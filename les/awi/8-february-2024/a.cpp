#include <bits/stdc++.h>
using namespace std;
int f(int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    return f(l, mid) + f(mid + 1, r);
}
int main() {
    cout << f(2000, 2024) << endl;
    int sum = 0;
    for(int i = 2000; i <= 2024; ++i)
        sum += i;
    cout << sum << endl;
}