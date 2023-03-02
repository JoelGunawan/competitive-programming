#include <bits/stdc++.h>
using namespace std;
int main() {
    int b;
    vector<int> a; 
    while(cin >> b) {
        a.push_back(b);
    }
    for(int i = a.size() - 1; i >= 0; --i) {
        cout << a[i] << endl;
    }
    return 0;
}