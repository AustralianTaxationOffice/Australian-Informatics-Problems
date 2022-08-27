#include <iostream>
#include <cmath>
#include <map>
#include <set>
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
struct node{
    int id;
    set<node*> neis;
};
map<int,node*> mp;
signed main()
{
    speed();
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        mp[i]=new node{i,{}};
    }
    while (m--){
        int a,b;cin>>a>>b;
        mp[a]->neis.insert(mp[b]);
        mp[b]->neis.insert(mp[a]);
    }
    for (int i=1;i<=n;i++){
        cout<<mp[i]->neis.size()<<' ';
        for (auto it:mp[i]->neis){
            cout<<it->id<<' ';
        }
        cout<<'\n';
    }
}