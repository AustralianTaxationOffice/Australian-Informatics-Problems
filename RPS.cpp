#include <iostream>
#include <climits>
using namespace std;
int main()
{
    freopen("rpsin.txt","r",stdin);
    freopen("rpsout.txt","w",stdout);
    int n; cin>>n;
    int ra,pa,sa,rb,pb,sb;
    cin>>ra>>pa>>sa>>rb>>pb>>sb;
    int pts=0;
    int t=min(rb,sa);
    pts+=t;
    rb-=t;sa-=t;
    t=min(pb,ra);
    pts+=t;
    pb-=t;ra-=t;
    t=min(sb,pa);
    pts+=t;
    sb-=t;pa-=t;
    t=min(rb,ra);
    rb-=t;ra-=t;
    t=min(pb,pa);
    pb-=t;pa-=t;
    t=min(sb,sa);
    sb-=t;sa-=t;
    pts-=rb+pb+sb;
    cout<<pts<<'\n';
}