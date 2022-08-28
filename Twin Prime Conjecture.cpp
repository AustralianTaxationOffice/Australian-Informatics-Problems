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
    piss(prime);
    int n;cin>>n;
    bool pms[n-1]{false};
    for (int i=0;i<n-1;i++){
        if (pms[i]==false){
            cout<<i+2<<'\n';
            for (int j=i;j<n-1;j+=i+2){
                pms[j]=true;
            }
        }
    }
}