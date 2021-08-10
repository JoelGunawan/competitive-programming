#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a(n);
    for(int i = 0; i < n; ++i)
    {
        int in1, in2;
        cin >> in1 >> in2;
        a[i] = make_tuple(in1, in2, i);
    }
    sort(a.begin(), a.end());
    int prev = 0, last = 0;
    for(int i = 0; i < n; ++i)
    {
        if(last == get<0>(a[i]))
            get<0>(a[i]) = prev;
        else
            last = get<0>(a[i]), get<0>(a[i]) = min(get<0>(a[i]), prev + 1), prev = get<0>(a[i]);
        swap(get<0>(a[i]), get<1>(a[i]));
    }
    sort(a.begin(), a.end());
    prev = 0, last = 0;
    for(int i = 0; i < n; ++i)
    {
        if(last == get<0>(a[i]))
            get<0>(a[i]) = prev;
        else
            last = get<0>(a[i]), get<0>(a[i]) = min(get<0>(a[i]), prev + 1), prev = get<0>(a[i]);
        swap(get<0>(a[i]), get<2>(a[i]));
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i)
        cout << get<1>(a[i]) << " " << get<2>(a[i]) << endl;
}