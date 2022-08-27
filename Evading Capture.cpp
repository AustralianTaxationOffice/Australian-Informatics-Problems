#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;
#define piss(in,out) \
ios::sync_with_stdio(false); \
cin.tie(0); \
freopen(#in,"r",stdin); \
freopen(#out,"w",stdout)

struct Node{
    vector<Node*> neighbours;
    bool odd=false;
    bool even=false;
    long long id=-1;
};
    Node* beg;
Node* nodesbyname;
Node& getbyname(long long nv)
{
    return nodesbyname[nv-1];
}
unordered_set<Node*> vld;
long long cr,k;
void visit(Node* node, long long depth)
{
    if (depth%2==k%2&&depth<=k&&vld.count(node)==0){
        vld.insert(node);
    }
}
/*void printTree(Node* node, long long tcount=0)
{
    //for (long long i=0;i<tcount;i++)
    //    cout<<'\t';
    //cout<<(node-beg)/sizeof(Node)<<'\n';
    node->visited=true;
    visit(node, tcount);
    if (tcount<k)
    for (auto it=node->neighbours.begin();it!=node->neighbours.end();++it){
        if (!(**it).visited){
            printTree(*it,tcount+1);
        }
    }
}*/
int main()
{
    piss(evadingin.txt,evadingout.txt);
    long long n,e,x;
    cin>>n>>e>>x>>k;
    nodesbyname=new Node[n];
    for (long long i=0;i<n;i++)
        nodesbyname[i].id=i+1;
    beg=&getbyname(x);
    for (long long i=0;i<e;i++){
        long long p1,p2;
        cin>>p1>>p2;
        getbyname(p1).neighbours.push_back(&getbyname(p2));
        getbyname(p2).neighbours.push_back(&getbyname(p1));
    }
    //cout<<n<<' '<<e<<' '<<x<<' '<<k<<'\n';
    queue<pair<Node*,long long>> q;
    q.push({beg,0});
    beg->even=true;
    long long tct=1;
    while (!q.empty()){
        Node* node=q.front().first;
        long long tcount=q.front().second;
        visit(node, tcount);
        q.pop();
        //cout<<node->id<<"  "<<tcount<<'\n';
        if (tcount<k){
            for (auto it=node->neighbours.begin();it!=node->neighbours.end();++it){
                if (((tcount+1)%2==1&&!(**it).odd)||((tcount+1)%2==0&&!(**it).even)){
                    (tcount+1)%2==0?(**it).even=true:(**it).odd=true;
                    q.push({*it,tcount+1});
                    ++tct;
                }
            }
        }
    }
    cout<<vld.size()<<'\n';
}