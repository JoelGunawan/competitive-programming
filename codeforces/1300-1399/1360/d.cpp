#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int cur = 1;
        for(int i = 1; i <= sqrt(n); ++i) {
            if(n % i == 0) {
                if(i > cur && i <= k)
                    cur = i;
                if(n / i > cur && n / i <= k)
                    cur = n / i;
            }
        }
        cout << n / cur << endl;
    }
    return 0;
}