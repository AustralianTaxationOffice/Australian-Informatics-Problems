#include <iostream>
#include <climits>
using namespace std;
int main()
{
    freopen("vasesin.txt","r",stdin);
    freopen("vasesout.txt","w",stdout);
    int n; cin>>n;
    if (n>5)
        cout << "1 2 " << n-3 << '\n';
    else cout << "0 0 0\n";
}