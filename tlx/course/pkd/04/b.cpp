#include <cstdio>
using namespace std;
int teamCount, points[5], currentGroup[5];
bool found = false;

void sortPointsArray()
{
    bool ordered = false;
    while(!ordered)
    {
        ordered = true;
        for(int i = 0; i < 4; i++)
        {
            if(points[i] > points[i+1])
            {
                int temp = points[i];
                points[i] = points[i+1];
                points[i+1] = temp;
                ordered = false;
            }
        }
    }
}

void sortCurrentGroupArray()
{
    bool ordered = false;
    while(!ordered)
    {
        ordered = true;
        for(int i = 0; i < 4; i++)
        {
            if(currentGroup[i] > currentGroup[i+1])
            {
                int temp = currentGroup[i];
                currentGroup[i] = currentGroup[i+1];
                currentGroup[i+1] = temp;
                ordered = false;
            }
        }
    }
}

void getResults(int, int);

void simulateGroup(int depth)
{
    // if there is already a matching result don't bother checking
    if(found) return;
    // if all matches have been simulated
    if(depth >= teamCount - 1)
    {
        // sort the array
        found = true;

        // check if the array is the same as the currentGroup
        for(int i = 0; i < teamCount; i++)
        {
            if(currentGroup[i] != points[i])
            {
                found = false;
                break;
            }
        }
        if(found) printf("YES\n");
    }
    else
    {
        getResults(depth, depth+1);
    }
}

void getResults(int depth, int enemyTeamIndex)
{
    if(enemyTeamIndex >= teamCount) simulateGroup(depth+1);
    else
    {
        // case win
        points[depth] += 3;
        getResults(depth, enemyTeamIndex+1);
        // reset val
        points[depth] -= 3;
        // case draw
        points[depth]++; points[enemyTeamIndex]++;
        getResults(depth, enemyTeamIndex+1);
        // reset val
        points[depth]--; points[enemyTeamIndex]--;
        // case loss
        points[enemyTeamIndex] += 3;
        getResults(depth, enemyTeamIndex+1);
        // reset val
        points[enemyTeamIndex] -=3;
    }
}

int main()
{
    // get how many groups need to be simulated
    int inputLength;
    scanf("%d", &inputLength);
    for(int i = 0; i < inputLength; i++)
    {
        // reset val of points and currentGroup
        for(int i = 0; i < 5; i++)
        {
            points[i] = 0;
            currentGroup[i] = 0;
        }
        // get the amount of teams in the group
        scanf("%d", &teamCount);
        // input the values to currentGroup array
        for(int i = 0; i < teamCount; i++)
        {
            scanf("%d", &currentGroup[i]);
        }

        // call simulateGroup function
        simulateGroup(0);

        // check if the result has been found
        // if the result has been found do nothing
        // else print "NO\n"
        if(!found) printf("NO\n");
        found = false;
    }
}