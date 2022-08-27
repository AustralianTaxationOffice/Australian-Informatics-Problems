#include <iostream>
#include <cmath>
#include <string>
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
    piss(chairs);
    int c,n,k;cin>>c>>n>>k;
    if (n==1){
        cout<<"0\n";
        exit(0);
    }
    string cs;cin>>cs;
    string bean(cs.size(),'0');
    
    for (int i=0;i<n;i++){

    }
}