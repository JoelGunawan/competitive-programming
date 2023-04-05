// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
int n;
string s;
int conv(char a) {
    return a;
}
const int alphabet = 200;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // bsta string hashing
    // save all string hash results in a map
    cin >> n;
    char s[n + 1];
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    s[n] = '$';
    n = n + 1;
    // first iteration: 
    // buat langsung aja, kalo terlalu besar rollback langsung
    // jadi nanti langsung dapet 1 msbnya, tinggal coba lagi anaknya
    int p[n], c[n], cnt[max(alphabet, n)], pn[n], cn[n];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    if(classes == n)
        cout << 0 << endl, exit(0);
    //cout << endl;
    int l = 0, r, ans = 1;
    for (int h = 0; (1 << h) <= n; ++h) {
        // always mul by 2
        int cur_len = 1 << h;
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - cur_len;
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt, cnt + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + cur_len) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + cur_len) % n]};
            if (cur != prev) {
                ++classes;
            }
            cn[p[i]] = classes - 1;
        }
        if(classes == n) {
            // revert to old, terus binser
            for(int i = 0; i < n; ++i) {
                p[i] = pn[i] + cur_len;
                if(p[i] >= n)
                    p[i] -= n;
            }
            r = (1 << h) - 1;
            break;
        }
        for(int i = 0; i < n; ++i)
            c[i] = cn[i];
        ans *= 2;
        //cout << endl;
    }
    int res = 0;
    //cout << l << " " << r << endl;
    while(l <= r) {
        int mid = (l + r) / 2;
        int cur_len = mid;
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - cur_len;
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt, cnt + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + cur_len) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + cur_len) % n]};
            if (cur != prev) {
                ++classes;
            }
            cn[p[i]] = classes - 1;
        }
        for(int i = 0; i < n; ++i)
            p[i] = (pn[i] + cur_len) % n;
        if(classes < n)
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans + res << endl;
    return 0;
}