#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool rev = 0; // dq kebalik/tidak
    deque<int> dq;
    for(int i = 0; i < n; ++i) {
        string op;
        cin >> op;
        if(op == "add") {
            int x, y;
            cin >> x >> y;
            if(rev) {
                for(int j = 0; j < y; ++j) {
                    dq.push_front(x);
                }
            }
            else {
                for(int j = 0; j < y; ++j) {
                    dq.push_back(x);
                }
            }
            cout << dq.size() << endl;
        }
        else if(op == "del") {
            int y;
            cin >> y;
            if(rev) {
                cout << dq.back() << endl;
                for(int j = 0; j < y; ++j) {
                    dq.pop_back();
                }    
            }
            else {
                cout << dq.front() << endl;
                for(int j = 0; j < y; ++j) {
                    dq.pop_front();
                }
            }
        }
        else {
            rev = !rev; // membalik true -> false/false -> true
        }
    }
}