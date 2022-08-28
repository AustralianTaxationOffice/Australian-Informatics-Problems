#include <iostream>
#include <cmath>
#include <vector>
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
struct stack{
    vector<int> v;
    inline void push(int i){
        v.push_back(i);
    }
    inline void pop(){
        v.pop_back();
    }
    int& top(){
        return v.back();
    }
};
signed main()
{
    piss(stacks);
    stack st;
    while (true){
        int iv;cin>>iv;
        if (iv==-2)break;
        else if (iv==-1){
            st.pop();
        }
        else st.push(iv);
        if (!st.v.empty()){
            for (auto it:st.v){
                cout<<it<<' ';
            }
        }
        else cout<<"stack is empty!";
        cout<<'\n';
    }
}