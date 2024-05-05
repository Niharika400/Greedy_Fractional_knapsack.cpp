#include<bits/stdc++.h>
using namespace std;
class item{
    public:
    int profit,weight;
};
static bool cmp(item a,item b)
{
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}
double fractionalknap(int w,item arr[],int n)
{
    sort(arr,arr + n,cmp);
    double finalvalue =0.0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=w)
        {
            finalvalue+=arr[i].profit;
            w-=arr[i].weight;

        }
        else
        {
            finalvalue+=arr[i].profit*((double)w/arr[i].weight);
            break;
        }
    }
    return finalvalue;
    


}
int main(){
    int w=50;
    item arr[]={{100,20},{60,10},{120,30}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<fractionalknap(w,arr,n);
}