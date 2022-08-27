#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in,"r",stdin); \
freopen(#out,"w",stdout)
#define ll long long
int n,m;
enum claim{
    honest=1,liar,thief
};
struct d{
    char rel='U';
    struct cl{
        int acc=-1;
        claim c;
    };
    vector<cl> claims;
};
unordered_map<int,d> inf;
set<int> out;
int main()
{
    piss(detectivein.txt,detectiveout.txt);
    auto quickex=[]{
        cout<<"MISTAKE\n";
        exit(0);
    };
    cin>>n>>m;
    while (m--){
        int a,b,c;
        cin>>a>>b>>c;
        inf[a].claims.push_back({b,(claim)c});
    }
    auto func=[&](auto itt,auto&& func){
        for (auto it=itt->second.claims.begin();it!=itt->second.claims.end();++it){
            if (itt->second.rel=='T')
            switch (it->c){
                case claim::honest:
                if (inf[it->acc].rel=='U')
                    inf[it->acc].rel='T';
                else quickex();
                break;
                case claim::liar:
                if (inf[it->acc].rel=='U')
                    inf[it->acc].rel='F';
                else quickex();
                break;
                case claim::thief:
                if (inf[it->acc].rel=='U'){
                    inf[it->acc].rel='F';
                    out.insert(it->acc);
                }
                else quickex();
                break;
            }
            else if(itt->second.rel=='F')
            switch (it->c){
                case claim::honest:
                if (inf[it->acc].rel=='U')
                    inf[it->acc].rel='F';
                else quickex();
                break;
                case claim::liar:
                if (inf[it->acc].rel=='U')
                    inf[it->acc].rel='T';
                else quickex();
                break;
                case claim::thief:
                if (inf[it->acc].rel=='U'){
                    inf[it->acc].rel='U';
                    out.insert(it->acc);
                }
                else quickex();
                break;
            }
        }
    };
    inf.begin()->second.rel='T';
    func(inf.begin(),func);
    int tint=0;
    for (auto it=inf.begin();it!=inf.end();++it){
        if (it->second.rel=='U'){
            ++tint;break;
        }
    }
    for (auto it=inf.begin();it!=inf.end();++it){
        cout<<it->first<<"  "<<it->second.rel<<'\n';
        it->second.rel='U';
    }
    inf.begin()->second.rel='F';
    func(inf.begin(),func);
    for (auto it=inf.begin();it!=inf.end();++it){
        if (it->second.rel=='U'){
            ++tint;break;
        }
    }
    cout<<'\n';
    for (auto it=inf.begin();it!=inf.end();++it){
        cout<<it->first<<"  "<<it->second.rel<<'\n';
        it->second.rel='U';
    }
    if (tint==2){
        quickex();
    }
    cout<<"woo\n";
}