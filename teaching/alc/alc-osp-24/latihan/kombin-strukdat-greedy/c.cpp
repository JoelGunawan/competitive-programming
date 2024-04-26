#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, int> cnt;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(cnt[s] == 0) {
            cout << "OK" << endl;
        }
        else {
            cout << s + to_string(cnt[s]) << endl;
        }
        ++cnt[s];
    }
}