#include <iostream>
#include <string>
#include <numeric>
#include <map>
#include <unordered_map>
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
#define __for(container, iterator) for (auto iterator=container.begin();it!=container.end();it++)
#define __forI(var, start, end) for (int var=start;var<end;var++)
int main()
{
    speed();
    int n,k;cin>>n>>k;
    mmap<int,string> dec;
    umap<string,int> cct;
    __forI(i,0,n){
        int c;string s;cin>>c>>s;
        dec.insert({c,s});
    }
    int cr=0;
    while (true){
    }
    cout<<cr<<'\n';
}