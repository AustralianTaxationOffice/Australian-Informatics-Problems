#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
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
    piss(sort);
    int n;cin>>n;
    vector<int> v;v.reserve(n);
    while (n--){
        int iv;cin>>iv;
        v.push_back(iv);
    }
    std::sort(v.begin(),v.end(),[](auto& a,auto& b){return abs(a)<abs(b);});
    for (auto it:v){
        cout<<it<<'\n';
    }
}