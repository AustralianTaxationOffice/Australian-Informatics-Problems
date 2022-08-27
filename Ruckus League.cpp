#include <iostream>
#include <cmath>
#include <vector>
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
#define ll long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
struct node{
    int id;bool vt=false;
    set<node*> neis;
};
map<int,node*> mp;
int main()
{
    piss(ruckus);
    int n,l,k,m;cin>>n>>l>>k>>m;
    for (int i=1;i<=n;i++){
        mp.insert({i,new node{i,{}}});
    }
    while (l--){
        int c1,c2;cin>>c1>>c2;
        mp[c1]->neis.insert(mp[c2]);
        mp[c2]->neis.insert(mp[c1]);
    }
    vector<int> sz;
    for (auto&it:mp){
        if (!it.second->vt){
            sz.push_back(0);
            auto rc=[&](node* nd, auto&& rc)->void{
                ++sz.back();
                nd->vt=true;
                for (auto it=nd->neis.begin();it!=nd->neis.end();++it){
                    if (!(**it).vt)
                        rc(*it,rc);
                }
            };
            rc(it.second,rc);
        }
    }
    int cr=sz.size();
    for (auto&it:sz){
        rt:
        if (k>0){
            if (it-m>=m){
                it-=m;
                ++cr;
                --k;
                goto rt;
            }
        }
        else{
            break;
        }
    }
    /*for(auto&it:sz){
        cout<<it<<'\n';
    }*/
    cout<<cr<<'\n';
}