#include <iostream>
#include <cmath>
#include <unordered_map>
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
int main()
{
    piss(snap);
    umap<int,int> m1,m2;
    int r,s;cin>>r>>s;
    while (r--){
        int iv;cin>>iv;
        ++m1[iv];
    }
    while (s--){
        int iv;cin>>iv;
        ++m2[iv];
    }
    int cr=0;
    for (auto it=m1.begin();it!=m1.end();++it){
        cr+=m2[it->first]*it->second;
    }
    cout<<cr<<'\n';
}