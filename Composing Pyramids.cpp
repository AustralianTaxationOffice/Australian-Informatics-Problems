#include <iostream>
#include <cmath>
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
int main()
{
    piss(comp);
    int n;cin>>n;
    int pyr[n];
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        pyr[i]=iv;
    }
    int lreq[100001]{0};
    int rreq[100001]{0};
    int bcl[n],bcr[n];
    for (int i=0;i<n;i++){
        lreq[pyr[i]]=lreq[pyr[i]-1]+1;
        bcl[i]=lreq[pyr[i]];
    }
    for (int i=0;i<n;i++){
        rreq[pyr[n-1-i]]=rreq[pyr[n-1-i]-1]+1;
        bcr[i]=rreq[pyr[n-1-i]];
    }
    /*for (int i=0;i<n;i++){
        cout<<bcl[i]<<'\t';
    }
    cout<<'\n';
    for (int i=0;i<n;i++){
        cout<<bcr[i]<<'\t';
    }
    cout<<'\n';*/
    int cr=0;
    for (int i=0;i<n;i++){
        cr=max(cr,min(bcl[i],bcr[n-1-i]));
    }
    cout<<n-(cr*2-1)<<'\n';
}