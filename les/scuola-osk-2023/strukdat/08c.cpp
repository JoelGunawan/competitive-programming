#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    // fi -> x (angka berapa)
    // se -> y (jumlahnya)
    vector<pair<int, int>> v;
    int q = 0;
    for(int i = 0; i < n; ++i) {
        string ops;
        cin >> ops;
        if(ops == "add") {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
            q += y;
            cout << q << endl;
        }
        else if(ops == "del") {
            int y;
            cin >> y;
            q -= y;
            cout << v.back().first << endl;
            // hapus y elemen terakhir
            while(y > 0) {
                if(v.back().second > y) {
                    v.back().second -= y;
                    y = 0;
                }
                else {
                    y -= v.back().second;
                    v.pop_back();
                }
            }
        }
        else if(ops == "adx") {
            int x;
            cin >> x;
            for(int j = 0; j < v.size(); ++j)
                v[j].first += x;
        }
        else {
            int x;
            cin >> x;
            for(int j = 0; j < v.size(); ++j)
                v[j].first -= x;
        }
    }
}