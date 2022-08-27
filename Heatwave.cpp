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
int main()
{
    piss(heat);
    int n,h;cin>>n>>h;
    int cr=0;
    int ct=0;
    while (n--){
        int t;cin>>t;
        if (t>=h){
            ++ct;
        }
        else{
            cr=max(cr,ct);
            ct=0;
        }
    }
    cr=max(cr,ct);
    cout<<cr<<'\n';
}