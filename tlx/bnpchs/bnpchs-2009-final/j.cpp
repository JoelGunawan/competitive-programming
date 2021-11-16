#include <bits/stdc++.h>
using namespace std;
vector<int> generate_primes(int number) {
    bool arr[number + 1]; memset(arr, 1, sizeof(arr));
    arr[0] = 0, arr[1] = 0;
    for(int i = 2; i <= number / 2; ++i) {
        if(arr[i]) {
            for(int j = 2 * i; j <= number; j += i)
                arr[j] = 0;
        }
    }
    vector<int> res;
    for(int i = 0; i <= number; ++i)
        if(arr[i])
            res.push_back(i);
    return res;
}
int main() {
    int t;
    cin >> t;
    vector<int> primes = generate_primes(1e6);
    vector<vector<int>> arr;
    arr.push_back(primes);
    while(arr[arr.size() - 1].size() > 1) {
        vector<int> cur;
        for(int i = 0; primes[i] <= arr[arr.size() - 1].size(); ++i)
            cur.push_back(arr[arr.size() - 1][primes[i] - 1]);
        arr.push_back(cur);
    }
    while(t--) {
        int p;
        cin >> p;
        int res = -1;
        for(int i = 0; i < arr.size(); ++i)
            if(binary_search(arr[i].begin(), arr[i].end(), p))
                res = i;
        cout << res + 1 << endl;
    }
}