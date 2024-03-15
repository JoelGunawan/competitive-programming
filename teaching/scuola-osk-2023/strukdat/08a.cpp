#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    deque<int> dq;
    while(q--) {
        string ops;
        cin >> ops;
        if(ops == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if(ops == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if(ops == "pop_back") {
            dq.pop_back();
        }
        else 
            dq.pop_front();
    }
    for(auto i : dq)
        cout << i << endl;
}