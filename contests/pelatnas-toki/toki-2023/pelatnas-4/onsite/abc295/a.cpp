#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> a = {"and", "not", "that", "the", "you"};
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for(auto j : a) {
            if(s == j) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}