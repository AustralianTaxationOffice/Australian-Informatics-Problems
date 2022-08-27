#include <iostream>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define piss(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define ll long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
char grid[2000][2000];
int main()
{
    piss(oil);
    int h,w,k;cin>>h>>w>>k;
    int xspil,yspil;
    int bean=w*h;
    for (int y=0;y<h;y++){
        for (int x=0;x<w;x++){
            char iv;cin>>iv;
            grid[x][y]=iv;
            if (iv=='$'){
                xspil=x;yspil=y;
            }
        }
    }
    queue<tuple<int,int,int>> q;
    if (xspil+1<w&&1<=k&&grid[xspil+1][yspil]=='.'){
        q.push({xspil+1,yspil,1});
        grid[xspil+1][yspil]='*';
    }
    if (xspil-1>=0&&1<=k&&grid[xspil-1][yspil]=='.'){
        q.push({xspil-1,yspil,1});
        grid[xspil-1][yspil]='*';
    }
    if (yspil+1<h&&1<=k&&grid[xspil][yspil+1]=='.'){
        q.push({xspil,yspil+1,1});
        grid[xspil][yspil+1]='*';
    }
    if (yspil-1<h&&1<=k&&grid[xspil][yspil-1]=='.'){
        q.push({xspil,yspil-1,1});
        grid[xspil][yspil-1]='*';
    }
    while (!q.empty()){
        int x,y,dp;x=get<0>(q.front());y=get<1>(q.front());dp=get<2>(q.front());
        if (x+1<w&&dp<k&&grid[x+1][y]=='.'){
            q.push({x+1,y,dp+1});
            grid[x+1][y]='*';
        }
        if (x-1>=0&&dp<k&&grid[x-1][y]=='.'){
            q.push({x-1,y,dp+1});
            grid[x-1][y]='*';
        }
        if (y+1<h&&dp<k&&grid[x][y+1]=='.'){
            q.push({x,y+1,dp+1});
            grid[x][y+1]='*';
        }
        if (y-1>=0&&dp<k&&grid[x][y-1]=='.'){
            q.push({x,y-1,dp+1});
            grid[x][y-1]='*';
        }
        q.pop();
        //cout<<q.size()<<'\n';
    }
    for (int y=0;y<h;y++){
        for (int x=0;x<w;x++){
            cout<<grid[x][y];
        }
        cout<<'\n';
    }
}