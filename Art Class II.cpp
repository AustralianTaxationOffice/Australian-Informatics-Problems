#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
long long xmin=LLONG_MAX,xmax,ymin=LLONG_MAX,ymax;
long long n;
int main(){
    freopen("artin.txt", "r", stdin);
    freopen("artout.txt", "w", stdout);
    cin>>n;
    for (long long i=0;i<n;i++){
        long long x,y;
        cin>>x>>y;
        if (x<xmin) xmin=x;
        if (x>xmax) xmax=x;
        if (y<ymin) ymin=y;
        if (y>ymax) ymax=y;
    }
    cout<<(xmax-xmin)*(ymax-ymin)<<'\n';
}