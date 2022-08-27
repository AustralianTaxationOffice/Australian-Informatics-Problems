#include <iostream>
#include <cmath>
#include <vector>
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
    piss(ground);
    int n;cin>>n;
    vector<int> alts;
    int cr=0;
    while (n--){int iv;cin>>iv;alts.push_back(iv);}
    int cur=0;
    for (auto it=alts.begin();it!=alts.end();++it){
        auto next=it;++next;
        cur+=*it;
        if (*it!=*next){cr=max(cr,cur);cur=0;}
    }
    cr=max(cr,cur);
    cout<<cr<<'\n';
}