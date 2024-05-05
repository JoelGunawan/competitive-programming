#include <bits/stdc++.h>
using namespace std;
long long fpb(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return fpb(b, a % b);
}
int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long kpk = a * b / fpb(a, b);
    cout << kpk / a + kpk / b << endl;
}