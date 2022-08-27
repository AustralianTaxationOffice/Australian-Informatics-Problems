#include <iostream>
#include <cmath>
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
int main()
{
    piss(island);
    int n,l;cin>>n>>l;
    if (l==0){
        cout<<"0\n";
        exit(0);
    }
    umap<int,int> hs;
    while (n--){
        int h,p;
        cin>>h>>p;
        hs[h-1]=p;
    }
    int sumr=0,suml=0,ctr=0,ctl=0;
    for (auto it=hs.begin();it!=hs.end();++it){
        if (it->first<l*2){
            ctr+=it->second;
            sumr+=it->second*(l*2-it->first);
        }
        else{
            ctl+=it->second;
            suml+=it->second*(it->first-l*2);
        }
    }
    int hct=4*l;
    int i1=0,i2=l*2;
    int cr=0;
    while (hct--){
        cr=max(cr,suml+sumr);
        //cout<<i2<<"  "<<suml+sumr<<'\n';
        if (hs.count(i1)){
            ctl+=hs[i1];
            ctr-=hs[i1];
        }
        if (hs.count(i2)){
            ctr+=hs[i2];
            ctl-=hs[i2];
        }
        sumr+=ctr;
        suml-=ctl;
        ++i1;++i2;if (i2==l*4)i2=0;
    }
    cout<<cr<<'\n';
}