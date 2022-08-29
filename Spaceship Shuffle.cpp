#include <iostream>
#include <cmath>
#include <numeric>
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
    piss(space);
    int n;cin>>n;
    int ci[n],cd[n];
    int cm[n],psa[n];
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        ci[i]=iv;
    }
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        cd[i]=iv;
    }
    for (int i=0;i<n;i++){
        cm[i]=ci[i]-cd[i];
    }
    int sm=0;int sub=-2e9;
    for (int i=0;i<n;i++){
        sm+=cm[i];
        psa[i]=sm;
        //cout<<psa[i]<<' ';
    }
    //cout<<'\n';
    int cr=0;
    sub=(psa[0]-psa[n-1])/2ll;
    for (int i=0;i<n;i++){
        psa[i]-=sub;
        cr+=abs(psa[i]);
        //cout<<psa[i]<<' ';
    }
    //cout<<'\n';
    cout<<cr<<'\n';
}