#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<long long, long long> a[n];
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }
    sort(a, a + n);
    vector<pair<long long, long long>> arr;
    arr.push_back(a[0]); arr.push_back(a[1]);
    for(int i = 2; i < n; ++i) {
        long long x1, y1, x2, y2, x3, y3;
        x1 = arr[arr.size() - 2].first;
        y1 = arr[arr.size() - 2].second;
        x2 = arr[arr.size() - 1].first;
        y2 = arr[arr.size() - 1].second;
        x3 = a[i].first;
        y3 = a[i].second;
        x2 -= x1;
        y2 -= y1;
        x3 -= x1;
        y3 -= y1;
        while(arr.size() >= 2 && x2 * y3 - x3 * y2 > 0) {
            arr.pop_back();
            //arr.size() = 1
            // arr.size() - 2 = -1
            // arr[-1] -> error
            if(arr.size() >= 2) {
                x1 = arr[arr.size() - 2].first;
                y1 = arr[arr.size() - 2].second;
                x2 = arr[arr.size() - 1].first;
                y2 = arr[arr.size() - 1].second;
                x3 = a[i].first;
                y3 = a[i].second;
                x2 -= x1;
                y2 -= y1;
                x3 -= x1;
                y3 -= y1;
            }
        }
        arr.push_back(a[i]);
    }
    set<pair<int, int>> res;
    for(int i = 0; i < arr.size(); ++i) {
        res.insert(arr[i]);
    }
    arr.clear();
    arr.push_back(a[n - 1]); arr.push_back(a[n - 2]);
    for(int i = n - 3; i >= 0; --i) {
        long long x1, y1, x2, y2, x3, y3;
        x1 = arr[arr.size() - 2].first;
        y1 = arr[arr.size() - 2].second;
        x2 = arr[arr.size() - 1].first;
        y2 = arr[arr.size() - 1].second;
        x3 = a[i].first;
        y3 = a[i].second;
        x2 -= x1;
        y2 -= y1;
        x3 -= x1;
        y3 -= y1;
        while(arr.size() >= 2 && x2 * y3 - x3 * y2 > 0) {
            arr.pop_back();
            //arr.size() = 1
            // arr.size() - 2 = -1
            // arr[-1] -> error
            if(arr.size() >= 2) {
                x1 = arr[arr.size() - 2].first;
                y1 = arr[arr.size() - 2].second;
                x2 = arr[arr.size() - 1].first;
                y2 = arr[arr.size() - 1].second;
                x3 = a[i].first;
                y3 = a[i].second;
                x2 -= x1;
                y2 -= y1;
                x3 -= x1;
                y3 -= y1;
            }
        }
        arr.push_back(a[i]);
    }
    for(int i = 0; i < arr.size(); ++i)
        res.insert(arr[i]);
    cout << res.size() << endl;
    for(auto i : res) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}