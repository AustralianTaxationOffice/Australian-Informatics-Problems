#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("baublesin.txt", "r", stdin);
    freopen("baublesout.txt", "w", stdout);

    int red, blue; cin >> red >> blue;
    int spare; cin >> spare;
    int red_order, blue_order; cin >> red_order >> blue_order;

    int ans;

    if (red > red_order && blue > blue_order) {
        if (red_order == 0) {
            ans = blue - blue_order + spare;
        } else if (blue_order == 0) {
            ans = red - red_order + spare;
        } else {
            ans = min(red - red_order, blue - blue_order) + spare;
        }

    } else if (red < red_order && blue < blue_order) {
        ans = spare - (red_order - red + blue_order - blue);
    } else {
        if (blue_order == 0) {
            ans = spare - red_order + red;
        } else if (red_order == 0) {
            ans = spare - blue_order + blue;
        } else {
            ans = spare - max(red_order - red, blue_order - blue);
        }
    }

    ans++; // we sabotage one more bauble in order to stop him from fulfilling the order

    cout << max(ans, 0);
}
