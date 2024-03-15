#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    multiset<int> a;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        // artinya -> lower_bound ada/valid
        // fungsi lower bound -> return iterator elemen pertama yg nilainya >= x
        // mis a = {2, 4, 7} lower_bound(5) -> iterator ke "7"
        if(a.lower_bound(x) != a.end()) {
            a.erase(a.lower_bound(x));
            a.insert(x);
        }
        else {
            a.insert(x);
        }
    }
    cout << a.size() << endl;
}