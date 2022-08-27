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
    piss(gen);
    int n,p;cin>>n>>p;
    map<int,int> mp;
    for (int i=1;i<=n;i++){
        mp[i]=0;
    }
    int sv=0;
    while (true){
        for (int i=1;i<=n;i++){
            if (p>0){
                int pi=min(++sv,p);
                p-=pi;
                mp[i]+=pi;
                //cout<<i<<'\t'<<mp[i]<<'\n';
            }
            else goto exit;
        }
    }
    exit:;
    auto it=max_element(mp.begin(),mp.end(),[](auto a,auto b){return a.second<b.second;});
    cout<<it->first<<' '<<it->second<<'\n';
}