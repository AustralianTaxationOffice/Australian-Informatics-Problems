#include <iostream>
#include <string>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in ".txt","r",stdin); \
freopen(#out ".txt","w",stdout)
#define ll long long
string sr[2],r;
int n,sws;bool idx=false;
int main()
{
    piss(chimin,chimout);
    cin>>n>>sr[0]>>sr[1]>>r;
    int ib=0;
    ta:
    if (sr[0][ib]==r[ib]&&sr[1][ib]==r[ib]){
        ++ib;
        goto ta;
    }
    else if(sr[0][ib]==r[ib])
        idx=false;
    else idx=true;
    bool flag=false;
    for (int i=0;i<r.size();i++){
        if (sr[(int)idx][i]!=r[i]){
            idx=!idx;
            //cout<<i<<'\n';
            if (sr[(int)idx][i]!=r[i]){
                cout<<"PLAN FOILED\n";
                exit(0);
            }
            ++sws;
        }
    }
    cout<<"SUCCESS\n"<<sws<<'\n';
}