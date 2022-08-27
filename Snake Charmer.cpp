#include <iostream>
#include <string>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in ".txt","r",stdin); \
freopen(#out ".txt","w",stdout)
#define ll long long
int x,y;char dir='N';
string cr;
int x0=0,y0=0;
void sw(char& c){
    if (c=='L')
        c='R';
    else c='L';
}
char move(char inst)
{
    if (x0==x&&y0==y){
        cout<<cr<<'\n';
        exit(0);
    }
    cr.push_back(inst);
    if (inst=='R'){
        switch (dir){
            case 'N':++x0;dir='E';break;
            case 'E':--y0;dir='S';break;
            case 'S':--x0;dir='W';break;
            case 'W':++y0;dir='N';break;
        }
        return 'L';
    }
    else{
        switch (dir){
            case 'N':--x0;dir='W';break;
            case 'E':++y0;dir='N';break;
            case 'S':++x0;dir='E';break;
            case 'W':--y0;dir='S';break;
        }
        return 'R';
    }
}
int main()
{
    piss(snakein,snakeout);
    cin>>x>>y;
    char id;
    if (x>=0&&y>=0){
        move('R');move('L');id='R';
    }
    else if (x>=0&&y<0){
        move('R');move('R');id='L';
    }
    else if (x<0&&y>=0){
        move('L');move('R');id='L';
    }
    else if (x<0&&y<0){
        move('L');move('L');id='R';
    }
    while (y!=y0&&x!=x0){
        move(id);sw(id);
        move(id);sw(id);
    }
    mstr:
    int li=0;char l[4]{'R','R','L','L'};
    if (x>x0){
        if (dir=='S')li=2;
    }
    else if (y>y0){
        li=1;
    }
    else if (x<x0){
        if (dir=='N')li=2;
    }
    else if (y<y0){
        li=1;
    }
    int br=0;
    while (x0!=x||y0!=y){
        cout<<x0<<' '<<y0<<'\n';
        move(l[li]);
        ++li;
        if (li==4)li==0;++br;if(br>100)exit(-1);
    }
    cout<<cr<<'\n';
}