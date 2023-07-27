#include <bits/stdc++.h>
using namespace std;

#define loopI(n) for (int i = 0; i < n; i++)
#define int long long
#define vec vector
#define pub push_back
#define pob pop_back

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vec<int> a(n),b(m);
    vec<vec<int>> uv(k);

    loopI(n){
        cin >> a[i];
    }
    loopI(m){
        cin >> b[i];
    }
    loopI(k){
        int idx = 0;
        int temp;

        cin >> temp;
        cin >> uv[i].push_back(temp);
    }
    if(b.size() == 0) cout << -1 << endl;
    return 0;
}
