#include <set>
#include <iostream>
using namespace std;
int main(){
    set<int> remk;
    int n; cin>>n; int cr=0; int v;
    for (int i=0;i<n;i++){
        cin>>v;
        remk.insert(v);
    }
    cout<<*--remk.end()-*remk.begin()+1-remk.size()<<'\n';
}