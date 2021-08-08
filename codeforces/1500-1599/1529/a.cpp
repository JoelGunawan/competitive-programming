#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

void test_case()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int sum = 0, rightPointer = n - 1;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i)
        sum += a[i];
    int avg = sum / (rightPointer + 1);
    while(avg < a[rightPointer])
    {
        while(a[rightPointer] > avg)
        {
            sum -= a[rightPointer];
            --rightPointer;
        }
        avg = sum / (rightPointer + 1);
    }
    cout << n - rightPointer - 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}