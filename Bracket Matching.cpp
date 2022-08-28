#include <iostream>
#include <cmath>
#include <stack>
#include <string>
using namespace std;
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define piss(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define int long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
signed main()
{
    speed();
    stack<char> bracs;
    int n;cin>>n;
    string s;cin>>s;
    for (auto it:s){
        if (it=='('||it=='{'||it=='['){
            bracs.push(it);
        }
        else if (it==')'||it=='}'||it==']'){
            if (!bracs.empty()&&(bracs.top()=='('&&it==')'||bracs.top()=='{'&&it=='}'||bracs.top()=='['&&it==']')){
                bracs.pop();
            }
            else{
                cout<<"NO\n";
                exit(0);
            }
        }
    }
    if (bracs.empty())
        cout<<"YES\n";
    else cout<<"NO\n";
}