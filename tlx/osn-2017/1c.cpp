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
    if(subsoal[3] == '3')
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
        vector<string> vertical, horizontal;
        string tmp = "1";
        char in;
        cout << "KANAN" << endl;
        cin >> in;
        tmp += in;
        while(in != tmp[0])
        {
            cout << "KANAN" << endl;
            cin >> in;
            tmp += in;
        }
        horizontal.push_back(tmp);
        for(int i = 0; i < 4; ++i)
        {
            cout << "BAWAH" << endl;
            cin >> tmp;
            cout << "KANAN" << endl;
            cin >> in;
            while(in != tmp[0])
            {
                cout << "KANAN" << endl;
                cin >> in;
                tmp += in;
            }
            horizontal.push_back(tmp);
        }
    }
    else if(subsoal[5] == '5')
    {
        // 1 <= n <= 4
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