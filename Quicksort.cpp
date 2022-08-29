#include <iostream>
#include <cmath>
#include <set>
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
struct node{
    int id;
    set<node*> neis;
    bool vt=0;
};
map<int,node*> mp;
signed main()
{
    piss(qsort);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        mp[i]=new node{i,{}};
    }
    for (int i=1;i<=n;i++){
        int iv;cin>>iv;
        switch (iv){
        case 1:
            if (i!=n){
                mp[i]->neis.insert(mp[i+1]);
            }
            break;
        case 2:
            int c;cin>>c;
            mp[i]->neis.insert(mp[c]);
            break;
        case 3:
            int a,b;cin>>a>>b;
            mp[i]->neis.insert(mp[a]);
            mp[i]->neis.insert(mp[b]);
            break;
        }
    }
    int cr=0;
    auto rc=[&](node* nd, auto&& rc)->void{
        for (auto it:nd->neis){
            if (!it->vt){
                //cout<<it->id<<'\n';
                it->vt=1;
                ++cr;
                rc(it,rc);
            }
        }
    };
    //cout<<mp[1]->id<<'\n';
    mp[1]->vt=1;
    ++cr;
    rc(mp[1],rc);
    cout<<n-cr<<'\n';
}