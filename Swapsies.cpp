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
#define int long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
signed main()
{
    piss(swaps);
    int n;cin>>n;
    vector<long double>v;v.reserve(n);
    //vector<int> _warr(n,0ll);
    //auto& v=_v;auto& warr=_warr;
    for (int i=0;i<n;i++){
        long double iv;cin>>iv;
        v.push_back(iv);
        //cout<<_v.back()<<'\n';
    }
    for (auto it=v.begin();it!=v.end();++it){
        auto me=max_element(it,v.end(),[](auto a,auto b){return a<=b;});
        swap(*it,*me);
        if (it!=me)
            cout<<it-v.begin()+1<<' '<<me-v.begin()+1<<'\n';
    }
    exit:
    cout<<"all sorted\n";
    /*for (int r=1;r<n;r+=r){
        for (int i=0;i<n;i+=r*2){
            int il=i,ir=i+r;
            for (int iw=i;iw<min(i+r*2,n);iw++){
                //if (r*2==4)__debugbreak();
                    auto t1=v[ir];auto t2=v[il];
                if ((il<min(i+r,n)&&v[il]>=v[ir])||ir>=min(i+r*2,n)){
                    warr[iw]=v[il];
                    ++il;
                }
                else{
                    warr[iw]=v[ir];
                    ++ir;
                }
            }
        }
        swap(v,warr);
    }*/
    /*for (auto it:v){
        cout<<it<<'\n';
    }*/
}