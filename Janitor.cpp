#include <iostream>
#include <tuple>
#include <set>
using namespace std;
#define piss(name) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define ll long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
int r,c,q;
bool inb(int x,int y){
    return x>=0&&x<c&&y>=0&&y<r;
}
int main()
{
    piss(janitor);
    cin>>r>>c>>q;
    int* gd=new int[c*r];
    auto at=[&](int x,int y)->int&{
        return gd[x*r+y];
    };
    for (int y=0;y<r;y++){
        for (int x=0;x<c;x++){
            int iv;cin>>iv;
            at(x,y)=iv;
        }
    }
    auto minr=[&]{int cr=0;
    for (int y=0;y<r;y++){
        for (int x=0;x<c;x++){
            bool iv=false;
            if (inb(x+1,y)){
                iv=iv||(at(x,y)<at(x+1,y));
            }
            if (inb(x-1,y)){
                iv=iv||(at(x,y)<at(x-1,y));
            }
            if (inb(x,y+1)){
                iv=iv||(at(x,y)<at(x,y+1));
            }
            if (inb(x,y-1)){
                iv=iv||(at(x,y)<at(x,y-1));
            }
            if (iv==false){
                ++cr;
                //joe.insert({x,y});
            }
        }
    }return cr;};
    int cr=minr();
    cout<<cr<<'\n';
    for (int i=0;i<q;i++){
        int ix,iy,ih;cin>>iy>>ix>>ih;--ix,--iy;
        auto isPeak=[&](int x,int y){
            if (!inb(x,y))
                return false;
            if (inb(x+1,y)&&at(x,y)<=at(x+1,y))
                return false;
            if (inb(x-1,y)&&at(x,y)<=at(x-1,y))
                return false;
            if (inb(x,y+1)&&at(x,y)<=at(x,y+1))
                return false;
            if (inb(x,y-1)&&at(x,y)<=at(x,y-1))
                return false;
            return true;
        };
        if (isPeak(ix,iy))--cr;
        if (isPeak(ix+1,iy))--cr;
        if (isPeak(ix-1,iy))--cr;
        if (isPeak(ix,iy+1))--cr;
        if (isPeak(ix,iy-1))--cr;
        at(ix,iy)=ih;
        if (isPeak(ix,iy))++cr;
        if (isPeak(ix+1,iy))++cr;
        if (isPeak(ix-1,iy))++cr;
        if (isPeak(ix,iy+1))++cr;
        if (isPeak(ix,iy-1))++cr;
        cout<<cr<<'\n';
    }
}