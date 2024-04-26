#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++cnt[x];
        }
        // kemunculan 0 pertama
        // kemunculan 1 kedua
        int zero = n, first = n;
        int kemunculan1 = 0;
        for(int i = 0; i < n; ++i) {
            if(cnt[i] == 0) {
                zero = min(zero, i);
            }
            else if(cnt[i] == 1) {
                ++kemunculan1;
                if(kemunculan1 == 2) {
                    first = i;
                }
            }
        }
        //cout << zero << " " << first << endl;
        cout << min(zero, first) << endl;
    }
}