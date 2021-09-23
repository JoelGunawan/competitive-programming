#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], nomor[n];
    int firstindex, secondindex;
    for(int i = 0; i < n; ++i)
    {
        int cur, curharga = 0;
        cin >> cur;
        nomor[i] = cur;
        while(cur > 0)
            curharga += cur % 10, cur /= 10;
        a[i] = curharga;
    }
    // selisih angka terkecil
    // harga terkecil
    // indeks terkecil
    int mindiff = INT_MAX, price;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
        {
            if(abs(a[j] - a[i]) < mindiff)
            {
                mindiff = abs(a[j] - a[i]);
                firstindex = i, secondindex = j;
                price = min(a[i], a[j]);
            }
            else if(abs(a[j] - a[i]) == mindiff)
            {
                if(price > min(a[i], a[j]))
                {
                    mindiff = abs(a[j] - a[i]);
                    firstindex = i, secondindex = j;
                    price = min(a[i], a[j]);
                }
            }
        }
    // choose to output firstindex or secondindex first
    if(a[firstindex] <= a[secondindex])
        // output the firstindex first
        cout << a[firstindex] << " " << firstindex << " " << nomor[firstindex] << endl << a[secondindex] << " " << secondindex << " " << nomor[secondindex] << endl; 
    else
        cout << a[secondindex] << " " << secondindex << " " << nomor[secondindex] << endl << a[firstindex] << " " << firstindex << " " << nomor[firstindex] << endl;
    return 0;
}