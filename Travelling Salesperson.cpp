#include <iostream>
#include <cmath>
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
    piss(sales);
    int vs[3];
    cin>>vs[0]>>vs[1]>>vs[2];
    int cr=0;
    int* me=max_element(&vs[0],&vs[0]+3);
    cr+=*me;
    *me=0;
    cr+=*max_element(&vs[0],&vs[0]+3);
    cout<<cr<<'\n';
}