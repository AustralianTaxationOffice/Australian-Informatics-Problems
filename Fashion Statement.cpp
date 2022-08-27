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
    piss(fash);
    int t;cin>>t;
    int cr=0;
    cr+=t/100;t%=100;
    cr+=t/20;t%=20;
    cr+=t/5;t%=5;
    cr+=t;
    cout<<cr<<'\n';
}