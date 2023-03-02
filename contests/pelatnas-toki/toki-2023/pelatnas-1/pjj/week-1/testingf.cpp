#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct point_type{
    double x;
    double y;
};
bool cmp(point_type a,point_type b)
{
    return a.x<b.x;
}
double distance(point_type a,point_type b);
double divide(point_type a[],int low,int high);
double combine(point_type a[],int low,int mid,int high,double min_left,double min_right);
int main()
{
    int N;
    point_type point[200001];
    while(scanf("%d",&N))
    {
        if (N==0) break;
        for(int i=0;i<N;i++)
            scanf("%lf %lf",&point[i].x,&point[i].y);
        sort(point,point+N,cmp);
        double dis=divide(point,0,N-1);
        //if(dis>=10000.0) printf("INFINITY\n");
        //else printf("%.4lf\n",dis);
        printf("%.0lf", pow(dis, 2));
        return 0;
    }
    return 0;
}
double Distance(point_type a,point_type b)
{
    return (double)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double divide(point_type a[],int low,int high)
{
    if(low>=high) return 9e18;  //切到只剩1個點，return inf

    int mid=(low+high)/2;
    double min_left=divide(a,low,mid);
    double min_right=divide(a,mid+1,high);
    return combine(a,low,mid,high,min_left,min_right);
}
double combine(point_type a[],int low,int mid,int high,double min_left,double min_right)
{
    double d=(min_left<min_right)?min_left:min_right;
    double line=(double)(a[mid].x+a[mid+1].x)*0.5; //line:左集合與右集合的中間線x座標
    double min_D=d;
    for(int i=mid+1;a[i].x<line+d && i<=high;i++){ //枚舉line+-d範圍內左右集合的點
        for(int j=mid;a[j].x>line-d && j>=low;j--){
            double temp=Distance(a[i],a[j]);
            if(temp<min_D) min_D=temp;
        }
    }
    return min_D;
}