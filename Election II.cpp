#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define piss(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
signed main()
{
    piss(elec);
    map<char,int> vs;
    int n;cin>>n;
    string s;cin>>s;
    for (auto it=s.begin();it!=s.end();++it){
        ++vs[*it];
    }
    char cr='\t';
    int cm=0;
    int act=vs['A'],bct=vs['B'],cct=vs['C'];
    int m=max({act,bct,cct});
    if (act==m&&act!=bct&&act!=cct){
        cout<<"A\n";
    }
    else if (bct==m&&bct!=act&&bct!=cct){
        cout<<"B\n";
    }
    else if (cct==m&&cct!=act&&cct!=bct){
        cout<<"C\n";
    }
    else cout<<"T\n";
}