#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
void rotate(vector<pair<int, int>> &a)
{
    for(int i = 0; i < a.size(); ++i)
    {
        //cout << "TC" << endl;
        //cout << a[i].first << " " << a[i].second << endl;
        int tmp1 = a[i].first;
        a[i].first = -a[i].second;
        a[i].second = tmp1;
        //cout << a[i].first << " " << a[i].second << endl;
    }
}
bool check(vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    for(int j = 0; j < 4; ++j)
    {
        // rotates 90 degrees
        rotate(a);
        sort(a.begin(), a.end());
        cout << "TEST" << endl;
        for(int i = 0; i < a.size(); ++i)
            cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << endl;
        bool possible = 1;
        int x = b[0].first - a[0].first, y = b[0].second - a[0].second;
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i].first + x != b[i].first || a[i].second + y != b[i].second)
            {
                possible = 0;
                break;
            }
        }
        if(possible)
            return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, in1, in2;
    cin >> n;
    if(n == 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    vector<pair<int, int>> a(n), b(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2;
        a[i] = make_pair(in1, in2);
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2;
        b[i] = make_pair(in1, in2);
    }
    // check for each number pair if it is a pythagorean theorem
    // if all is a pythagorean theorem (only valid is h = 5 || h = 10) we check for 8 angles, else we check for 4 angles
    string ans = "No";
    sort(b.begin(), b.end());
    // try rotate, if for all of them the relative points it the same, then it is correct
    sort(a.begin(), a.end());
    if(check(a, b))
        ans = "Yes";
    vector<pair<int, int>> backup = a;
    // try to rotate everything by 37 or 53 degrees
    // how do you rotate?
    // brute force???
    // rotate type 1
    bool possible = 1;
    for(int i = 0; i < n; ++i)
    {
        if(a[i].first == 0)
        {
            if(a[i].second == 10)
            {
                a[i].first = 8;
                a[i].second = 6;
            }
            else if(a[i].second == 5)
            {
                a[i].first = 4;
                a[i].second = 3;
            }
            else if(a[i].second == -5)
            {
                a[i].first = -4;
                a[i].second = -3;
            }
            else if(a[i].second == -10)
            {
                a[i].first = -8;
                a[i].second = -6;
            }
            else
            {
                possible = 0;
                break;
            }
        }
        else if(a[i].second == 0)
        {
            if(a[i].first == 10)
            {
                a[i].first = 6;
                a[i].second = -8;
            }
            else if(a[i].first == 5)
            {
                a[i].first = 3;
                a[i].second = -4;
            }
            else if(a[i].first == -5)
            {
                a[i].first = -3;
                a[i].second = 4;
            }
            else if(a[i].first == -10)
            {
                a[i].first = -6;
                a[i].second = 8;
            }
            else
            {
                possible = 0;
                break;
            }
        }
        else
        {
            if(a[i].first == 6 && a[i].second == 8)
            {
                a[i].first = 10;
                a[i].second = 0;
            }
            else if(a[i].first == 3 && a[i].second == 4)
            {
                a[i].first = 5;
                a[i].second = 0;
            }
            else if(a[i].first == -6 && a[i].second == -8)
            {
                a[i].first = -10;
                a[i].second = 0;
            }
            else if(a[i].first == -3 && a[i].second == -4)
            {
                a[i].first = -5;
                a[i].second = 0;
            }
            else if(a[i].first == 8 && a[i].second == -6)
            {
                a[i].first = 0;
                a[i].second = -10;
            }
            else if(a[i].first == 4 && a[i].second == -3)
            {
                a[i].first = 0;
                a[i].second = -5;
            }
            else if(a[i].first == -8 && a[i].second == 6)
            {
                a[i].first = 0;
                a[i].second = 10;
            }
            else if(a[i].first == -4 && a[i].second == 3)
            {
                a[i].first = 0;
                a[i].second = 5;
            }
            else
            {
                possible = 0;
                break;
            }
        }
    }
    if(possible && check(a, b))
        ans = "Yes";
    possible = 1;
    a = backup;
    // we need to set for all 8 possible points the rotation value
    for(int i = 0; i < n; ++i)
    {
        if(a[i].first == 0)
        {
            if(a[i].second == 10)
            {
                a[i].first = 6;
                a[i].second = 8;
            }
            else if(a[i].second == 5)
            {
                a[i].first = 3;
                a[i].second = 4;
            }
            else if(a[i].second == -5)
            {
                a[i].first = -3;
                a[i].second = -4;
            }
            else if(a[i].second == -10)
            {
                a[i].first = -6;
                a[i].second = -8;
            }
            else
            {
                possible = 0;
                break;
            }
        }
        else if(a[i].second == 0)
        {
            if(a[i].first == 10)
            {
                a[i].first = 8;
                a[i].second = -6;
            }
            else if(a[i].first == 5)
            {
                a[i].first = 4;
                a[i].second = -3;
            }
            else if(a[i].first == -5)
            {
                a[i].first = 3;
                a[i].second = -4;
            }
            else if(a[i].first == -10)
            {
                a[i].first = -8;
                a[i].second = 6;
            }
            else
            {
                possible = 0;
                break;
            }
        }
        else
        {
            if(a[i].first == 8 && a[i].second == 6)
            {
                a[i].first = 10;
                a[i].second = 0;
            }
            else if(a[i].first == 4 && a[i].second == 3)
            {
                a[i].first = 5;
                a[i].second = 0;
            }
            else if(a[i].first == -8 && a[i].second == -6)
            {
                a[i].first = -10;
                a[i].second = 0;
            }
            else if(a[i].first == -4 && a[i].second == -3)
            {
                a[i].first = -5;
                a[i].second = 0;
            }
            else if(a[i].first == 6 && a[i].second == -8)
            {
                a[i].first = 0;
                a[i].second = -10;
            }
            else if(a[i].first == 3 && a[i].second == -4)
            {
                a[i].first = 0;
                a[i].second = -5;
            }
            else if(a[i].first == -6 && a[i].second == 8)
            {
                a[i].first = 0;
                a[i].second = 10;
            }
            else if(a[i].first == -3 && a[i].second == 4)
            {
                a[i].first = 0;
                a[i].second = 5;
            }
            else
            {
                possible = 0;
                break;
            }
        }
    }
    if(possible && check(a, b))
        ans = "Yes";
    // rotate again
    cout << ans << endl;
    return 0;
}