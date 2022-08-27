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
#define ll long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
int main()
{
    piss(build);
    int n;cin>>n;
    int* h=new int[n];
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        h[i]=iv;
    }
    int bc=0;int ib=-1;
    for (int i=1;i<n-1;i++){
        if (abs(abs(h[i+1]-h[i])+abs(h[i-1]-h[i])-(abs(h[i-1]-h[i+1])))>bc){
            bc=abs(abs(h[i+1]-h[i])+abs(h[i-1]-h[i])-(abs(h[i-1]-h[i+1])));
            ib=i;
        }
    }
    if (abs(h[1]-h[0])>bc){
        bc=abs(h[1]-h[0]);
        ib=0;
    }
    if (abs(h[n-1]-h[n-2])>bc){
        bc=abs(h[n-1]-h[n-2]);
        ib=n-1;
    }
    if (ib==n-1){
        h[ib]=h[ib-1];
    }
    else if(ib==0){
        h[ib]=h[ib+1];
    }
    else{
        h[ib]=(h[ib+1]+h[ib-1])/2;
    }
    //cout<<ib<<'\n';
    int cr=0;
    for (int i=0;i<n-1;i++){
        cr+=abs(h[i]-h[i+1]);
    }
    cout<<cr<<'\n';
}