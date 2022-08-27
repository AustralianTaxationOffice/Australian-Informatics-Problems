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
int main()
{
    piss(comp);
    int n;cin>>n;
    int* pyr=new int[n];
    multimap<int,int,greater<int>> ixs;
    for (int i=0;i<n;i++){
        int iv;cin>>iv;
        pyr[i]=iv;
        ixs.insert(pair{iv,i});
    }
    int cr=0;
    for (auto it=ixs.begin();it!=ixs.end();++it){
        int bv=1;
        int il=it->second,ir=it->second;
        int ireq=it->first-1;
        rt:
        if (ireq==0||il<0||ir>=n){
            p2:;
            cr=max(cr,bv);
            cout<<bv<<'\n';
        }
        else{
            while (pyr[ir++]!=ireq)
                if (ir>n)goto p2;
            while (pyr[il--]!=ireq)
                if (il<0)goto p2;
            bv+=2;
            --ireq;
            goto rt;
        }
    }
    cout<<n-cr<<'\n';
}