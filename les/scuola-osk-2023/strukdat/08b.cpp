#include <bits/stdc++.h>
using namespace std;
int main() {
    deque<int> dq;
    int n;
    cin >> n;
    bool rev = 0;
    for(int i = 0; i < n; ++i) {
        string op;
        cin >> op;
        if(op == "add") {
            int x, y;
            cin >> x >> y;
            for(int j = 0; j < y; ++j) {
                if(!rev) {
                    dq.push_back(x);
                }
                else {
                    dq.push_front(x);
                }
            }
            cout << dq.size() << endl;
        }
        else if(op == "del") {
            int y;
            cin >> y;
            if(rev) {
                cout << dq.back() << endl;
            }
            else {
                cout << dq.front() << endl;
            }
            for(int j = 0; j < y; ++j) {
                if(!rev)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        else {
            rev ^= 1;
        }
    }
}