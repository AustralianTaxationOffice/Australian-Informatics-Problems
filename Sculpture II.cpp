#include <iostream>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_map>
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
#define __for(container, iterator) for (auto iterator=container.begin();it!=container.end();++it)
struct sech {
    int h,ts,te;
};
int main()
{
    piss(art);
    int n;cin>>n;
    int cr=0;
    int pt=0;
    stack<sech> se;
    while (n--){
        int t,w,h;cin>>t>>w>>h;--t;
        while (t>=(se.empty()?2e9:se.top().te))se.pop();
        se.push({(se.empty()?0:se.top().h)+h,t,t+w});
        cr=max(cr,(se.empty()?0:se.top().h));
    }
    cout<<cr<<'\n';
}