#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
pair<int, int> divgcd(pair<int, int> a) {
    int gcd = __gcd(abs(a.fi), abs(a.se));
    if(a.fi != 0 && a.se != 0) {
        a.fi /= gcd, a.se /= gcd;
    }
    else if(a.fi == 0 && a.se == 0) {
        return a;
    }
    else if(a.se == 0) {
        //cout << "HERE" << endl;
        return {1, 0};
    }
    else if(a.fi == 0) {
        return {0, 1};
    }
    return a;
}
bool check(pair<int, int> a, pair<int, int> b) {
    // dx * (x1+x2) + dy * (y1 + y2) = 0
    // jika kedua garis melewati 0, maka harusnya true? 
    return 1ll * a.fi * b.fi + 1ll * a.se * b.se == 0;
}
pair<int, int> perpendicular(pair<int, int> a) {
    a = {-a.se, a.fi};
    if(a.se < 0)
        a.fi = -a.fi, a.se = -a.se;
    return divgcd(a);
}
double get_angle(pair<int, int> a) {
    //cout << a.se << " " << a.fi << endl;
    double ret = atan2(a.se, a.fi) / acos(-1) * 180.0;
    return ret;
}
int main() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    vector<pair<int, int>> slope;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            // cari angle nya dengan y positif, x terserah
            // find midpoint of the 2, paksa jadi y positifnya (reflect by the y line)
            pair<int, int> mid = {a[i].fi + a[j].fi, a[i].se + a[j].se};
            mid = divgcd(mid);
            pair<int, int> alt = {a[i].fi - a[j].fi, a[i].se - a[j].se};
            alt = divgcd(alt);
            //cout << mid.fi << " " << mid.se << " " << alt.fi << " " << alt.se << endl;
            if(mid.fi == 0 && mid.se == 0) {
                slope.push_back(perpendicular(alt));
            }
            else if(check(mid, alt)) {
                if(mid.se < 0)
                    mid.fi = -mid.fi, mid.se = -mid.se;
                mid = divgcd(mid);
                //cout << "DEB " << mid.fi << " " << mid.se << endl;
                slope.push_back(mid);
            }
        }
    }
    //cout << ver << " " << hor << endl;
    //cout << "TEST" << endl;
    cout << fixed << setprecision(3);
    sort(slope.begin(), slope.end());
    double deg = 0;
    int mxcnt = 0, cnt = 0;
    for(int i = 0; i < slope.size(); ++i) {
        if(i != 0 && slope[i] != slope[i - 1]) {
            if(cnt == mxcnt) {
                //cout << "JOINT " << slope[i - 1].fi << " " << slope[i - 1].se << endl;
                deg = max(deg, get_angle(slope[i - 1]));
            }
            else if(cnt > mxcnt) {
                //cout << "NEW " << slope[i - 1].fi << " " << slope[i - 1].se << endl;
                deg = get_angle(slope[i - 1]);
                mxcnt = cnt;
            }
            cnt = 0;
        }
        ++cnt;
    }
    //cout << "CHANGE MX" << endl;
    if(mxcnt == cnt && slope.size()) {
        deg = max(deg, get_angle(slope.back()));
    }
    else if(cnt > mxcnt) {
        mxcnt = cnt;
        //cout << slope.back().fi << " " << slope.back().se << endl;
        deg = get_angle(slope.back());
    }
    //cout << mx.se.se << " " << mx.se.fi << endl;
    //if(mx.se.fi == 0)
    //    cout << 90.0 << endl << n - 2 * mx.fi << endl;
    //else
    cout << deg << endl << n - 2 * mxcnt << endl;
}