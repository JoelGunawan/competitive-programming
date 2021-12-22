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

void destroy(int x, int y)
{
    int temp = matrix[x][y];
    matrix[x][y] = 0;
    if(x + 1 < width && matrix[x+1][y] == temp) destroy(x+1, y);
    if(x - 1 >= 0 && matrix[x-1][y] == temp) destroy(x-1, y);
    if(y + 1 < height && matrix[x][y+1] == temp) destroy(x, y+1);
    if(y - 1 >= 0 && matrix[x][y-1] == temp) destroy(x, y-1);
}

void collapse()
{
    for(int i = height - 2; i >= 0; i--)
    {
        for(int j = 0; j < width; j++)
        {
            if(matrix[j][i+1] == 0)
            {
                for(int k = height - 1; k > i; k--)
                {
                    if(matrix[j][k] == 0)
                    {
                        matrix[j][k] = matrix[j][i];
                        matrix[j][i] = 0;
                        break;
                    }
                }
            }
        }
    }
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

    int maxResult = 0, xIndex, yIndex;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(matrix[i][j] != 0)
            {
                int temp = click(i,j);
                if(temp > maxResult)
                {
                    maxResult = temp;
                    xIndex = i;
                    yIndex = j;
                }
            }
        }
    }

    destroy(xIndex, yIndex);

    collapse();

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(matrix[j][i] == 0)
            {
                if(j == width - 1) printf(".\n");
                else printf(". ");
            }
            else
            {
                if(j == width - 1) printf("%d\n", matrix[j][i]);
                else printf("%d ", matrix[j][i]);
            }
        }
    }
}