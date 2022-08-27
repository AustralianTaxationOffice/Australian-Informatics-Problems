#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <tuple>
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
#define __for(container, iterator) for (auto iterator=container.begin();iterator!=container.end();iterator++)
#define __forI(var, start, end) for (int var=start;var<end;var++)
enum joe{
    chair=1,
    bean=0
};
struct comp{
    bool operator()(const tuple<int,joe,int>&a,const tuple<int,joe,int>&b)const{
        if (get<0>(a)==get<0>(b)){
            return get<1>(a)<get<1>(b);
        }
        else return get<0>(a)<get<0>(b);
    }
};
int n;
int dis(int chair,int p)
{
    if (p>chair){
        return n-p+chair;
    }
    else return chair-p;
}
int main()
{
    piss(shuffle);
    vector<pair<int,int>> chairs,beans;
    set<tuple<int,joe,int>,comp> st;
    int k;cin>>n>>k;
    __forI(i,0,k){
        int iv;cin>>iv;
        chairs.push_back({iv,i+1});
        st.insert({iv,joe::chair,i+1});
    }
    __forI(i,0,k+1){
        int iv;cin>>iv;
        beans.push_back({iv,i+1});
        st.insert({iv,joe::bean,i+1});
    }
    auto bk=[&](auto& it){
        if (it==st.begin())
            it=st.end();
        return --it;
    };
    auto ch=st.begin();
    while (get<1>(*ch)==joe::bean)
        ++ch;
    int ct=0;
    auto it=ch;
    __forI(i,0,k*2+1){
        switch (get<1>(*it)){
            case joe::bean:
                --ct;
                break;
            case joe::chair:
                ++ct;
                break;
        }
        if (ct==0){
            cout<<get<2>(*it)<<"\n";
            break;
        }
        bk(it);
    }
    vector<int> can;
    ct=0;
    for(auto it2_=st.rbegin();it2_!=st.rend();++it2_){
        if (get<1>(*it2_)==joe::chair){
            ++ct;
        }
        else{
            if (ct==0){
                can.push_back(get<2>(*it2_));
            }
            else --ct;
        }
    }
    cout<<can.back()<<'\n';
}