#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    deque<int> a;
    while(n--) {
        string q;
        cin >> q;
        if(q == "push_front") {
            int x;
            cin >> x;
            a.push_front(x);
        }
        else if(q == "push_back") {
            int x;
            cin >> x;
            a.push_back(x);
        }
        else if(q == "pop_back") {
            a.pop_back();
        }
        else
            a.pop_front();
    }
    for(auto i : a)
        cout << i << endl;
}