#include <bits/stdc++.h>
using namespace std;

#define loopI(n) for (int i = 0; i < n; i++)
#define int long long
#define all(a) a.begin(), a.end()

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    M += K;
    vector<int> A(N);
    loopI(N) {
        cin >> A[i];
    }
    sort(all(A));
    int ans = 0;
    loopI(N) {
        int l = 0, r = N - 1, id = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            // Mencari botol yang berguna yaitu botol dengan kemampuan > tinggi pohon saat ini
            if (A[mid] <= M) {
                l = mid + 1;
            }
            else {
                id = mid;
                r = mid - 1;
            }
        }
        cout << A[id] << endl;
        if (id == -1) continue;
        M = A[id];
        M += K;
        ans++;
    }
    cout << ans << endl;
    return 0;
}