#include <bits/stdc++.h>
using namespace std;
struct danceMove
{
    int point;
    char moveType;
};

bool usedIndex[10];
danceMove danceMoves[10], moveOrder[10];
int minPoint[1000]= {0}, knownMoves, judgeCount,
totalMoves, bonusScore;
vector<int> results;

int calculatePoints(int length)
{
    bool convincingMove = false;
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        if(convincingMove) sum += bonusScore;
        if(i > 0)
        {
            if(moveOrder[i-1].moveType == 'P') sum += (moveOrder[i].point * 2);
            else if(moveOrder[i-1].moveType == 'L') sum += (moveOrder[i].point / 2);
            else sum += moveOrder[i].point;
        }
        else
        {
            sum += moveOrder[i].point;
        }
        if(moveOrder[i].moveType == 'Y') convincingMove = true;
    }
    return sum;
}

void myFunc(int depth)
{
    if(depth >= totalMoves)
    {
        int points = calculatePoints(depth);
        results.push_back(points);
    }
    else
    {
        for(int i = 0; i < knownMoves; i++)
        {
            if(!usedIndex[i])
            {
                usedIndex[i] = true;
                moveOrder[depth] = danceMoves[i];
                myFunc(depth+1);
                usedIndex[i] = false;
            }
        }
    }
}

int main()
{
    scanf("%s %d");
    scanf("%d %d %d %d\n", &knownMoves, &totalMoves, &bonusScore, &judgeCount);
    for(int i = 0; i < knownMoves; i++)
    {
        int temp1; char temp2; danceMove temp3;
        scanf("%d %c\n", &temp1, &temp2);
        temp3.point = temp1; temp3.moveType = temp2;
        danceMoves[i] = temp3;
    }
    for(int i = 0; i < judgeCount; i++) scanf("%d", &minPoint[i]);

    myFunc(0);

    // sort results
    sort(results.begin(), results.end());
    int left, right, middle, length = results.size(),
    currentPoint;
    for(int i = 0; i < judgeCount; i++)
    {
        left = 0; right = length-1;
        currentPoint = minPoint[i]+1;
        int j = 0;
        while(left <= right)
        {
            middle = (left + right) / 2;
            if(results[middle] > currentPoint) right = middle - 1;
            else if(results[middle] < currentPoint) left = middle + 1;
            else break;
        }
        if(results[middle] < currentPoint) middle++;
        while(results[middle] ==
              results[middle-1]) middle--;
        printf("%d\n", length-middle);
    }
    return 0;
}
