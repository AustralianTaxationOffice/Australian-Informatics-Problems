#include <iostream>
#include <cmath>
using namespace std;
int x,y;
int main(){
    freopen("robotin.txt", "r", stdin);
    freopen("robotout.txt", "w", stdout);
    int k;string input;
    cin>>k>>input;
    for(auto it=input.begin();it!=input.end();++it){
        switch (*it){
        case 'N':++y;break;
        case 'E':++x;break;
        case 'S':--y;break;
        case 'W':--x;break;
        }
    }
    cout<<abs(x)+abs(y);
}