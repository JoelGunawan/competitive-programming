#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, d;
    cin >> n >> k >> d;
    string s;
    cin >> s;
    int last = -1e9;
    vector<int> forward, backward;
    for(int i = 0; i < n; ++i)
        if(s[i] == 'o' && i - last - 1 >= d) {
            last = i;
            forward.pb(i);
        }
    last = 1e9;
    for(int i = n - 1; i >= 0; --i) {
        if(s[i] == 'o' && last - i - 1 >= d) {
            last = i;
            backward.pb(i);
        }
    }
    if(forward.size() > k || backward.size() > k)
        cout << -1 << endl;
    else {
        vector<int> result;
        for(int i = 0; i < backward.size(); ++i)
            if(binary_search(forward.begin(), forward.end(), backward[i]))
                result.pb(backward[i]);
        sort(result.begin(), result.end());
        if(result.size() == 0)
            cout << -1 << endl;
        else {
            for(int i = 0; i < result.size(); ++i)
                cout << result[i] + 1 << endl;
        }
    }
    return 0;
}