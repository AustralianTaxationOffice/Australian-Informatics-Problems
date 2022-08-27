#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;
int n;
string a,b;
int ux,uy,lx,ly;
int ls;
int main()
{
    freopen("laserin.txt","r",stdin);
    freopen("laserout.txt","w",stdout);
    cin>>n;
    cin>>a>>b;
    for (int i=0;i<2*n;i++){
        a[i]=='R'?++lx:++ly;
        b[i]=='R'?++ux:++uy;
        ls=max(ls,ux-lx);
    }
    cout<<ls;
}