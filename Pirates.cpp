#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <tuple>
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
#define __for(container, iterator) for (auto iterator=container.begin();iterator!=container.end();iterator++)
#define __forI(var, start, end) for (int var=start;var<end;var++)
int main()
{
    piss(pirate);
    int l,x,y;cin>>l>>x>>y;
    cout<<min(x+y,l-x+l-y)<<'\n';
}