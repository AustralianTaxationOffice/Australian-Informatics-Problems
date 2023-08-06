#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("spacein.txt", "r", stdin);
    freopen("spaceout.txt", "w", stdout);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    vector<long long> diff(n), diffPrefixSum(n);

    long long tmpSum = 0;
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
        diffPrefixSum[i] = (tmpSum += diff[i]);
    }

    sort(diffPrefixSum.begin(), diffPrefixSum.end());

    const int HALF_n = (n - 1) >> 1;
    long long ans = 0, sub = diffPrefixSum[HALF_n];
    for (int i = 0; i < n; i++) {
        ans += abs(diffPrefixSum[i] - sub);
    }

    cout << ans << endl;
}
