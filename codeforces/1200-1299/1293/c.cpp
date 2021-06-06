#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

set<pair<int, int>> active, blocking;

void block(int r, int c)
{
    if(active.find(mp(r, c)) == active.end())
        return;
    if(active.find(mp(r + 1, c + 1)) == active.end()
       && active.find(mp(r + 1, c)) == active.end()
       && active.find(mp(r + 1, c - 1)) == active.end()
       && active.find(mp(r - 1, c + 1)) == active.end()
       && active.find(mp(r - 1, c)) == active.end()
       && active.find(mp(r - 1, c - 1)) == active.end()
       )
    {
        if(blocking.find(mp(r, c)) != blocking.end())
            blocking.erase(*blocking.find(mp(r, c)));
    }
    else
        blocking.insert(mp(r, c));
}

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < q; ++i)
    {
        int r, c;
        cin >> r >> c;
        pair<int, int> cur = make_pair(r, c);
        if(active.find(cur) != active.end())
        {
            active.erase(*active.find(cur));
            if(blocking.find(cur) != blocking.end())
                blocking.erase(*blocking.find(cur));
            // check whether there is an element adjacent that this object is blocking
            block(r + 1, c + 1);
            block(r + 1, c);
            block(r + 1, c - 1);
            block(r - 1, c + 1);
            block(r - 1, c);
            block(r - 1, c - 1);
        }
        else
        {
            active.insert(cur);
            // check adjacent (horizontal, vertical, diagonal
            block(r, c);
        }
        if(blocking.size() > 0)
            cout << "No";
        else
            cout << "Yes";
        cout << endl;
    }
    return 0;
}
