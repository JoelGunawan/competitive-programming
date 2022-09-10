#include <bits/stdc++.h>
using namespace std;
int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int input;
    cin >> input;
    return input;
}
int main() {
    int t, n, q;
    cin >> t >> n >> q;
    int color[1005];
    bool used[1005];
    color[1] = 1;
    int color_cnt = 1;
    for(int i = 2; i <= n; ++i) {
        vector<int> colors;
        for(int j = i - 1; j >= 1; --j) {
            if(!used[color[j]])
                used[color[j]] = 1, colors.push_back(j);
        }
        int l = 0, r = colors.size(), ans = colors.size();
        while(l <= r) {
            if(l == colors.size())
                break;
            int mid = (l + r) / 2;
            int tmp = colors[mid];
            if(query(tmp, i) == mid) {
                ans = tmp;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if(ans == colors.size())
            color[i] = ++color_cnt;
        else
            color[i] = color[ans];
    }
    cout << "! ";
    for(int i = 1; i <= n; ++i)
        cout << color[i] << " ";
    cout << endl;
}