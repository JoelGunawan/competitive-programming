#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // b1 d1
    // b2 d2
    // b3 d3
    /*
        b1 (awal)
        d1 (akhir)
        data yang disimpan -> banyak orang yang hidup
        pair<int, bool> ?
        pair<int, int>
        1 -> mulai sebuah segment
        0 -> akhir sebuah segment
    */
    //pair<int, bool> a[2 * n];
    vector<pair<int, bool>> a;
    for(int i = 0; i < n; ++i) {
        int b, d;
        cin >> b >> d;
        a.push_back(make_pair(b, true));
        a.push_back(make_pair(d, false));
        //a[2 * i] = make_pair(b, true);
        //a[2 * i + 1] = make_pair(d, false);
    }
    // i = 0 -> 0, 1
    // i = 1 -> 2, 3
    // i = 2 -> 4, 5
    // i = 3 -> 6, 7
    // i = 4 -> 8, 9
    // ...
    //for(int i = 0; i < a.size(); ++i) {
    //    cout << i << " " << a[i].first << " " << (int)a[i].second << endl;
    //}
    //return 0;
    sort(a.begin(), a.end());
    int cnt = 0, max_people = 0, year;
    for(int i = 0; i < 2 * n; ++i) {
        if(a[i].second == true) {
            ++cnt;
        }
        else if(a[i].second == false) {
            --cnt;
        }
        if(cnt > max_people) {
            max_people = cnt;
            year = a[i].first;
        }
    }
    cout << year << " " << max_people << endl;
    return 0;
}