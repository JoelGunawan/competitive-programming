#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(i != 0) arr[i] += arr[i-1];
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int query;
        scanf("%d", &query);
        printf("%d\n", (lower_bound(arr.begin(), arr.end(), query)) - arr.begin() + 1);
    }
    return 0;
}
