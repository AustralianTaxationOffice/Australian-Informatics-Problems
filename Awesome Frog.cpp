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
    piss(frog);
    int n,k;cin>>n>>k;
    int dst[n-1];
    int bestidx=0,bestdiff=2e9;
    __forI(i,0,n-1)
    {
        cin>>dst[i];
        if (bestdiff>abs(dst[i]-k)){
            bestdiff=abs(dst[i]-k);
            bestidx=i;
        }
    }
}