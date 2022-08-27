#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define piss(name) \
ios::sync_with_stdio(false); \
cin.tie(0); \
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
    piss(cloud);
    vector<int> lens;
    int n,k;cin>>n>>k;
    int l=n-1;
    for (int i=0;i<l;i++){
        int iv;cin>>iv;
        lens.push_back(iv);
    }
    int cr=2e9;
    int isum=0;
    for (int i=0;i<k-1;i++){
        isum+=lens[i];
    }
    for (int i=0;i<l-k+1;i++){
        isum+=lens[i+k-1];
        cr=min(cr,isum);
        isum-=lens[i];
    }
    cout<<cr<<'\n';
}