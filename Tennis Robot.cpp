#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("tennisin.txt", "r", stdin);
    freopen("tennisout.txt", "w", stdout);

    int b, n; cin >> b >> n;

    int a[b];
    vector<int> r(b); // r: remaining number
    for (int i = 0; i < b; i++) {
        int c; cin >> c;
        a[i] = c;
        r[i] = c;
    }

    sort(r.begin(), r.end());
    int sub = *min_element(r.begin(), r.end());

    vector<int> subs; subs.push_back(sub); // the vector of all subtractions we're going to make
    int bestValue = sub;
    for (int i = 1; i < b; i++) {
        int diff = r[i] - bestValue;
        if (diff > 0) {
            subs.push_back(diff);
            bestValue = r[i];
        }
    }

    int remaining = b;
    int totalsub = 0, j = 0, iter = 0;

    while (n > sub * remaining) { // while it is safe to remove an entire chunk of sub
        n -= sub * remaining;
        totalsub += sub;
        for (int i = j; i < b; i++) {
            // subtract sub from all bins
            r[i] -= sub;
            if (r[i] == 0) {
                j = i; // optimisation: we don't need to check the bins before this one
                remaining--; // remove this bin
            }
        }

        sub = subs[++iter];
    }

    // it is no longer safe to remove from everyone

    vector<int> can_use; // bins that we can still use
    for (int i = 0; i < b; i++) {
        if (a[i] > totalsub) can_use.push_back(i);
        // we can still use this bin as it has more capacity than what we used
    }

    int final_i = (n-1) % can_use.size();
    int final_bin = can_use[final_i] + 1;

    cout << final_bin << endl;
}
