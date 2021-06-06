#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<string> a;
    string in;
    for(int i = 0; i < n; ++i)
    {
        cin >> in;
        a.insert(in);
    }
    deque<string> res;
    auto it = a.begin(), previt = a.begin();
    while(it != a.end())
    {
        string x = *it, y = *it;
        reverse(x.begin(), x.end());
        if(x == y)
        {
            if(a.count(x) > 1)
            {
                res.push_front(y); res.push_back(y);
                if(it == a.begin())
                {
                    a.erase(it++);
                    a.erase(it);
                    it = a.begin();
                }
                else
                {
                    a.erase(it++);
                    a.erase(it);
                    it = previt;
                }
            }
            else
                previt = it++;
        }
        else
        {
            if(a.find(x) != a.end())
            {

                res.push_front(y); res.push_back(x);
                if(it == a.begin())
                {
                    a.erase(it);
                    a.erase(a.find(x));
                    it = a.begin();
                }
                else
                {
                    a.erase(it);
                    a.erase(a.find(x));
                    it = previt;
                }
            }
            else
                previt = it++;
        }
    }
    // find a palindrome
    string add = "";
    for(auto i = a.begin(); i != a.end(); ++i)
    {
        string x = *i;
        reverse(x.begin(), x.end());
        if(x == *i)
        {
            add = x;
            break;
        }
    }
    cout << add.size() + res.size() * m << endl;
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i];
        if(i == res.size() / 2 - 1)
            cout << add;
    }
    if(res.size() == 0)
        cout << add;
    return 0;
}
