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
#define ll long long
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vi A, B;
    ll int ans = 0, totA = 0, totB = 0;

    loopI(N) {
        int temp;
        cin >> temp;
        A.pb(temp);
        totA += temp;
    }
    totA = sum(A.begin(), A.end(), 0LL);

    loopI(M) {
        int temp;
        cin >> temp;
        B.pb(temp);
        totB += temp;
    }
    totB = sum(B.begin(), B.end(), 0LL);

    sort(B.begin(), B.end());

    while ((double)totA / N <= (double)totB / M && B.size() > 0)
    {
        int tmp = B[B.size() - 1];
        while (B[B.size() - 1] == tmp)
        {
            B.pob();
            ans += tmp;
            totA += tmp;
            totB -= tmp;
            N++;M--;
        }
    }

    if (B.size() == 0) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

