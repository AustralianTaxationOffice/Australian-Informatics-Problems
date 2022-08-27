#include <climits>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int d,c0,p1,c1,p2,c2;
int main()
{
    freopen("cookiesin.txt","r",stdin);
    freopen("cookiesout.txt","w",stdout);
    cin>>d>>c0>>p1>>c1>>p2>>c2;
    int m1=d*c0;
    int ck=c0,_c=0,m2,m3,m4,m5;bool cdg1=false;
    for (int i=0;i<d;i++){
        _c+=ck;
        if (!cdg1&&_c>=p1){
            _c-=p1;
            ck+=c1;
            cdg1=true;
        }
    }
    m2=_c;
    ck=c0;_c=0;cdg1=false;
    for (int i=0;i<d;i++){
        _c+=ck;
        if (!cdg1&&_c>=p2){
            _c-=p2;
            ck+=c2;
            cdg1=true;
        }
    }
    m3=_c;
    ck=c0;_c=0;cdg1=false;
    int px=p1,cx=c1;bool cdg2=true;
    for (int i=0;i<d;i++){
        _c+=ck;
        if (!cdg1&&_c>=px){
            _c-=px;
            ck+=cx;
            cdg1=true;
            cdg2=false;
        }
        if (!cdg2&&_c>=p2){
            _c-=p2;
            ck+=c2;
            px=p2;cx=c2;
            cdg2=true;
        }
    }
    m4=_c;
    ck=c0;_c=0;
    px=p2;cx=c2;cdg1=false;cdg2=true;
    for (int i=0;i<d;i++){
        _c+=ck;
        if (!cdg1&&_c>=px){
            _c-=px;
            ck+=cx;
            cdg1=true;
            cdg2=false;
        }
        if (!cdg2&&_c>=p1){
            _c-=p1;
            ck+=c1;
            px=p1;cx=c1;
            cdg2=true;
        }
    }
    m5=_c;
    cout<<max({m1,m2,m3,m4,m5})<<'\n';
}