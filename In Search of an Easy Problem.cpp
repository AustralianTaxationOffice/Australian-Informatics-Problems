#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int ez;
    for (int i=0;i<n;i++){
        cin>>ez;
        if (ez){
            cout<<"HARD\n";
            return 0;
        }
    }
    cout<<"EASY\n";
}