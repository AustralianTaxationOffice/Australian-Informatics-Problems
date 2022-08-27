#include <iostream>
#include <cmath>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in ".txt","r",stdin); \
freopen(#out ".txt","w",stdout)
#define ll long long
int main()
{
    piss(streetin,streetout);
    int n,k;cin>>n>>k;
    cout<<(n-k)/(k+1)+((n-k)%(k+1)!=0)<<'\n';
}