#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
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
    piss(mode);
    map<int,int> mp;
    int p;cin>>p;
    while (p--){
        int iv;cin>>iv;
        ++mp[iv];
    }
    auto it=max_element(mp.begin(),mp.end(),[](auto a,auto b){return a.second<b.second;});
    cout<<it->first<<' '<<it->second<<'\n';
}