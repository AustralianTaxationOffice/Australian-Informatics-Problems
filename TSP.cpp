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
    piss(tsp);
    int n;cin>>n;
    vector<int>l;vector<int>r;
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        l.push_back(iv);
    }
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        r.push_back(iv);
    }
    int reqnext=l[0];
    for (int i=1;i<n;i++){
        if (reqnext<=l[i])
            reqnext=l[i];
        if (reqnext>r[i]){
            cout<<"NO\n";
            exit(0);
        }
    }
    cout<<"YES\n";
}