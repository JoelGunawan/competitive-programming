#include <bits/stdc++.h>
using namespace std;
int query(int left, int right) {
    cout << "? " << left << " " << right << endl;
    int input;
    cin >> input;
    return input;
}
int main() {
   int t, n, q;
   cin >> t >> n >> q;
   if(t == 1 || t == 2) {
    vector<int> colors;
    for(int i = 0; i < n; ++i)
        colors.push_back(query(1, i + 1));
    cout << "! ";
    for(auto i : colors) 
        cout << i << " ";
    cout << endl;
   }
   if(t == 5) {
    if(query(1, n) == n) {
        cout << "! ";
        for(int i = 1; i <= n; ++i)
            cout << i << " ";
        cout << endl;
    }
    else {
        int l, r, pr = 1;
        for(int i = 2; i <= n; ++i) {
            if(query(1, i) == pr)
                r = i;
            else
                ++pr;
        }
        pr = 1;
        for(int i = n - 1; i >= 1; --i) {
            if(query(i, n) == pr)
                l = i;
            else
                ++pr;
        }
        vector<int> ans;
        int color = 1;
        for(int i = 1; i <= n; ++i) {
            if(i == r)
                ans.push_back(ans[l - 1]);
            else
                ans.push_back(color), ++color;
        }
        cout << "! ";
        for(auto i : ans)
            cout << i << " ";
        cout << endl;
    }
   }
   if(t == 6 || t == 7) {
    int ans[n + 1];
    ans[1] = 1;
    int cnt = 1;
    for(int i = 2; i <= n; ++i) {
        int left = 1, right = cnt + 1;
        bool used[n + 1];
        while(left < right) {
            memset(used, 0, sizeof(used));
            int mid = (left + right) >> 1, cur_cnt = 0, idx_mid;
            for(int j = i - 1; j >= 1; --j) {
                if(!used[ans[j]])
                    ++cur_cnt, used[ans[j]] = 1;
                if(cur_cnt == mid) {
                    idx_mid = j;
                    break;
                }
            }
            if(query(idx_mid, i) == mid)
                right = mid;
            else
                left = mid + 1;
        }
        if(left == cnt + 1)
            ans[i] = cnt + 1, ++cnt;
        else {
            memset(used, 0, sizeof(used));
            int cur_cnt = 0;
            for(int j = i - 1; j >= 1; --j) {
                if(!used[ans[j]])
                    ++cur_cnt, used[ans[j]] = 1;
                if(cur_cnt == left) {
                    ans[i] = ans[j];
                    break;
                }
            }
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
   }
   if(t == 3 || t == 4) {
    int ans[n + 1];
    ans[1] = 1;
    int cnt = 1;
    for(int i = 2; i <= n; ++i) {
        int left = 1, right = min(4, cnt + 1);
        bool used[n + 1];
        while(left < right) {
            memset(used, 0, sizeof(used));
            int mid = (left + right) >> 1, cur_cnt = 0, idx_mid;
            for(int j = i - 1; j >= 1; --j) {
                if(!used[ans[j]])
                    ++cur_cnt, used[ans[j]] = 1;
                if(cur_cnt == mid) {
                    idx_mid = j;
                    break;
                }
            }
            if(query(idx_mid, i) == mid)
                right = mid;
            else
                left = mid + 1;
        }
        if(left == cnt + 1)
            ans[i] = cnt + 1, ++cnt;
        else {
            memset(used, 0, sizeof(used));
            int cur_cnt = 0;
            for(int j = i - 1; j >= 1; --j) {
                if(!used[ans[j]])
                    ++cur_cnt, used[ans[j]] = 1;
                if(cur_cnt == left) {
                    ans[i] = ans[j];
                    break;
                }
            }
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
   }
}