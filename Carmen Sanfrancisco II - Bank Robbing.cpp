#include <iostream>
#include <cmath>
#include <numeric>
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
    piss(where);
    int n,c;cin>>n>>c;
    int* bks=new int[c];
    for (int i=0;i<c;i++){
        int iv;cin>>iv;
        bks[i]=iv-1;
    }
    int* tts=new int[n-1];
    for (int i=0;i<n-1;i++){
        int iv;cin>>iv;
        tts[i]=iv;
    }
    int cr=0;
    int* ttr=new int[n-1]{0};
    int i=bks[0];int t=tts[bks[0]];
    while (t!=0&&i+1<n-1){
        --t;++i;
        if (t>tts[i])
            t=tts[i];
    }
    for (i;i>=bks[0];i--){
        ttr[i]=t++;
    }
    int* ttl=new int[n-1]{0};
    i=bks[c-1]-1;t=tts[bks[c-1]-1];
    while (t!=0&&i-1>=0){
        --t;--i;
        if (t>tts[i])
            t=tts[i];
    }
    for (i;i<bks[c-1];i++){
        ttl[i]=t++;
    }
    bool* out=new bool[n-1];
    for (i=0;i<n-1;i++){
        if (i<bks[0]){
            out[i]=ttl[i]!=0;
        }
        else if (i>=bks[c-1]){
            out[i]=ttr[i]!=0;
        }
        else{
            out[i]=2*(i-bks[0])<=ttl[i-1]||2*(bks[c-1]-i)<=ttr[i];
        }
    }
    //for (int i=0;i<n-1;i++){
        //cout<<out[i]<<'\n';
    //}
    cout<<accumulate(&out[0],&out[0]+n-1,0)<<'\n';
}