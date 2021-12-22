#include <bits/stdc++.h>
using namespace std;
bool usedIndex[25][25] = {{false}};
int matrix[25][25] = {{0}};
int width, height;

int click(int x, int y)
{
    if(!usedIndex[x][y])
    {
        int result = 1;
        usedIndex[x][y] = true;
        if(x + 1 < width && matrix[x+1][y] == matrix[x][y]) result += click(x+1, y);
        if(x - 1 >= 0 && matrix[x-1][y] == matrix[x][y]) result += click(x-1, y);
        if(y + 1 < height && matrix[x][y+1] == matrix[x][y]) result += click(x, y+1);
        if(y - 1 >= 0 && matrix[x][y-1] == matrix[x][y]) result += click(x, y-1);
        return result;
    }
    else return 0;
}

int main()
{
    scanf("%d %d", &height, &width);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            scanf("%d", &matrix[j][i]);
        }
    }

    int maxResult = 0;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(!usedIndex[i][j])
            {
                int temp = click(i,j);
                if(temp > maxResult)
                {
                    maxResult = temp;
                }
            }
        }
    }
    maxResult *= (maxResult-1);
    printf("%d\n", maxResult);
}