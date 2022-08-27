#include <bits/stdc++.h>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in,"r",stdin); \
freopen(#out,"w",stdout)

multiset<int> x,s,m;
int main()
{
    piss(hirein.txt,hireout.txt);
    int n,k;cin>>n;
    for (int i=0;i<n;i++){
        cin>>k;
        x.insert(k);
    }
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>k;
        s.insert(k);
    }
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>k;
        m.insert(k);
    }
    /*for (auto it=x.begin();it!=x.end();it++){
        cout<<*it<<"  ";
    }
    cout<<'\n';
    for (auto it=s.begin();it!=s.end();it++){
        cout<<*it<<"  ";
    }
    cout<<'\n';
    for (auto it=m.begin();it!=m.end();it++){
        cout<<*it<<"  ";
    }*/
    int cr=0;
    auto xi=x.begin();
    for (auto it=s.begin();it!=s.end();++it){
        if (xi==x.end()) break;
        if (*xi<=*it){
            ++cr;
            ++xi;
        }
    }
    auto mk=m.begin();
    for (;xi!=x.end();++xi){
        if (mk==m.end()) break;
        if (*xi>=*mk){
            ++cr;
            ++mk;
        }
    }
    cout<<cr;
}