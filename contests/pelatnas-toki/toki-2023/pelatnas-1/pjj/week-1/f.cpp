// header file
#include <cstdio>
#include <algorithm>
#include <cmath>
// pragma
// macros
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
/*
void f(int l, int r) {
    if(l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    f(l, mid), f(mid + 1, r);
    int midx = -1e9;
    for(int i = l; i <= mid; ++i)
        midx = max(midx, a[i].se);
    int pr = mid + 1, ps = mid + 1;
    deque<int> dq;
    dq.pb(mid + 1);
    for(int i = l; i <= mid; ++i) {
        if(sqr(midx - a[i].se) >= ans)
            continue;
        // cek antara left dan right
        // right pake 2 pointers
        // furhter ps
        while(ps < r && (a[ps].fi < a[i].fi || sqr(a[ps + 1].fi - a[i].fi) < ans)) {
            if(sqr(midx - a[ps + 1].se) < ans)
                dq.pb(ps + 1);
            ++ps;
        }
        // incr pr
        while(pr < r && pr < ps && a[pr + 1].fi < a[i].fi && sqr(a[pr].fi - a[i].fi) >= ans) {
            if(dq.size() && dq.front() == pr)
                dq.pop_front();
            ++pr;
        }
        for(auto j : dq)
            ans = min(ans, sqr(a[i].fi - a[j].fi) + sqr(a[i].se - a[j].se));
    }
    //inplace_merge(a + l, a + mid + 1, a + r + 1);
    int lidx = l, ridx = mid + 1;
    for(int i = l; i <= r; ++i) {
        if(lidx > mid || (ridx <= r && a[ridx] < a[lidx]))
            tmp[i] = a[ridx++];
        else
            tmp[i] = a[lidx++];
    }
    for(int i = l; i <= r; ++i)
        a[i] = tmp[i];
    /*
    vector<pair<int, int>> proc;
    inplace_merge(a + l, a + mid + 1, a + r + 1);
    for(int i = l; i <= r; ++i) {
        if(sqr(midx - a[i].se) < ans)
            proc.pb(a[i]);
    }
    //cout << "cur " << l << " " << r << endl;
    //for(auto i : proc)
    //    cout << i.fi << " " << i.se << endl;
    int pr = 0;
    for(int i = 0; i < proc.size(); ++i) {
        while(pr < i && sqr(proc[pr].fi - proc[i].fi) >= ans)
            ++pr;
        for(int j = pr; j < i; ++j)
            ans = min(ans, sqr(proc[j].fi - proc[i].fi) + sqr(proc[j].se - proc[i].se));
    }
}
*/
double f(pair<double, double> a[], int l, int r) {
    if(l >= r) {
        return 9e18;
    }
    /*
    cout << "cur " << l << " " << r << endl;
    for(auto i : proc)
        cout << i.fi << " " << i.se << endl;
    */
    int mid = (l + r) / 2;
    double lans = f(a, l, mid), rans = f(a, mid + 1, r);
    double ans = (lans < rans) ? lans : rans;
    double midx = (double)(a[mid].fi + a[mid + 1].fi) * 0.5;
    //if(l == 25 && r == 49)
    //    printf("%lf %lf %lf %d\n", a[mid + 1].fi, midx + ans, midx, mid + 1);
    for(int i = mid + 1; a[i].fi < midx + ans && i <= r; i++) {
        //if(l == 25 && r == 49)
        //    printf("%lf %lf %d\n", a[mid].fi, midx - ans, l);
        for(int j = mid; a[j].fi > midx - ans && j >= l; j--) {
            double temp = (double)sqrt(pow(a[i].fi - a[j].fi, 2) + pow(a[i].se - a[j].se, 2));
            //if(i == 39)
            //    printf("%lf %lf %d\n", a[j].fi, midx - ans, l);
            if(temp < ans)
                ans = temp;
        }
    }
    //printf("%d %d %.4lf\n", l, r, ans);
    return ans;
}
bool compx(pair<double, double> a, pair<double, double> b) {
    return a.fi < b.fi;
}
int main() {
    pair<double, double> a[200001];
    int n;
    while(scanf("%d", &n)) {
        if(n == 0)
            break; 
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &a[i].fi, &a[i].se);
        }
        sort(a, a + n, compx);
        //for(int i = 0; i < n; ++i) {
        //    for(int j = 0; j < i; ++j) {
        //        if(pow(a[i].fi - a[j].fi, 2) + pow(a[i].se - a[j].se, 2) == 1)
        //            printf("OUTPUT %d %d\n", i, j);
        //    }
        //}
        double ans = f(a, 0, n - 1);
        printf("%.0lf\n", pow(ans, 2));
        return 0;
    }
    return 0;
}