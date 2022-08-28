#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
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
    piss(queues);
    deque<int> dq;
    while (true){
        int iv;cin>>iv;
        if (iv==-2){
            break;
        }
        else if (iv==-1){
            dq.pop_front();
        }
        else{
            dq.push_back(iv);
        }
        if (!dq.empty()){
            for (auto it:dq){
                cout<<it<<' ';
            }
        }
        else cout<<"queue is empty!";
        cout<<'\n';
    }
}