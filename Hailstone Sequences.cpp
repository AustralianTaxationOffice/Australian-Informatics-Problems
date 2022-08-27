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
#define int long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
signed main()
{
    piss(hail);
    int iv;
    while (cin>>iv&&iv!=0){
        int cr=0;
        while (iv!=1){
            if (iv%2==0)
                iv/=2ll;
            else iv=3ll*iv+1;
            ++cr;
        }
        cout<<cr<<'\n';
    }
}