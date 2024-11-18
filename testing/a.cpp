#include <iostream>
#include <iomanip>
#include <cmath>
#include <deque>
#define pid pair<int, double>
#define ppi pair<pid, int>
#define fst first
#define snd second

using namespace std;

const int INF = 1e8;

double pref[1000001];
int N, K, L, R, A[1000001], DP[1000001];
deque<ppi> D;

inline bool solve(double c)
{
    for (int i = 1; i <= N; i++) {DP[i] = INF; pref[i] = pref[i - 1] + A[i - 1] - c;}
    D.push_back({{0, 0}, 0});
    int l = L, r = R;

    for (int i = L; i <= N; i++)
    {
        if (DP[i - L] < INF)
        {
            while (D.size() && D.back().fst >= make_pair(DP[i - L], -pref[i - L])) {D.pop_back();}
            D.push_back({make_pair(DP[i - L], -pref[i - L]), i - L});
        }
        while (D.size() && D.front().snd < i - R) {D.pop_front();}

        DP[i] = D.front().fst.fst;
        if (D.front().fst.snd + pref[i] >= 0) {DP[i]++;}
        
        if (i == r)
        {
            l = l + L, r = r + R;
            if (l > i) {i = l - 1;}
        }
    }
    D.clear();
    return (DP[N] <= K);
}

int main()
{
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> L >> R;
    for (int i = 0; i < N; i++) cin >> A[i];

    double lf = 0, rg = 1e5;
    for (int iter = 0; iter < 40; iter++)
    {
        double M = (lf + rg) / 2;
        if (solve(M)) lf = M;
        else rg = M;
    }

    cout << fixed << setprecision(9) << lf << "\n";
    return 0;
}