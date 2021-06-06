#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> init(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> init[i];
    }
    deque<int> screen;
    for(int i = 0; i < n; ++i)
    {
        bool found = false;
        for(int j = 0; j < screen.size(); ++j)
        {
            if(screen[j] == init[i])
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            continue;
        }
        else
        {
            if(screen.size() == k)
            {
                screen.push_front(init[i]);
                screen.pop_back();
            }
            else
            {
                screen.push_front(init[i]);
            }
        }
    }
    cout << screen.size() << endl;
    for(int i = 0; i < screen.size(); ++i)
    {
        cout << screen[i];
        if(i == n - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}
