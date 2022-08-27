#include <iostream>
#include <cmath>
#include <stack>
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
    piss(cute);
    int d;cin>>d;
    stack<int> n;
    while (d--){
        int iv;cin>>iv;
        n.push(iv);
    }
    int cr=0;
    while (!n.empty()&&n.top()==0){
        ++cr;
        n.pop();
    }
    cout<<cr<<'\n';
}