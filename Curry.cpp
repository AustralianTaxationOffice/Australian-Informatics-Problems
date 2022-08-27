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
    piss(curry);
    int c,r,v;cin>>c>>r>>v;
    map<char,int> mp;mp['c']=c;mp['r']=r;mp['v']=v;int x=0,y=0,z=0;
    while (true){
        auto it=max_element(mp.begin(),mp.end(),[](auto a,auto b){return a.second<b.second;});
        auto pr=*it;
        mp.erase(it);
        it=max_element(mp.begin(),mp.end(),[](auto a,auto b){return a.second<b.second;});
        if (!(it->second>0&&pr.second>0)){
            goto exit;
        }
        --it->second;--pr.second;
        //cout<<it->second<<'\t'<<pr.second<<'\n';
        if ((it->first=='c'&&pr.first=='v')||(it->first=='v'&&pr.first=='c')){
            ++y;
        }
        else if((it->first=='c'&&pr.first=='r')||(it->first=='r'&&pr.first=='c')){
            ++z;
        }
        else{
            ++x;
        }
        mp.insert(pr);
    }
    exit:;
    cout<<x<<' '<<y<<' '<<z<<'\n';
}