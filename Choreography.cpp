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
    piss(dance);
    int d,t;cin>>d>>t;
    int dans[d]{0};
    int cr=0;
    while (t--){
        int a,b;cin>>a>>b;
        if (dans[a-1]==0){
            ++cr;
            dans[a-1]=1;
        }
        --dans[a-1];
        ++dans[b-1];
    }
    cout<<cr<<'\n';
}