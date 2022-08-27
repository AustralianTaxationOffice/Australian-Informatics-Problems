#include <iostream>
#include <set>
#include <climits>
using namespace std;
int n,k;
set<int> counts;
int main(){
    freopen("distin.txt", "r", stdin);
    freopen("distout.txt", "w", stdout);
    cin>>n>>k;
    int di;
    for (int i=0;i<n;i++){
        cin>>di;
        counts.insert(di);
    }
    int cr=0, dm=0;
    for (auto it=counts.begin();it!=counts.end();++it){
        if (*it >= dm){
            dm = *it + k;
            ++cr;
        }
    }
    cout << cr << '\n';
}