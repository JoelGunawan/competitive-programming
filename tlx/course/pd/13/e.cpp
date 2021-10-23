#include <bits/stdc++.h>
using namespace std;
int r, c, a[128][128];
vector<string> res;
void divide(int x_1, int y_1, int x_2, int y_2, string code)
{
    bool all_one = 1, all_zero = 1;
    for(int i = x_1; i < x_2; ++i)
        for(int j = y_1; j < y_2; ++j)
        {
            if(a[i][j] == 1)
                all_zero = 0;
            else
                all_one = 0;
        }
    if(all_one)
    {
        res.push_back("1" + code);
        return;
    }
    else if(!all_zero)
    {
        // x2, y2
        int x_mid = (x_1 + x_2) / 2, y_mid = (y_1 + y_2) / 2;
        divide(x_1, y_1, x_mid, y_mid, code + "0");
        // x1, y2
        divide(x_mid, y_1, x_2, y_mid, code + "2");
        // x2, y1
        divide(x_1, y_mid, x_mid, y_2, code + "1");
        // x1, y1
        divide(x_mid, y_mid, x_2, y_2, code + "3");
    }
}
int main()
{
    vector<int> power_of_two = {1};
    while(power_of_two[power_of_two.size() - 1] < 128)
        power_of_two.push_back(power_of_two[power_of_two.size() - 1] * 2);
    cin >> r >> c;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            cin >> a[i][j];
    r = *lower_bound(power_of_two.begin(), power_of_two.end(), max(r, c));
    divide(0, 0, r, r, "");
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}