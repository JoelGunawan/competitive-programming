#include <bits/stdc++.h>
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    string subsoal; int n;
    cin >> subsoal >> n;
    vector<vector<int>> res(5, vector<int>(5, 0));
    if(n == 25)
    {
        // n = 25
        res[0][0] = 1;
        int in;
        for(int i = 0; i < 4; ++i)
        {
            cout << "KANAN" << endl;
            cin >> in;
            res[i + 1][0] = in;
        }
        cout << "KANAN" << endl;
        cin >> in;
        for(int i = 0; i < 4; ++i)
        {
            cout << "BAWAH" << endl;
            cin >> in;
            res[0][i + 1] = in;
            for(int j = 0; j < 4; ++j)
            {
                cout << "KANAN" << endl;
                cin >> in;
                res[j + 1][i + 1] = in;
            }
            cout << "KANAN" << endl;
            cin >> in;
        }
    }
    else if(subsoal[2] == '2')
    {
        // n = 2 with the case in the problem
        res[0][0] = 9;                  res[2][0] = 1; res[3][0] = 5;
        res[0][1] = 10; res[1][1] = 18; res[2][1] = 2; res[3][1] = 6; res[4][1] = 16;
        res[0][2] = 11; res[1][2] = 19; res[2][2] = 3;                res[4][2] = 17;
        res[0][3] = 12; res[1][3] = 20; res[2][3] = 4; res[3][3] = 7; res[4][3] = 14;
        res[0][4] = 13; res[1][4] = 21;                res[3][4] = 8; res[4][4] = 15;
    }
    else if(subsoal[4] == '4')
    {
        // n = 24
        // find the empty one
        // do vertical lines
        int x, y, in = 1;
        vector<vector<int>> horizontal, vertical;
        vector<int> tmp;
        for(int i = 0; i < 5; ++i)
        {
            while(tmp.size() == 0 || in != tmp[0])
            {
                tmp.push_back(in);
                cout << "KANAN" << endl;
                cin >> in;
            }
            horizontal.push_back(tmp);
            tmp.clear();
            cout << "BAWAH" << endl;
            cin >> in;
        }
        if(in != horizontal[0][0])
        {
            // it's either 0, 0 is empty or 0, 4 is empty
            x = 0;
            if(in == horizontal[1][0])
                y = 4;
            else
                y = 0;
        }
        else
        {
            // we need to find the verticals
            // if the size of first row is not 5, we can go to the 5th row
            if(horizontal[0].size() == 4)
            {
                cout << "ATAS" << endl;
                cin >> in;
                // do line 5 first and base everything of line 5
                for(int i = 0; i < 5; ++i)
                {
                    while(tmp.size() == 0 || in != tmp[0])
                    {
                        tmp.push_back(in);
                        cout << "BAWAH" << endl;
                        cin >> in;
                    }
                    // move first element to back
                    tmp.push_back(tmp[0]);
                    tmp.erase(tmp.begin());
                    vertical.push_back(tmp);
                    cout << "KANAN" << endl;
                    cin >> in;
                }
            }
            else
            {
                for(int i = 0; i < 5; ++i)
                {
                    while(tmp.size() == 0 || in != tmp[0])
                    {
                        tmp.push_back(in);
                        cout << "BAWAH" << endl;
                        cin >> in;
                    }
                    vertical.push_back(tmp);
                    tmp.clear();
                    cout << "KANAN" << endl;
                    cin >> in;
                }
            }
            for(int i = 0; i < 5; ++i)
            {
                if(horizontal[i].size() < 5)
                {
                    y = i;
                    break;
                }
            }
            for(int i = 0; i < 5; ++i)
            {
                if(vertical[i].size() < 5)
                {
                    x = i;
                    break;
                }
            }
            for(int i = 0; i < 5; ++i)
            {
                int index = 0;
                for(int j = 0; j < 5; ++j)
                {
                    if(i == x && j == y)
                        continue;
                    res[j][i] = horizontal[i][index];
                    ++index;
                }
            }
        }
    }
    else if(subsoal[5] == '5')
    {
        // 1 <= n <= 4
        int in;
        if(n == 1)
            res[0][0] = 1;
        else if(n == 2)
        {
            // we just need to check for horizontal and vertical
            cout << "KANAN" << endl;
            cin >> in;
            if(in != 1)
            {
                res[0][0] = 1; res[1][0] = in;
            }
            else
            {
                cout << "BAWAH" << endl;
                cin >> in;
                if(in != 1)
                {
                    res[0][0] = 1; res[0][1] = in;
                }
                else
                {
                    res[0][0] = 1; res[1][1] = 2;
                }
            }
        }
    }
    else if(subsoal[6] == '6')
    {
        // there is one line that has 5 ints
    }

    cout << "JAWAB" << endl;
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
            cout << res[j][i] << " ";
        cout << endl;
    }
}