#include <iostream>
#include <set>
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
#define __for(container, iterator) for (auto iterator=container.begin();it!=container.end();it++)
#define __forI(var, start, end) for (int var=start;var<end;var++)
int main()
{
    piss(lady);
    int n,k,q;cin>>n>>k>>q;
    int p[n];int d[q];
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        p[i]=iv;
    }
    for (int i=0;i<q;i++){
        int iv;cin>>iv;
        d[i]=iv;
    }
}