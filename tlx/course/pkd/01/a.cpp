#include <bits/stdc++.h>
using namespace std;
struct peserta
{
    string id;
    int sesi_1, sesi_2, sesi_3;
};
bool compare_peserta(peserta a, peserta b)
{
    if(a.sesi_3 != b.sesi_3)
        return a.sesi_3 > b.sesi_3;
    else if(a.sesi_2 != b.sesi_2)
        return a.sesi_2 > b.sesi_2;
    else
        return a.sesi_1 > b.sesi_1;
}
void test_case()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    peserta arr[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i].id >> arr[i].sesi_1 >> arr[i].sesi_2 >> arr[i].sesi_3;
    sort(arr, arr + n, compare_peserta);
    int idx;
    for(int i = 0; i < n; ++i)
    {
        //cout << arr[i].id << endl;
        if(arr[i].id == s)
            idx = i;
    }
    if(idx < m)
        cout << "YA" << endl;
    else
        cout << "TIDAK" << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}