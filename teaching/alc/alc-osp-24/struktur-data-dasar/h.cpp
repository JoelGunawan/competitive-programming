#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, string> s;
    s["halo"] = "dunia";
    s["osn"] = "p";
    s["tlx"] = "toki";
    s["code"] = "forces";
    s["at"] = "coder";
    cout << s["halo"] << endl;
    // pair<T1, T2>
    // T1 -> tipe data 1 (string)
    // T2 -> tipe data 2 (string)
    for(pair<string, string> x : s) {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
    map<string, int> a;
    a["skor1"] = 100;
    a["no wa"] = 72429472;
    a["no peserta"] = 124923847;
    for(pair<string, int> x : a) {
        cout << x.first << " " << x.second << endl;
    }
    cout << a["belum dipakai"] << endl;
    cout << s["belum dipakai"] << endl;
}