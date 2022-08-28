#include <iostream>
#include <cmath>
#include <map>
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
map<int,int> mp;
signed main()
{
    piss(pair);
    int n;cin>>n;
    int cr=0;
    for (int i=0;i<n*2;i++){
        int iv;cin>>iv;
        if (!mp.count(iv)){
            mp[iv]=i;
        }
        else cr=max(cr,abs(mp[iv]-i));
    }
    cout<<cr<<'\n';
}