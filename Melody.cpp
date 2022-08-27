#include <climits>
#include <array>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
int n,k;
std::array<unordered_map<int,int>, 3> counts;
int c1 = INT_MAX,c2 = INT_MAX,c3 = INT_MAX;
int main(){
    freopen("melodyin.txt", "r", stdin);
    freopen("melodyout.txt", "w", stdout);
    cin>>n>>k;
    for (int i=0;i<n/3;i++){
        int note;
        cin>>note;
        counts[0][note]++;
        cin>>note;
        counts[1][note]++;
        cin>>note;
        counts[2][note]++;
    }
    int c1,c2,c3;
    c1=n/3-max_element(counts[0].begin(), counts[0].end(), [](auto a, auto b){return a.second<b.second;})->second;
    c2=n/3-max_element(counts[1].begin(), counts[1].end(), [](auto a, auto b){return a.second<b.second;})->second;
    c3=n/3-max_element(counts[2].begin(), counts[2].end(), [](auto a, auto b){return a.second<b.second;})->second;
    cout<<c1+c2+c3<<'\n';
}