#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ins insert
#define pf push_front
using namespace std;
int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    // solve for S only movement
    bool arr[x][y];
    memset(arr, 1, sizeof(arr));
    int leftx = 0, rightx = x, lefty = 0, righty = y;
    while(true)
    {
        int midx = (leftx + rightx) / 2, midy = (lefty + righty) / 2;
        cout << '?' << midx << " " << midy << endl;
        int type; char move;
        cin >> type >> move;
        // up
        if(type == 1 || type == 2)
        {
            lefty = midy;
            for(int i = 0; i <= midy; ++i)
            {
                for(int j = 0; j < x; ++j)
                    arr[j][i] = 0;
            }
        }
        else
        {
            righty = midy;
            for(int i = midy + 1; i < y; ++i)
                for(int j = 0; j < x; ++j)
                    arr[j][i] = 0;
        }
        // left
        if(type == 2 || type == 3)
        {
            rightx = midx;
            for(int i = 0; i <= midx; ++i)
            {
                for(int j = 0; j < y; ++j)
                    arr[i][j] = 0;
            }
        }
        else
        { 
            leftx = midx;
            for(int i = midx + 1; i < x; ++i)
                for(int j = 0; j < y; ++j)
                    arr[i][j] = 0;
        }
        int validpos = 0;
        for(int i = 0; i < x; ++i)
            for(int j = 0; j < y; ++j)
                if(arr[x][y])
                    ++validpos;
        if(validpos == 1)
            break;
    }
    for(int i = 0; i < x; ++i)
        for(int j = 0; j < y; ++j)
            if(arr[x][y])
                cout << '!' << " " << i + 1 << " " << j + 1 << endl;
    return 0;
}