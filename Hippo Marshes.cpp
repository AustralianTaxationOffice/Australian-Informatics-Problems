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
map<pair<int,int>,bool> mp;
int main()
{
    speed();
    int n,m;cin>>n>>m;
    while (m--){
        int a,b;cin>>a>>b;
        mp[{a,b}]=true;
    }
    for (int i=0;i<n;i++){
        for (int j=1;j<=n;j++){
            
        }
    }
}