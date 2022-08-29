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
    piss(goss);
    int n;cin>>n;
    for (int i=0;i<n;i++){
        mp[i]=new node{i};
    }
    int a,b;
    cin>>a>>b;
    while (a!=-1||b!=-1){
        mp[a]->neis.insert(mp[b]);
        mp[b]->neis.insert(mp[a]);
        cin>>a>>b;
    }
    auto rc=[](node* nf,int fd,auto&& rc)->bool{
        bool ret=false;
        for (auto it:nf->neis){
            if (!it->vt){
                it->vt=true;
                if (it->id==fd){
                    return true;
                }
                else ret=ret||rc(it,fd,rc);
            }
        }
        return ret;
    };
    cin>>a>>b;
    while (a!=-1||b!=-1){
        if (rc(mp[a],b,rc)){
            cout<<"yes\n";
        }
        else cout<<"no\n";
        for (auto it:mp){
            it.second->vt=false;
        }
        cin>>a>>b;
    }
}