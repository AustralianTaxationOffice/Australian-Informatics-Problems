#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define piss(name) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define ll long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
bool validsq(int (&sq)[3][3]){
    return
    (sq[0][0]+sq[0][1]+sq[0][2]==sq[1][0]+sq[1][1]+sq[1][2])&&
    (sq[0][0]+sq[0][1]+sq[0][2]==sq[2][0]+sq[2][1]+sq[2][2])&&
    (sq[0][0]+sq[0][1]+sq[0][2]==sq[0][0]+sq[1][0]+sq[2][0])&&
    (sq[0][0]+sq[0][1]+sq[0][2]==sq[0][1]+sq[1][1]+sq[2][1])&&
    (sq[0][0]+sq[0][1]+sq[0][2]==sq[0][2]+sq[1][2]+sq[2][2])&&
    sq[0][0]>0&&sq[1][0]>0&&sq[2][0]>0&&
    sq[0][1]>0&&sq[1][1]>0&&sq[2][1]>0&&
    sq[0][2]>0&&sq[1][2]>0&&sq[2][2]>0;
}
int main()
{
    piss(magic);
    int sq[3][3]{0};
    cin>>sq[0][0]>>sq[1][0]>>sq[0][1];
    if (sq[1][0]>sq[0][1]){
        sq[1][2]=1;
        sq[2][1]=sq[1][0]+1-sq[0][1];
    }
    else{
        sq[2][1]=1;
        sq[1][2]=sq[0][1]+1-sq[1][0];
    }
    sq[2][2]=sq[0][0]+sq[0][1]-sq[1][2];
    int c=1;
    while (!validsq(sq)){
        sq[2][0]=c;
        sq[0][2]=sq[1][0]+sq[2][0]-sq[0][1];
        sq[1][1]=sq[0][0]+sq[1][0]+sq[2][0]-sq[0][1]-sq[2][1];
        ++c;
    }
    cout<<sq[0][0]<<' '<<sq[1][0]<<' '<<sq[2][0]<<'\n'<<
    sq[0][1]<<' '<<sq[1][1]<<' '<<sq[2][1]<<'\n'<<
    sq[0][2]<<' '<<sq[1][2]<<' '<<sq[2][2]<<'\n';
}