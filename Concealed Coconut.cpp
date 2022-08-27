#include <iostream>
#include <cmath>
using namespace std;
#define piss(name) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define ll long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
int e2(int val)
{
    return val*val;
}
float dist(int x1,int x2,int y1,int y2)
{
    return sqrt(float(e2(x2-x1)+e2(y2-y1)));
}
int main()
{
    piss(coco);
    int ix,iy,id,cx,cy,cd;
    cin>>ix>>iy>>id>>cx>>cy>>cd;
    float d=dist(ix,cx,iy,cy);
    if ((d-(float)id<=cd&&cd<=d+(float)id)&&((float)id-d<=cd&&cd<=(float)id+d)){
        cout<<"yes\n";
    }
    else cout<<"no\n";
}