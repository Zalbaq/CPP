#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <numeric>
#define vi vector<int>
#define loopI(n) for (int i = 0; i < n; i++)
#define sum accumulate
#define pb push_back
#define pob pop_back
using namespace std;

int main() {
    int N, M, ans = 0, maxWeight;
    double avgA, avgB;

    cin >> N >> M;
    vi A, B;

    loopI(N) {
        int temp;
        cin >> temp;
        A.pb(temp);
    }

    loopI(M) {
        int temp;
        cin >> temp;
        B.pb(temp);
    }
    sort(B.begin(), B.end());

    avgA = static_cast<double>(sum(A.begin(), A.end(), 0)) / A.size();
    avgB = static_cast<double>(sum(B.begin(), B.end(), 0)) / B.size();

    if (avgA > avgB)
    {
        ans = -1;
    }
    else {
        while (avgA <= avgB && B.size() > 1)
        {
            maxWeight = *max_element(B.begin(), B.end());
            A.pb(maxWeight);
            B.pob();
            ans += maxWeight;

            while (maxWeight == B.back() && B.size() > 1)
            {
                maxWeight = B.back();
                A.pb(maxWeight);
                B.pob();
                ans += maxWeight;
            }

            avgA = static_cast<double>(sum(A.begin(), A.end(), 0)) / A.size();
            avgB = static_cast<double>(sum(B.begin(), B.end(), 0)) / B.size();
        }

    }

    cout << ans << endl;

    return 0;
}