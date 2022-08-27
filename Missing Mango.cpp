#include <iostream>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in,"r",stdin); \
freopen(#out,"w",stdout)
#define ll long long
int ix,cx,id,cd;
int main()
{
    piss(manin.txt,manout.txt);
    cin>>ix>>cx>>id>>cd;
    int cr=2e9;
    if (ix+id==cx+cd||ix+id==cx-cd)
        cr=ix+id;
    else if (ix-id==cx+cd||ix-id==cx-cd)
        cr=ix-id;
    cout<<cr<<'\n';
}