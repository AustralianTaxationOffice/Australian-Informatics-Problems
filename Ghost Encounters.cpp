#include <climits>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <sstream>
using namespace std;
int n,k;
set<int> bb;
multiset<int> b;
#define ld int
int main()
{
    freopen("ghostin.txt","r",stdin);
    freopen("ghostout.txt","w",stdout);
    cin>>n>>k;
    for (int i=0;i<n;i++){
        int xi,ti;
        cin>>xi>>ti;
        //cout<<ti-xi*k<<'\n';
        bb.insert(ti-xi*k);
        b.insert(ti-xi*k);
    }
    int cr=0;
    for (auto it=bb.begin();it!=bb.end();++it){
        cr=max(cr,(int)b.count(*it));
    }
    cout<<cr<<'\n';
}