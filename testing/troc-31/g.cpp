#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll addAll(ll A, ll B) {
    ll X = (B - A + 1) / 2;
    ll Y = (A+B)*X;
    return Y;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--) {
        ll N;
        cin >> N;
        if(N == 2) {
            cout << 1 << " " << 3 << endl;
        }
        else if(N == 3) {
            cout << "3 6 7" << endl;
        }
        else if(N == 4) {
            cout << "4 5 7 9" << endl;
        }
        else if(N % 2 == 1){
            ll gap = N+2;
            ll gap2 = gap*gap;
            ll average = gap2 / N;
            ll modgap2 = (gap2 % N) + 2;
            if(modgap2 > N) {
                modgap2 %= N;
                modgap2++;
            }
            ll start = average - (N / 2); 
            ll end = start + gap;
            ll sum = 0;
            cout << start << " ";
            sum += start + end;
            for(ll i=1; i<=modgap2; i++) {
                cout << start + i << " ";
                sum += start + i;
            }
            for(ll i=start+modgap2+2; i<end-2; i++) {
                cout << i << " ";
                sum += i;
            }
            cout << end << endl;
            cout << (end-start) * (end-start) << " " << sum << endl;
        }
        else {
                     ll gap = N+2;
            ll gap2 = gap*gap;
            ll average = gap2 / N;
            ll modgap2 = addAll(average - (N / 2) + 1, average + (N / 2)) - gap2;
            ll start = average - (N / 2);
            ll end = start + gap;
            cout << start << " ";
            for(ll i=1; i<=modgap2+1; i++) {
                cout << start + i << " ";
            }
            for(ll i=start+modgap2+3; i<end-2; i++) {
                cout << i << " ";
            }
            cout << end << endl;
        }
    }
}