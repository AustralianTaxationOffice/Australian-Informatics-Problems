#include <unordered_map>
#include <iostream>
using namespace std;
int main(){
    unordered_map<int,int> cct;
    int n; cin>>n;
    int a;
    for (int i=0;i<n;i++){
        cin>>a;
        ++cct[a];
    }
    int cr=0;
    for (auto it=cct.begin();it!=cct.end();++it){
        cr=max(cr,it->second);
    }
    cout<<cr<<'\n';
}