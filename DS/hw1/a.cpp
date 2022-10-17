#include<bits/stdc++.h>
using namespace std;

struct Loc {
    int x, y;
};

int m, n, limit;
bool placeX[100] = { false };
bool placeY[100] = { false };
bool placeSlash[100] = { false };
bool placeBackSlash[100] = { false };
vector<Loc> builtin, queens, maxQueens;

bool recursive(int startX) {
    for (auto x = startX; x < m; x++) {
        if (placeX[x]) {
            continue;
        }
        for (auto y = 0; y < n; y++) {
            Loc l = Loc {x, y};
            if (placeY[y] || placeSlash[x+y] || placeBackSlash[x-y+n-1]) {
                continue;
            }
            
            // place a queen
            placeX[x] = true;
            placeY[y] = true;
            placeSlash[x+y] = true;
            placeBackSlash[x-y+n-1] = true;
            queens.emplace_back(l);

            if (queens.size() > maxQueens.size()) {
                maxQueens.assign(queens.begin(), queens.end());
            }

            if (queens.size() == limit) {
                return true;
            }
            if (recursive(x+1)) {
                return true;
            }
            
            // revert
            placeX[x] = false;
            placeY[y] = false;
            placeSlash[x+y] = false;
            placeBackSlash[x-y+n-1] = false;
            queens.pop_back();
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int k, x, y;
    set<int> cntX, cntY;
    cin >> m >> n >> k;
    
    builtin.reserve(k);
    for (auto i = 0; i < k; i++) {
        cin >> x >> y;
        builtin.emplace_back(Loc {x, y});
        placeX[x] = true;
        placeY[y] = true;
        placeSlash[x+y] = true;
        placeBackSlash[x-y+n-1] = true;
        cntX.insert(x);
        cntY.insert(y);
    }

    if (m == n && m == 2) {
        limit = 1 - k;
    } else if (m == n && m == 3) {
        limit = 2 - k;
    } else {
        limit = min(m - cntX.size(), n - cntY.size());
    }

    if (limit <= 0) {
        cout << "0" << endl;
        return 0;
    }
    queens.reserve(limit);
    maxQueens.reserve(limit);
    recursive(0);

    cout << maxQueens.size() << endl;
    for (auto it = maxQueens.begin(); it != maxQueens.end(); advance(it,1)) {
        cout << (*it).x << ' ' << (*it).y << endl;
    }
}
