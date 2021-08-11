#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> v, o;
    bool isv;
    if(s[0] == 'v')
        isv = 1;
    else
        isv = 0;
    int streak = 0;
    string t = "";
    for(int i = 0; i < s.size(); ++i)
    {
        if(isv && s[i] == 'o')
            v.push_back(streak - 1), streak = 1, t += "v", isv = 0;
        else if(isv && s[i] == 'v')
            ++streak;
        else if(s[i] == 'o')
            ++streak;
        else
            o.push_back(streak), streak = 1, t += "o", isv = 1;
    }
    if(isv)
        v.push_back(streak - 1), t += "v";
    else
        o.push_back(streak), t += "o";
    int prevv = 0, allv = 0;
    for(int i = 0; i < v.size(); ++i)
        allv += v[i];
    long long res = 0;
    int oindex = 0, vindex = 0;
    for(int i = 0; i < t.size(); ++i)
    {
        if(t[i] == 'o')
            res += (long long)prevv * (o[oindex]) * (long long)(allv - prevv), ++oindex;
        else
            prevv += v[vindex], ++vindex;
    }
    cout << res << endl;
}