#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;
int n,f;
vector<int> costs;
vector<pair<int,int>> fwreq;
vector<pair<int,int>> revreq;
int cr=-1;
int main(){
    freopen("spacein.txt", "r", stdin);
    freopen("spaceout.txt", "w", stdout);
    cin>>n>>f;
    for (int i=0;i<n;i++){
        int fd;
        cin>>fd;
        costs.push_back(fd);
    }
    int idx=0;
    int prev = INT_MAX;
    for (auto it=costs.begin();it!=costs.end();++it){
        if (*it<prev){
            fwreq.push_back({*it,idx});
            prev=*it;
        }
        ++idx;
    }
    idx=costs.size()-1;
    prev=INT_MAX;
    for (auto it=costs.rbegin();it!=costs.rend();++it){
        if (*it<prev){
            revreq.push_back({*it,idx});
            prev=*it;
        }
        --idx;
    }
    reverse(revreq.begin(),revreq.end());
    auto revn=revreq.begin();
    for (auto it=fwreq.begin();it!=fwreq.end();++it){
        while (revn!=revreq.end()&&revn->second<=it->second){
            ++revn;
        }
        while (it->first+revn->first<=f&&revn!=revreq.end()){
            cr=max(cr,abs(it->second-revn->second)+1);++revn;
        }
    }
    cout<<cr;
}
/*vector<long long> fuelOnDays;
int main(){
    freopen("spacein.txt", "r", stdin);
    freopen("spaceout.txt", "w", stdout);
    cin>>n>>f;
    fuelOnDays.reserve(n);
    for (long long i=0;i<n;i++){
        long long _;
        cin>>_;
        fuelOnDays.push_back(_);
    }

    auto itf = fuelOnDays.begin();
    auto ite = --fuelOnDays.end();
    long long cr;
    while (itf != ite)
    {
        if (*ite + *itf > f)
        {
            if (abs(*itf-*(itf+1)) > abs(*ite-*(ite-1))){
                ++itf;
            }
            else --ite;
        }
        else{
            cr = ite-itf+1;
            goto Exit;
        }
    }
    cr = -1;

    Exit:
    cout <<cr<<'\n';
}*/