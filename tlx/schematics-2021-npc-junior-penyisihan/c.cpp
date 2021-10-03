#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define pb push_back
using namespace std;
int main()
{
    int t;
    cin >> t;
    int counter[10000]; memset(counter, 0, sizeof(counter));
    while(t--)
    {
        string s; int k;
        cin >> s >> k;
        s = s.substr(1, 4);
        set<int> add;
        for(int i = 2; i <= 4; ++i)
        {
            for(int j = 0; j <= 4 - i; ++j)
                add.insert(stoi(s.substr(j, i)));
        }
        for(auto it = add.begin(); it != add.end(); ++it)
            counter[*it] += k;
    }
    int max = 0, num;
    for(int i = 10; i < 10000; ++i)
        if(counter[i] >= max)
            max = counter[i], num = i;
    cout << "V" << num << endl;
    return 0;
}