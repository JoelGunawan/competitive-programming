#include <bits/stdc++.h>
using namespace std;
int query(int left, int right)
{
    cout << "? " << left << " " << right << endl;
    int input;
    cin >> input;
    return input;
}
int main()
{
    int t, n, q;
    cin >> t >> n >> q;
    int color[n]; color[0] = 1;
    if(t <= 2)
    {
        for(int i = 0; i < n; ++i)
            color[i] = query(1, i + 1);
    }
    else if(t <= 4)
    {
        int color_counter = 1;
        for(int i = 1; i < n; ++i)
        {
            // binser previous colors
            if(color_counter == 1)
            {
                color[i] = query(1, i + 1);
                if(color[i] > 1)
                    ++color_counter;
            }   
            else
            {
                // binser previous colors
                int left = 1, right = min(4, color_counter + 1);
                bool used[5];
                while(left < right)
                {
                    memset(used, 0, sizeof(used));
                    int mid = (left + right) / 2, cnt = 0, idx;
                    // find an index such that there is a mid amount of colors
                    for(int j = i - 1; j >= 0; --j)
                    {
                        if(!used[color[j]])
                            used[color[j]] = 1, ++cnt;
                        if(cnt == mid)
                        {
                            idx = j;
                            break;
                        }
                    }
                    if(query(idx + 1, i + 1) == mid)
                        right = mid;
                    else
                        left = mid + 1;
                }
                if(left > color_counter)
                    color[i] = ++color_counter;
                else
                {
                    // find the ith color from the current index, where i = left
                    memset(used, 0, sizeof(used));
                    int cnt = 0;
                    for(int j = i - 1; j >= 0; --j)
                    {
                        if(!used[color[j]])
                            used[color[j]] = 1, ++cnt;
                        if(cnt == left)
                        {
                            color[i] = color[j];
                            break;
                        }
                    }
                }
            }
        }
    }
    else if(t <= 5)
    {
        // use 2 pointers to find in O(n)
        if(query(1, n) == n)
        {
            for(int i = 1; i < n; ++i)
                color[i] = i + 1;
        }
        else
        {
            int prev = 0, left, right;
            for(int i = 1; i < n; ++i)
            {
                ++prev;
                if(query(1, i + 1) == prev)
                {
                    right = i;
                    break;
                }
            }
            prev = 0;
            for(int i = n - 2; i >= 0; --i)
            {
                ++prev;
                if(query(i + 1, n) == prev)
                {
                    left = i;
                    break;
                }
            }
            int cur_color = 1;
            for(int i = 0; i < n; ++i)
            {
                if(i == right)
                    color[i] = color[left];
                else
                    color[i] = cur_color++;
            }
        }
    }
    else
    {
        bool used[n + 1];
        int color_counter = 1;
        for(int i = 1; i < n; ++i)
        {
            // binser previous colors
            int left = 1, right = color_counter + 1;
            // do binser
            while(left < right)
            {
                memset(used, 0, sizeof(used));
                int mid = (left + right) / 2, cnt = 0, idx;
                for(int j = i - 1; j >= 0; --j)
                {
                    if(!used[color[j]])
                        ++cnt, used[color[j]] = 1;
                    if(cnt == mid)
                    {
                        idx = j;
                        break;
                    }
                }
                if(query(idx + 1, i + 1) == mid)
                    right = mid;
                else
                    left = mid + 1;
            }
            if(left == color_counter + 1)
                color[i] = ++color_counter;
            else
            {
                int cnt = 0;
                memset(used, 0, sizeof(used));
                for(int j = i - 1; j >= 0; --j)
                {
                    if(!used[color[j]])
                        ++cnt, used[color[j]] =  1;
                    if(cnt == left)
                    {
                        color[i] = color[j];
                        break;
                    }
                }
            }
        }
    }
    cout << "! ";
    for(int i = 0; i < n; ++i)
        cout << color[i] << " ";
    cout << endl;
    return 0;
}
