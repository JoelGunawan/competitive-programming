#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> res(25, 0);
    for(int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        if((s[s.size() - 1] - '0') & 1)
        {
            for(int i = 0; i < s.size(); ++i)
                res[s.size() - i - 1] -= (s[i] - '0');
        }
        else
        {
            for(int i = 0; i < s.size(); ++i)
                res[s.size() - i - 1] += (s[i] - '0');
        }
    }
    for(int i = 0; i < 23; ++i)
    {
        int carry = res[i] / 10;
        res[i] %= 10;
        res[i + 1] += carry;
    }
    bool positive = 0, zero = 1;
    for(int i = 24; i >= 0; --i)
    {
        if(res[i] != 0)
        {
            zero = 0;
            if(res[i] > 0)
                positive = 1;
            else if(res[i] < 0)
                positive = 0;
            break;
        }
    }
    if(zero)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {    
        if(positive)
        {
            for(int i = 0; i < 23; ++i)
            {
                if(res[i] < 0)
                    res[i] += 10, --res[i + 1];
            }
        }
        else
        {
            for(int i = 0; i < 23; ++i)
                if(res[i] > 0)
                    res[i] -= 10, ++res[i + 1];
            cout << '-';
        }
        bool start = 0;
        for(int i = 24; i >= 0; --i)
            if(start)
                cout << abs(res[i]);
            else if(res[i])
                start = 1, cout << abs(res[i]);
        cout << endl;
    }
    return 0;
}