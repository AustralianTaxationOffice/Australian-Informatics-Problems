#include <iostream>
#include <map>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in ".txt","r",stdin); \
freopen(#out ".txt","w",stdout)
#define ll long long
int r,c,rr,cr,rs,cs;
int main()
{
    piss(snapin,snapout);
    cin>>r>>c>>rr>>cr>>rs>>cs;
    cout<<((abs(rr-rs)+abs(cr+cs))%2==0?"SCARLET":"ROSE")<<'\n';
}