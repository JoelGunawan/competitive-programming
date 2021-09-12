#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> kiri = {1, 2, 3, 4}, kanan = {5, 6, 7, 8};
    while(true)
    {
        cout << '?' << endl;
        for(int i = 0; i < kiri.size(); ++i)
            cout << kiri[i] << " ";
        cout << endl;
        for(int i = 0; i < kanan.size(); ++i)
            cout << kanan[i] << " ";
        cout << endl;
        string ans;
        cin >> ans;
        if(ans == "KIRI")
        {
            if(kiri.size() == 1)
            {
                cout << '!' << " " << kiri[0] << endl;
                break;
            }
            else
            {
                kanan.clear();
                int delcount = kiri.size() / 2;
                for(int i = delcount; i < kiri.size(); ++i)
                    kanan.push_back(kiri[i]);
                for(int i = delcount; i < 2 * delcount; ++i)
                    kiri.pop_back();
            }
        }
        else
        {
            if(kanan.size() == 1)
            {
                cout << '!' << " " << kanan[0] << endl;
                break;
            }
            else
            {
                kiri.clear();
                int delcount = kanan.size() / 2;
                for(int i = delcount; i < kanan.size(); ++i)
                    kiri.push_back(kanan[i]);
                for(int i = delcount; i < 2 * delcount; ++i)
                    kanan.pop_back();
            }
        }
    }
    return 0;
}