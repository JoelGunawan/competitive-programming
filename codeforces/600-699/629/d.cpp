#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define ins insert
#define fi first
#define se second
#define mp make_pair
#define lb lower_bound
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll volume[n];
    for(int i = 0; i < n; ++i) {
        int r, h;
        cin >> r >> h;
        volume[i] = 1ll * r * r * h;
    }
    // kita bisa skip cake
    // atau bisa ga skip cake
    // state yang mungkin itu current maximum volume
    // any increasing subsequence is valid
    // fi last volume, se total volume
    set<pair<ll, ll>> x;
    for(int i = 0; i < n; ++i) {
        if(x.size() == 0)
            x.ins(mp(volume[i], volume[i]));
        else {
            if(x.lb(mp(volume[i], 0)) == x.begin()) {
                if((*x.begin()).fi != volume[i])
                    x.ins(mp(volume[i], volume[i]));
                else if((*x.begin()).se < volume[i])
                    x.erase(x.begin()), x.ins(mp(volume[i], volume[i]));
            }
            else {
                ll prev = (*--x.lb(mp(volume[i], 0))).se;
                if((*x.lb(mp(volume[i], 0))).fi == volume[i]) {
                    if((*x.lb(mp(volume[i], 0))).se < prev + volume[i])
                        x.erase(x.lb(mp(volume[i], 0))), x.ins(mp(volume[i], prev + volume[i]));
                }
                else
                    x.ins(mp(volume[i], prev + volume[i]));    
                // try to erase the next
                while(true)
                {
                    auto nxt = x.find(mp(volume[i], prev + volume[i]));
                    ++nxt;
                    if(nxt == x.end() || (*nxt).se > prev + volume[i])
                        break;
                    else
                        x.erase(nxt);
                }
            }
            
        }
    }
    cout << fixed << setprecision(15);
    cout << (long double)atan(1) * 4 * (*--x.end()).se << endl;
    return 0;
}