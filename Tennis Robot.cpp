#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in,"r",stdin); \
freopen(#out,"w",stdout)
int b,n;
unordered_map<int,int> lr;
int main()
{
    piss(tennisin.txt,tennisout.txt);
    cin>>b>>n;
    vector<int> bs;
    for (int i=0;i<b;i++){
        int a;
        cin>>a;
        bs.push_back(a);
    }
    int m=*max_element(bs.begin(),bs.end());
    for (auto it=bs.begin();it!=bs.end();++it){
        lr[*it-1]++;
    }
    int l=0;
    int sub=bs.size();
    while (n-sub>0){
        n-=sub;
        auto it=lr.find(l);
        if (it!=lr.end())
            sub-=it->second;
        ++l;
    }
    int cr=-1;
    for (int i=0;i<b;i++){
        if (bs[i]>=l){
            --n;
        }
        if (n==0){
            cr=i+1;
            break;
        }
    }
    cout<<cr<<'\n';
}