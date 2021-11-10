#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int query(int left, int right)
{
    cout << "? " << left << " " << right << endl;
    int input;
    cin >> input;
    return input;
}
int mod = 1e9 + 7;
int main()
{
    fast_io();
    int t, n, q;
    cin >> t >> n >> q;
    if(t <= 2)
    {
        // binser every number
        int color[n], input; memset(color, 0, sizeof(color));
        for(int i = 0; i < n; ++i)
        {
            cout << "? " << 1 << " " << i + 1 << endl;
            cin >> input;
            color[i] = input;
        }
        cout << "! ";
        for(int i = 0; i < n; ++i)
            cout << color[i] << " ";
        cout << endl;
    }
    else if(t == 3)
    {
        int cur_color = 1, color[n], input; memset(color, 0, sizeof(color));
        color[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            cout << "? " << i << " " << i + 1 << endl;
            cin >> input;
            if(input == 1)
                color[i] = color[i - 1];
            else
            {
                if(cur_color == 1)
                    color[i] = 2, ++cur_color;
                else
                {
                    // check first previous color
                    // that is not the direct previous
                    int idx;
                    for(int j = i - 2; j >= 0; --j)
                        if(color[j] != color[i - 1])
                        {
                            idx = j;
                            break;
                        }
                    cout << "? " << idx + 1 << " " << i + 1 << endl;
                    cin >> input;
                    if(input == 2)
                        color[i] = color[idx];
                    else
                    {
                        set<int> tmp;
                        tmp.insert(color[idx]), tmp.insert(color[i - 1]);
                        if(tmp.find(1) == tmp.end())
                            color[i] = 1;
                        else if(tmp.find(2) == tmp.end())
                            color[i] = 2;
                        else
                            color[i] = 3;
                    }
                }
            }
        }
        cout << "! ";
        for(int i = 0; i < n; ++i)
            cout << color[i] << " ";
        cout << endl;
    }
    else if(t == 4)
    {
        int cur_color = 2, color[n], input; color[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            if(cur_color == 2)
            {
                input = query(i, i + 1);   
                if(input == 1)
                    color[i] = color[i - 1];
                else
                    color[i] = cur_color++;
            }
            else
            {
                // query from previous 2 colors and find input
                set<int> cur;
                int idx = 0;
                for(int j = i - 1; j >= 0; --j)
                {
                    idx = j;
                    if(cur.find(color[j]) == cur.end())
                        cur.insert(color[j]);
                    if(cur.size() == 2)
                        break;
                }
                input = query(idx + 1, i + 1);
                if(input == 3)
                {
                    if(cur_color == 3)
                        color[i] = cur_color++;
                    else
                    {
                        // find previous color that is different
                        int idx_2;
                        for(int j = idx - 1; j >= 0; --j)
                        {
                            idx_2 = j;
                            if(cur.find(color[j]) == cur.end())
                                cur.insert(color[j]);
                            if(cur.size() == 3)
                                break;
                        }
                        input = query(idx_2 + 1, i + 1);
                        if(input == 3)
                            color[i] = color[idx_2];
                        else
                        {
                            if(cur.find(1) == cur.end())
                                color[i] = 1;
                            else if(cur.find(2) == cur.end())
                                color[i] = 2;
                            else if(cur.find(3) == cur.end())
                                color[i] = 3;
                            else
                                color[i] = 4;
                        }
                    }
                }
                else
                {
                    input = query(i, i + 1);
                    if(input == 1)
                        color[i] = color[i - 1];
                    else
                    {
                        for(auto it = cur.begin(); it != cur.end(); ++it)
                            if(*it != color[i - 1])
                                color[i] = *it;
                    }
                }
            }
        }
        cout << "! ";
        for(int i = 0; i < n; ++i)
            cout << color[i] << " ";
        cout << endl;
    }
    else if(t == 5)
    {
        // n - 1 items means we only need to find 2 indices such that the amount of unique items in those 2 L and R equals to N - 1
        // use 2 pointers
        // first check the entire array first
        int input, color[n];
        cout << "? " << 1 << " " << n << endl;
        cin >> input;
        if(input == n)
        {
            cout << "! ";
            for(int i = 0; i < n; ++i)
                cout << i + 1 << " ";
            cout << endl;
            return 0;
        }
        int left = 1, right = n, prev = n - 1;
        while(true)
        {
            cout << "? " << left << " " << right - 1 << endl;
            cin >> input;
            if(input == prev)
                break;
            else
                --right, prev = input;
        }
        while(true)
        {
            cout << "? " << left + 1 << " " << right << endl;
            cin >> input;
            if(input == prev)
                break;
            else
                ++left, prev = input;
        }
        int cur_color = 2;
        color[left - 1] = 1, color[right - 1] = 1;
        for(int i = 0; i < n; ++i)
        {
            if(i != left - 1 && i != right - 1)
                color[i] = cur_color++;
        }
        cout << "! ";
        for(int i = 0; i < n; ++i)
            cout << color[i] << " ";
        cout << endl;
    }
    else if(t == 6)
    {
        // do O(n^2) algo
        int cur_color = 2, input, color[n];
        memset(color, 0, sizeof(color));
        color[0] = 1;
        bool vis[n + 1]; memset(vis, 0, sizeof(vis));
        for(int i = 1; i < n; ++i)
        {
            int prev = 1;
            set<int> cur;
            for(int j = i - 1; j >= 0; --j)
            {
                input = query(j + 1, i + 1);
                if(input == prev && !vis[color[j]])
                {
                    color[i] = color[j];
                    break;
                }
                vis[color[j]] = 1;
                prev = input;
            }
            memset(vis, 0, sizeof(vis));
            if(color[i] == 0)
                color[i] = cur_color++;
        }
        cout << "! ";
        for(int i = 0; i < n; ++i)
            cout << color[i] << " ";
        cout << endl;
    }
    else
    {
        int color_cnt = 1, color[n], input;
        memset(color, 0, sizeof(color));
        for(int i = 1; i < n; ++i)
        {
            // there are color_cnt previous colors
            // select ceil(color_cnt / 2.0) colors and check whether our new color is within that range, if it is not
            // then try the other colors
            input = query(1, i + 1);
            if(input > color_cnt)
                color[i] = ++color_cnt;
            else
            {
                // the color has been used before and we need to bsta
                // how to not case bash?
                int left = 1, right = color_cnt;
                while(left < right)
                {
                    int mid = (left + right) / 2;
                    
                }
            }
        }
    }
    return 0;
}