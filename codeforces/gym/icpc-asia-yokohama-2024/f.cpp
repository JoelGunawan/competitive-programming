#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
template<class T>
struct Point {
  typedef Point P;
  T x, y;
  Point(T x = 0, T y = 0): x(x), y(y) {}
  bool operator<(P p) const {
    return tie(x, y) < tie(p.x, p.y);
  }
  bool operator==(P p) const {
    return tie(x, y) == tie(p.x, p.y);
  }
  P operator+(P p) const {
    return P(x + p.x, y + p.y);
  }
  P operator-(P p) const {
    return P(x - p.x, y - p.y);
  }
  P operator*(T d) const {
    return P(x * d, y * d);
  }
  P operator/(T d) const {
    return P(x / d, y / d);
  }
  T cross(P p) const {
    return x * p.y - y * p.x;
  }
  T cross(P a, P b) const {
    return cross(a - *this, b - *this);
  }
  double angle() const {
    return atan2(y, x);
  }
  
};
template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
  auto d = (e1 - s1).cross(e2 - s2);
  if (d == 0) {
    return make_pair(-(s1.cross(e1, s2) == 0), P(0, 0));
  }
  auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
  return {1, (s1 * p + e1 * q) / d};
}
const double eps = 1e-9;
typedef long double ld;
template<class T>
struct HP {
  typedef Point<T> P;
  P st, ed;
  HP(P st, P ed): st(st), ed(ed) {}
};
typedef Point<ld> P;
typedef HP<ld> H;
vector<P> HPI(vector<HP<ld>> v) {
  vector<P> pts;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      pair<int, P> ii = lineInter(v[i].st, v[i].ed, v[j].st, v[j].ed);
      if (ii.first == 1) {
        pts.push_back(ii.second);
      }
    }
  }
  vector<P> ans;
  for (int i = 0; i < pts.size(); i++) {
    bool flag = 1;
    for (int j = 0; j < v.size(); j++) {
      if (v[j].st.cross(v[j].ed, pts[i]) < 0) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      ans.push_back(pts[i]);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // int test;
  // cin >> test;
  // while (test--) {
    ll sides[3];
    cin >> sides[0] >> sides[1] >> sides[2];
    sort(sides, sides + 3);
    ld ans = 0;
    do {
      ll a = sides[0], b = sides[1], c = sides[2];
      vector<HP<ld>> dom[4];
      for (int i = 0; i < 4; i++) {
        dom[i].push_back({P(0, 0), P(1, 0)});
        dom[i].push_back({P(0, 1), P(0, 0)});
        dom[i].push_back({P(c, 0), P(c, 1)});
        dom[i].push_back({P(0, a), P(1, a)});
      }
      ll px[4] = {a, b, 0, -b - c}, py[4] = {b, -a, -a -b, -a-c};
      dom[0].push_back({P(a, b), P(0, 0)});
      dom[3].push_back({P(c, a), P(c - b, a - c)});
      for (int i = 0; i < 4; i++) {
        vector<H> hp = dom[i];
        for (int j = 0; j < 4; j++) {
          if (i != j) {
            ld a1 = px[i] * 2, b1 = py[i] * 2, c1 = px[i] * px[i] + py[i] * py[i];
            ld a2 = px[j] * 2, b2 = py[j] * 2, c2 = px[j] * px[j] + py[j] * py[j];
            if (b1 == b2 && a1 == a2) {
              continue;
            } else if (b1 == b2) {
              if (a1 > a2) {
                hp.push_back({P((c1 - c2) / (a1 - a2), 0), P((c1 - c2) / (a1 - a2), 1)});
              } else {
                hp.push_back({P((c1 - c2) / (a1 - a2), 1), P((c1 - c2) / (a1 - a2), 0)});
              }
            } else if (a1 == a2) {
              if (b1 > b2) {
                hp.push_back({P(0, (c1 - c2) / (b2 - b1)), P(1, (c1 - c2) / (b2 - b1))});
              } else {
                hp.push_back({P(1, (c1 - c2) / (b2 - b1)), P(0, (c1 - c2) / (b2 - b1))});
              }
            } else {
              if (b2 > b1) {
                hp.push_back({P(0, c1 - c2), P(1, (a1 - a2) / (b2 - b1) + c1 - c2)});
              } else {
                hp.push_back({P(1, (a1 - a2) / (b2 - b1) + c1 - c2), P(0, c1 - c2)});
              }
            }
          }
        }
        vector<P> pts = HPI(hp);
        cout << pts.size() << endl;
        for (P p: pts) {
          ans = max(ans, (p.x - px[i]) * (p.x - px[i]) + (p.y - py[i]) * (p.y - py[i]));
        }
      }
    } while (next_permutation(sides, sides + 3));
    cout << fixed << setprecision(15) << sqrt(ans);
    cout << "\n";
  // }
}