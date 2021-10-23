#include <bits/stdc++.h>
using namespace std;
bool a[128][128];
void decode(int x_1, int y_1, int x_2, int y_2, string code)
{
    if(code.size() == 0)
    {
        for(int i = x_1; i < x_2; ++i)
            for(int j = y_1; j < y_2; ++j)
                a[i][j] = 1;
    }
    else
    {
        char tmp = code[code.size() - 1];
        code.pop_back();
        int x_mid = (x_1 + x_2) / 2, y_mid = (y_1 + y_2) / 2;
        if(tmp == '0')
            x_2 = x_mid, y_2 = y_mid;
        else if(tmp == '1')
            x_2 = x_mid, y_1 = y_mid;
        else if(tmp == '2')
            x_1 = x_mid, y_2 = y_mid;
        else if(tmp == '3')
            x_1 = x_mid, y_1 = y_mid;
        decode(x_1, y_1, x_2, y_2, code);
    }
}
int main()
{
    int n;
    cin >> n;
    string res[n];
    for(int i = 0; i < n; ++i)
        cin >> res[i], res[i] = res[i].substr(1, res[i].size() - 1), reverse(res[i].begin(), res[i].end());
    int r, c;
    cin >> r >> c;
    int tmp_size = 1;
    while(tmp_size < max(r, c))
        tmp_size *= 2;
    for(int i = 0; i < n; ++i)
        decode(0, 0, tmp_size, tmp_size, res[i]);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
            cout << (int)a[i][j] << " ";
        cout << endl;
    }
    return 0;
}