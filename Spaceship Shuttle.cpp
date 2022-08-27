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
    piss(space);
    int n;cin>>n;
    int* cur=new int[n],*des=new int[n];
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        cur[i]=iv;
    }
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        des[i]=iv;
    }
    int cr=0;
    for (int i=0;i<=n/2+(n%2!=0);i++){
        cr+=abs(cur[i]-des[i]);
        int sdif=(cur[i]-des[i]);
        cout<<abs(cur[i]-des[i])<<'\n';
        cur[i]-=sdif;
        cur[i+1]+=sdif;
    }
    cr+=abs(cur[0]-des[0]);
    int sdif=(cur[i]-des[i]);
    cout<<abs(cur[i]-des[i])<<'\n';
    cur[i]-=sdif;
    cur[i+1]+=sdif;
    for (int i=n-1;i>=n/2;i--){

    }
}