#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
ifstream fin; ofstream fout;
int row[8], column[8], arr[8][8], cur_row[8], cur_column[8], n;
bool used[65], done_row[8], done_column[8], solved;
void print_arr()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
bool check_sum()
{
    for(int i = 0; i < n; ++i)
    {
        /*cout << i << endl;
        cout << (int)done_row[i] << " " << row[i] << " " << cur_row[i] << endl;
        cout << (int)done_column[i] << " " << column[i] << " " << cur_column[i] << endl;
        print_arr();
        */
        if(done_row[i])
            if(cur_row[i] != row[i] && row[i] != INT_MAX)
                return 0;
        if(done_column[i])
            if(cur_column[i] != column[i] && column[i] != INT_MAX)
                return 0;
        if(cur_row[i] > row[i] || cur_column[i] > column[i])
            return 0;
    }
    return 1;
}
void brute(int x, int y)
{
    //cout << x << " " << y << endl;
    
    if(x == n - 1)
        done_column[y] = 1;
    if(y == n - 1)
        done_row[x] = 1;
    
    if(solved);
    else if(x == n - 1 && y == n - 1)
    {
        for(int i = 1; i <= n * n; ++i)
        {
            if(!used[i])
            {
                arr[x][y] = i, used[i] = 1, cur_row[x] += i, cur_column[y] += i;
                if(check_sum())
                {
                    solved = 1;
                    break;
                }
                used[i] = 0, cur_row[x] -= i, cur_column[y] -= i;
            }
        }
    }
    else if(row[x] == INT_MAX && column[y] == INT_MAX)
        brute((x + 1) % n, y + (x + 1) / n);
    else
    {
        for(int i = 1; i <= n * n; ++i)
        {
            if(!used[i])
            {
                arr[x][y] = i;
                used[i] = 1;
                cur_row[x] += i, cur_column[y] += i;
                if(check_sum())
                    brute((x + 1) % n, y + (x + 1) / n);
                cur_row[x] -= i, cur_column[y] -= i;
                if(!solved)
                    arr[x][y] = 0, used[i] = 0;
                else
                    break;
            }
        }
    }
    done_column[y] = 0, done_row[x] = 0;
}
void solve()
{
    memset(used, 0, sizeof(used)), memset(cur_row, 0, sizeof(cur_row)), memset(cur_column, 0, sizeof(cur_column)), memset(arr, 0, sizeof(arr));
    solved = 0;
    fin >> n;
    string input;
    for(int i = 0; i < n; ++i)
    {
        fin >> input;
        if(input == "-")
            row[i] = INT_MAX;
        else
            row[i] = stoi(input);
    }
    for(int i = 0; i < n; ++i)
    {
        fin >> input;
        if(input == "-")
            column[i] = INT_MAX;
        else
            column[i] = stoi(input);
    }
    // brute force solutions   
    brute(0, 0);
    int cur = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(arr[i][j])
                fout << arr[i][j];
            else
            {
                while(used[cur])
                    ++cur;
                used[cur] = 1;
                fout << cur;
            }
            fout << " ";
        }
        fout << endl;
    }
}
int main()
{
    for(int i = 1; i <= 5; ++i)
    {
        if(i == 3)
            continue;
        fin.open("./osn-2018-mejik/osn-2018-mejik_" + to_string(i) + ".in");
        fout.open("osn-2018-mejik_" + to_string(i) + ".out");
        solve();
        fin.close();
        fout.close();
    }
}