#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n, m;
        cin >> n >> m;
        long long mul = 1;
        int zero = 0;
        while(mul <= m) {
            while(n % 10 == 0)
                n /= 10, ++zero;
            if(n % 10 == 5) {
                if(mul * 2 > m)
                    break;
                n *= 2, mul *= 2;
            }
            else if(n % 2 == 0) {
                if(mul * 5 > m)
                    break;
                n *= 5, mul *= 5;
            }
            else {
                if(mul * 10 > m)
                    break;
                n *= 10, mul *= 10;
            }
        }
        for(int i = 0; i < zero; ++i)
            n *= 10;
        for(int i = 9; i >= 1; --i) {
            if(mul * i <= m) {
                n *= i;
                break;
            }
        }
        cout << n << endl;
    }
}