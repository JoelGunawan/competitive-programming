#include <bits/stdc++.h>
using namespace std;
ifstream fin; ofstream fout;
void tc_1()
{
    // kuli

}
void tc_2()
{
    // kuli
}
void tc_3()
{
    // just do line
    int cur = 0, n, m, k;
    fin >> n >> m >> k;
    int a[k];
    for(int i = 0; i < k; ++i)
    {
        fin >> a[i];
        fout << 0 << " " << 1 << " " << cur << " " << a[i] + cur << endl;
        cur += a[i];
    }
}
void tc_4()
{
    int n, m, k;
    fin >> n >> m >> k;
    pair<pair<int, int>, pair<int ,int>> res[k];
    int lim = 99999;
    for(int i = 0; i < m; ++i)
    {
        if(i == 0)
            res[lim - 1] = {{0, lim}, {i, i + 1}};
        else
            res[i - 1] = {{0, i}, {i, i + 1}}, res[lim - i - 1] = {{i, 99999}, {i, i + 1}};
    }
    for(int i = 0; i < k; ++i)
        fout << res[i].first.first << " " << res[i].first.second << " " << res[i].second.first << " " << res[i].second.second << endl;
}
void tc_5()
{
    int n, m, k;
    fin >> n >> m >> k;
    int n_mul = 9973, m_mul = 99991, n_cnt = 293, m_cnt = 311;
    for(int i = 0; i < k; ++i)
    {
        fout << i % n_cnt * n_mul << " " << i % n_cnt * n_mul + n_mul << " " << i / n_cnt * m_mul  << " " << i / n_cnt * m_mul + m_mul << endl;
    }
}
void tc_6()
{
    // brute force all subsets
    
}
void tc_7()
{

}
void tc_8()
{

}
void tc_9()
{
    
}
void tc_10()
{

}
int main()
{
    for(int i = 1; i <= 10; ++i)
    {
        if(i == 1 || i == 2)
            continue;
        fin.open("./pertahanan_negara/inputs/pertahanan_" + to_string(i) + ".in");
        fout.open("./pertahanan_negara/outputs/pertahanan_" + to_string(i) + ".out");
        if(i == 1)
            tc_1();
        else if(i == 2)
            tc_2();
        else if(i == 3)
            tc_3();
        else if(i == 4)
            tc_4();
        else if(i == 5)
            tc_5();
        else if(i == 6 || i == 7)
            tc_7();
        else if(i == 8)
            tc_8();
        else if(i == 9)
            tc_9();
        else
            tc_10();
        fin.close(), fout.close();
    }
    return 0;
}