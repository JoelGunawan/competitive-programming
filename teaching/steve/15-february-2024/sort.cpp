#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {5, 3, 9, 7};
    // O(NlogN)
    sort(a.begin() + 1, a.begin() + 4);
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    int arr[] = {5, 3, 9, 7};
    sort(arr, arr + 4);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    // O(N + maks)
    vector<int> awal = {3, 2, 1, 2, 2, 3, 1, 2, 4}, akhir;
    int cnt[5];
    memset(cnt, 0, sizeof(cnt));
    for(auto i : awal) {
        ++cnt[i];
    }
    for(int i = 1; i <= 4; ++i) {
        for(int j = 0; j < cnt[i]; ++j) {
            akhir.push_back(i);
        }
    }
    for(auto i : akhir) 
        cout << i << " ";
    cout << endl;
    sort(awal.begin(), awal.end());
    for(auto i : awal)
        cout << i << " ";
    cout << endl;
}