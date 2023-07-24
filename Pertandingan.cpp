#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define loopi(n) for (int i = 0; i < n; i++)
#define vpaint vector<pair<int,int>>

int main() {
    int N, M, maxSkill;
    int* pM = &M;
    cin >> N >> M;
    vpaint pemain(N);

    loopi(N) {
        cin >> pemain[i].first;
    }

    loopi(N) {
        cin >> pemain[i].second;
    }

    sort(pemain.begin(), pemain.end());

    loopi(N) {
        if (*pM >= pemain[i].first) {
            *pM += pemain[i].second;
        }
    }
    cout << *pM << endl;
    return 0;
} 