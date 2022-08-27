#include <iostream>
#include <unordered_map>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in ".txt","r",stdin); \
freopen(#out ".txt","w",stdout)
#define ll long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
int main()
{
    piss(cavalryin,cavalryout);
    int n;cin>>n;
    umap<int,int> m;
    for (int i=0;i<n;i++){
        int ai;cin>>ai;
        ++m[ai];
    }
    for (auto it=m.begin();it!=m.end();++it){
        if (it->second%it->first!=0){
            cout<<"NO\n";
            exit(0);
        }
    }
    cout<<"YES\n";
}