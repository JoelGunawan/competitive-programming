#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define bit(n) (1LL << (n))
#define getbit(x, i) (((x)) >> (i) & 1)
using namespace std;
const long long ooo = 1e18;
const long long oo = 1e9;
 
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {
    if (a > b) {a = b; return true;} return false;
}
 
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {
    if (a < b) {a = b; return true;} return false;
}
 
template<class T> int sgn(T x) {
    return (x > 0) - (x < 0); 
}
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y)==tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x-p.x, y - p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const {return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const {return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x * cos(a) - y  *sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};
template<class P>
vector<P> circleLine(P c, double r, P a, P b) {
    P ab = b - a, p = a + ab * (c - a).dot(ab) / ab.dist2();
    double s = a.cross(b, c), h2 = r * r - s * s / ab.dist2();
    if(h2 < 0) return {};
    if(h2 == 0) return {p};
    P h = ab.unit() * sqrt(h2);
    return {p - h, p + h};
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int r;
        double u, v;
        cin >> u >> v;
        Point a(u, v);
        cin >> u >> v;
        Point b(u, v);
        cin >> u >> v;
        Point c(u, v);
        cin >> r;
        auto g = circleLine(c, r, a, b);
        bool intersect = 0;
        if(b < a)
            swap(a, b);
        for(auto x : g) {
            if(x < a || b < x) {
                // not intersect
            }
            else
                intersect = 1;
        }
        if(!intersect && (a - c).dist() > r && (b - c).dist() > r) {
            double ang1 = (a - c).angle(), ang2 = (b - c).angle();
            if(ang1 > ang2)
                swap(ang1, ang2);
            // ang1 is smaller
            if(ang2 - ang1 >= acos(-1)) {
                ang2 -= 2 * acos(-1);
                swap(ang1, ang2);
            }
            cout << fixed << setprecision(12);
            // cout << ang1 << " " << ang2 << endl;
            double cl = ang1, cr = ang2;
            int it = 100;
            while(it--) {
                double mid1 = cl + (cr - cl) / 3, mid2 = cl + 2 * (cr - cl) / 3;
                Point d = c + Point(cos(mid1) * r, sin(mid1) * r);
                Point e = c + Point(cos(mid2) * r, sin(mid2) * r);
                // cout << mid1 << " " << mid2 << " " << (a - d).dist() + (b - d).dist() << " " << (a - e).dist() + (b - e).dist() << endl;
                if((a - d).dist() + (b - d).dist() < (a - e).dist() + (b - e).dist())
                    cr = mid2;
                else    
                    cl = mid1;
            }
            Point d = c + Point(cos(cl) * r, sin(cl) * r);
            cout << (a - d).dist() + (b - d).dist() << endl;
        }
        else {
            cout << (a - b).dist() << endl;
        }
    }
    return 0;
}