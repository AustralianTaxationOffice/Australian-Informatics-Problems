#include <iostream>
#include <cmath>
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
    piss(nom);
    int n;cin>>n;int iv;cin>>iv;
    int cr=1;int req=iv;int cur=0;
    int i=0;
    again:
    while (cur<req){
        ++i;
        if (i==n)
            goto exit;
        cin>>iv;
        cur+=iv;
    }
    req=cur;
    ++cr;
    cur=0;
    goto again;
    exit:;
    cout<<cr<<'\n';
}