#include <bits/stdc++.h>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in,"r",stdin); \
freopen(#out,"w",stdout)

bool test=false;
bool check(string& dna, int _piss)
{
    char c[]={'S','N','A','K','E','\0'};
    int idx=0;
    int ct=0;
    for (int i=0;i<dna.size();i++){
        if (test)
            cout<<dna[i]<<"  "<<c[idx]<<"  "<<ct<<'\n';
        if (dna[i]==c[idx]){
            ++ct;
        }
        if (ct>=_piss){
            if (++idx==5)
                return true;
            ct=0;
        }
    }
    return false;
}
int main()
{
    piss(snakein.txt,snakeout.txt);
    int n;string dna;
    cin>>n>>dna;
    int low=0,high=n/5;
    while (low!=high){
        int mid=(low+high+1)/2;
        if (check(dna,mid)){
            low=mid;
        }
        else high=mid-1;
    }
    cout<<low<<'\n';
    //cout<<ltrs['S']<<"  "<<ltrs['N']<<"  "<<ltrs['A']<<"  "<<ltrs['K']<<"  "<<ltrs['E']<<'\n';
}