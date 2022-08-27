#include <iostream>
#include <cmath>
using namespace std;
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define piss(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define ll long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
#define int long long
int taxi(int y2,int y1,int x2,int x1)
{
    return abs(y2-y1)+abs(x2-x1);
}
int euc(int y2,int y1,int x2,int x1)
{
    int ys=abs(y2-y1);
    int xs=abs(x2-x1);
    return xs*xs+ys*ys;
}
signed main()
{
    piss(probe);
    int r,c,yp,xp,yf,xf;cin>>r>>c>>yp>>xp>>yf>>xf;
    int q;cin>>q;
    if (abs(xp-xf)==abs(yp-yf)){
        while (q--){
            int x,y;cin>>y>>x;
            if (euc(yf,y,xf,x)<euc(yp,y,xp,x)){
                cout<<"LAVA\n";
            }
            else if(euc(yf,y,xf,x)==euc(yp,y,xp,x)){
                cout<<"MOUNTAINS\n";
            }
            else{
                cout<<"WATER\n";
            }
        }
    }
    else{
        while (q--){
            int x,y;cin>>y>>x;
            if (taxi(yf,y,xf,x)<taxi(yp,y,xp,x)){
                cout<<"LAVA\n";
            }
            else if(taxi(yf,y,xf,x)==taxi(yp,y,xp,x)){
                cout<<"MOUNTAINS\n";
            }
            else{
                cout<<"WATER\n";
            }
        }
    }
}