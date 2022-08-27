#include <iostream>
#include <unordered_set>
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
uset<int> fs;
int main()
{
    piss(farm);
    int n;cin>>n;
    int dv=0;
    for (int i=0;i<n-1;i++){
        int iv;cin>>iv;
        dv+=iv;
        fs.insert(dv);
    }
    int v;cin>>v;dv+=v;
    int cr=0;
    for (auto it=fs.begin();it!=fs.end();it++){
        if (!fs.count(dv-*it))
            ++cr;
    }
    cout<<cr<<'\n';
}