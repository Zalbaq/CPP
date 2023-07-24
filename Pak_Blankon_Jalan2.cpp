#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vpaint vector<pair<int, int>>
#define vdoub vector<double>
#define vvdoub vector<vdoub>
#define vvpaint vector<vpaint>
#define loopi(n) for (int i = 0; i < n; i++)

int main() {
    int N, X, Y, pi, qi, visibleTree = 0;
    int* pVisibleTree = &visibleTree;
    bool straightFront, straightBehind, straightRight, straightLeft;
    vvdoub radianPerQuadrant(4);
    vector<double>::iterator itRadian;

    cin >> N >> X >> Y;

    loopi(N) {
        cin >> pi >> qi;
        if (straightFront == false && (pi == X && qi > Y))
        {
            *pVisibleTree += 1;
            straightFront = true;
        }
        else if (straightBehind == false && (pi == X && qi < Y))
        {
            *pVisibleTree += 1;
            straightBehind = true;
        }
        else if (straightRight == false && (pi > X && qi == Y))
        {
            *pVisibleTree += 1;
            straightRight = true;
        }
        else if (straightLeft == false && (pi < X && qi == Y))
        {
            *pVisibleTree += 1;
            straightLeft = true;
        }
        else {
            if (pi > X && qi > Y)
            {
                radianPerQuadrant[0].push_back(static_cast<double>(qi - Y) / (pi - X));
                sort(radianPerQuadrant[0].begin(), radianPerQuadrant[0].end());
            }
            else if (pi < X && qi > Y)
            {
                radianPerQuadrant[1].push_back(static_cast<double>(qi - Y) / (pi - X));
                sort(radianPerQuadrant[1].begin(), radianPerQuadrant[1].end());
            }
            else if (pi < X && qi < Y)
            {
                radianPerQuadrant[2].push_back(static_cast<double>(qi - Y) / (pi - X));
                sort(radianPerQuadrant[2].begin(), radianPerQuadrant[2].end());
            }
            else if (pi > X && qi < Y)
            {
                radianPerQuadrant[3].push_back(static_cast<double>(qi - Y) / (pi - X));
                sort(radianPerQuadrant[3].begin(), radianPerQuadrant[3].end());
            }
        }

    }


    loopi(radianPerQuadrant.size()) {
        itRadian = unique(radianPerQuadrant[i].begin(), radianPerQuadrant[i].end());
        radianPerQuadrant[i].resize(distance(radianPerQuadrant[i].begin(), itRadian));
        *pVisibleTree += radianPerQuadrant[i].size();
    }

    cout << "Jumlah: " << *pVisibleTree << endl;

    return 0;

}