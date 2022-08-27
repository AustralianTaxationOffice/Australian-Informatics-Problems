#include <iostream>
#include <unordered_set>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in ".txt","r",stdin); \
freopen(#out ".txt","w",stdout)
#define ll long long
unordered_set<int> bt,rt;int n,m;
int main()
{
    piss(tagin,tagout);
    rt.insert(1);bt.insert(2);
    cin>>n>>m;
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        if (rt.count(a)){
            rt.insert(b);
        }
        else bt.insert(b);
    }
    cout<<rt.size()<<' '<<bt.size()<<'\n';
}