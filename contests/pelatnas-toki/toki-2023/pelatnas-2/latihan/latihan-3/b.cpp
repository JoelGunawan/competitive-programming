// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const lll is_query = -1e23;
struct Line {
    lll m, b, number;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) {
            if(m == rhs.m) {
                // return based on number 
                return number < rhs.number;
            }
            return m < rhs.m;
        }
        const Line* s = succ();
        if (!s) return 0;
        lll x = rhs.m;
        if(b - s->b == (s->m - m) * x)
            return s->number > number;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b < z->b;
        }
        auto x = prev(y);
        if (z == end()) {
            return y->m == x->m && y->b < x->b;
        }
        // **** May need long double typecasting here
        return (long double)(x->b - y->b)*(z->m - y->m) > (long double)(y->b - z->b)*(y->m - x->m) 
        || ((long double)(x->b - y->b)*(z->m - y->m) == (long double)(y->b - z->b)*(y->m - x->m) 
        && !((y->m == x->m && y->b == x->b && y->number > x-> number) || (y->m == z->m && y->b == z->b && y->number > z->number)));
    }
    void insert_line(lll m, lll b, lll number) {
        auto y = insert({ m, b, number });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    Line eval(lll x) {
        return *lower_bound((Line) { x, is_query });
        //return l.m * x + l.b;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, q, x;
    cin >> n >> q >> x;
    Line a[n + 1];
    HullDynamic cht;
    for(int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        a[i].m = -x;
        a[i].b = 0;
        a[i].number = i;
        cht.insert_line(a[i].m, a[i].b, a[i].number);
    }
    //cht.insert_line(a[1].m, a[1].b, 1);
    //cht.insert_line(a[1].m, a[1].b, 2);
    //cht.insert_line(a[1].m, a[1].b, 1);
    //cout << (ll)cht.eval(1).number << endl;
    for(int i = 0; i < q; ++i) {
        ll p, t, v;
        cin >> p >> t >> v;
        Line l = cht.eval(t);
        if(x == 1)
            cout << (int)l.number << " " << (ull)(-(l.m * t + l.b)) << endl;
        else 
            cout << (ull)(-(l.m * t + l.b)) << endl;
        a[p].b = -(-a[p].m * t + -a[p].b - (-a[p].m - v) * t);
        a[p].m += v;
        cht.insert_line(a[p].m, a[p].b, a[p].number);
    }
}
/*
struct line {
    lll m, c;
    int number;
};
bool customsort(line a, line b) {
    if(a.m != b.m)
        return a.m < b.m;
    else if(a.c != b.c)
        return a.c < b.c;
    else
        return a.number > b.number;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // dikasih persamaan garis, suruh nentuin sekarang garis yang paling kecil hasilnya di titik x berapa, hapus garis itu, output no pesertanya
    // dynamic cht
    // sqrt might be possible (small q and n, although pending update is not the best idea here)
    // divide into sqrt(n) blocks, nanti peserta yang di update dyn hull nya di sqrt bloknya bakal keganti
    // technically binser + dp cht is possible, tapi gada template jadi ribet :3
    // atau bisa ya? di sorting aja, terus ntar jalanin kyk biasa, bakal lebih ribet tapi lebih cepet
    // sebenernya bs di pending update cmn insert ribet?
    // eh ga juga deh, bisa deh
    // ntar simpen query up to sqrt(q), terus klo udah sqrt(q), hapus semua arraynya
    // dimasukkan ke pending, yang di pending buat manual :D
    // t increasing, jadi boleh lgsg buang dr array aja klo misal udah ga muat :D
    vector<line> cht, tmp;
    vector<int> pending;
    int n, q, x;
    cin >> n >> q >> x;
    line a[n + 1];
    for(int i = 1; i <= n; ++i) {
        lll x;
        cin >> x;
        a[i].m = x;
        a[i].c = 0;
        a[i].number = i;
        tmp.push_back(a[i]);
    }
    sort(tmp.begin(), tmp.end(), customsort);
    for(auto i : tmp) {
        cout << i.m << " " << i.number << endl;
    }
    // sort line by gradient besar di belakang kecil di depan, number dari besar di depan kecil di belakang
    // init: sort by 
    // bisa jadi dia di tempat intersect 2 line, jadi harus hati-hati bisa aja ada angka peserta lebih tinggi yang memenuhi
    // strategi: pop tapi coba set as max juga :D
    // aman !!!
    for(auto i : tmp) {
        if(cht.size() && i.m == cht.back().m) {
            // do nothing
        }
        else if(cht.size() == 0 || cht.size() == 1)
            cht.pb(i);
        else {
            // cek intersect antara back dan - 2
            // cek intersect antara cur dan - 2
            while(cht.size() >= 2 && (i.c - cht[cht.size() - 2].c) / (cht[cht.size() - 2].m - i.m) < (cht.back().c - cht[cht.size() - 2].c) / (cht[cht.size() - 2].m - cht.back().m)) {
                cht.pop_back();
            }
        }
    }
    tmp.clear();
    int blk = 1000;
    for(int i = 0; i < q; ++i) {
        if(pending.size() >= blk) {
            cht.clear();
            for(int j = 1; j <= n; ++j)
                tmp.pb(a[j]);
            sort(tmp.begin(), tmp.end(), customsort);
            for(auto i : tmp) {
                if(cht.size() && i.m == cht.back().m) {
                    // do nothing
                }
                else if(cht.size() == 0 || cht.size() == 1)
                    cht.pb(i);
                else {
                    // cek intersect antara back dan - 2
                    // cek intersect antara cur dan - 2
                    while(cht.size() >= 2 && (i.c - cht[cht.size() - 2].c) / (cht[cht.size() - 2].m - i.m) > (cht.back().c - cht[cht.size() - 2].c) / (cht[cht.size() - 2].m - cht.back().m)) {
                        cht.pop_back();
                    }
                    cht.pb(i);
                }
            }       
            //cout << "NEWCHT " << cht.size() << endl;
            tmp.clear();
            pending.clear();
        }
        lll p, t, v;
        cin >> p >> t >> v;
        pair<lll, int> res = {1e20, -1};
        for(int i : pending) {
            if((lll)a[i].m * t + a[i].c < res.fi || ((lll)a[i].m * t + a[i].c == res.fi && a[i].number > res.se)) {
                res.se = a[i].number;
                res.fi = (lll)1 * a[i].m * t + a[i].c;
            }
        }
        //cout << "EVALUATE " << cht.back().number << " " << (lll)cht.back().m * t + (lll)cht.back().c << " " << cht[cht.size() - 2].number << " " << (lll)cht[cht.size() - 2].m * t + (lll)cht[cht.size() - 2].c << endl;
        while(cht.size() >= 2 && (lll)cht.back().m * t + cht.back().c >= (lll)cht[cht.size() - 2].m * t + cht[cht.size() - 2].c) {
            if((lll)cht.back().m * t + cht.back().c < res.fi || ((lll)cht.back().m * t + cht.back().c == res.fi && cht.back().number > res.se)) {
                res.se = cht.back().number;
                res.fi = (lll)cht.back().m * t + cht.back().c;
            }
            cht.pop_back();
            //if(cht.size() >= 2)
            //    cout << "EVALUATE " << cht.back().number << " " << (lll)cht.back().m * t + (lll)cht.back().c << " " << cht[cht.size() - 2].number << " " << (lll)cht[cht.size() - 2].m * t + (lll)cht[cht.size() - 2].c << endl;
        }
        if((lll)cht.back().m * t + cht.back().c < res.fi || ((lll)cht.back().m * t + cht.back().c == res.fi && cht.back().number > res.se)) {
            res.se = cht.back().number;
            res.fi = (lll)cht.back().m * t + cht.back().c;
        }
        pending.pb(p);
        // di index p cek sekarang itu udah sampe berapa
        lll tmp = (lll)a[p].m * t + a[p].c;
        a[p].c = a[p].m * t + a[p].c - (a[p].m - v) * t;
        a[p].m -= v;
        //cout << "NEW " << (lll)a[p].m << " " << (lll)a[p].c << endl;
        //cout << "DEBUG " << (lll)cht.back().m << " " << (lll)cht.back().c << " " << (lll)cht.back().m * t + (lll)cht.back().c << endl;
        if(x == 1)
            cout << res.se << " " << (unsigned long long)res.fi << endl;
        else
            cout << (unsigned long long)res.fi << endl;
    }
    return 0;
}
*/