#include <climits>
#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
long long ro,bo,s,rp,bp;
int main()
{
    freopen("baublesin.txt","r",stdin);
    freopen("baublesout.txt","w",stdout);
    cin>>ro>>bo>>s>>rp>>bp;
    int cr=0;
    if (ro>=rp&&bo>=bp){
        cr=min(ro-rp,bo-bp)+1;
    }
    cout<<cr<<'\n';
}