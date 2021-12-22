#include <bits/stdc++.h>
using namespace std;
bool usedIndex[25][25] = {{false}};
int matrix[25][25] = {{0}};
int width, height, roundCount = 2;
long long maxResult = 0;

void resetUsedIndex()
{
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            usedIndex[i][j] = false;
        }
    }
}

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

void doRound(int depth, long long totalResults)
{
    resetUsedIndex();
    // if is last iteration
    if(depth >= roundCount - 1)
    {
        long long localMaxResult = 0;
        for(int i = 0; i < width; i++)
        {
            for(int j = 0; j < height; j++)
            {
                if(!usedIndex[i][j] && matrix[i][j] != 0)
                {
                    int temp = click(i, j);
                    if(temp >= localMaxResult) localMaxResult = temp;
                }
            }
        }
        localMaxResult *= (localMaxResult - 1);
        totalResults += localMaxResult;
        if(totalResults >= maxResult) maxResult = totalResults;
    }
    else
    {
        for(int i = 0; i < width; i++)
        {
            for(int j = 0; j < height; j++)
            {
                if(!usedIndex[i][j] && matrix[i][j] != 0)
                {
                    long long result = click(i, j);
                    if(result > 1)
                    {
                        result = result * (result - 1) + totalResults;
                        bool tempUsedIndex[width][height];
                        int tempMatrix[width][height];
                        for(int x = 0; x < width; x++)
                        {
                            for(int y = 0; y < height; y++)
                            {
                                tempUsedIndex[x][y] = usedIndex[x][y];
                                tempMatrix[x][y] = matrix[x][y];
                            }
                        }

                        destroy(i, j);
                        collapse();
                        doRound(depth + 1, result);

                        for(int x = 0; x < width; x++)
                        {
                            for(int y = 0; y < height; y++)
                            {
                                matrix[x][y] = tempMatrix[x][y];
                                usedIndex[x][y] = tempUsedIndex[x][y];
                            }
                        }
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

    doRound(0, 0);

    printf("%lld\n", maxResult);
}
