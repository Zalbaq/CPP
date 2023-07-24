#include <iostream>
#include <algorithm>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#include <vector>
using namespace std;
#define loop(n) for (int i = 0; i < n; i++)

int main(){
    fast_io
    int N;
    cin >> N;
    vector<int> X;


    loop(N){
        int item;
        cin >> item;
        X.push_back(item);
    }

    sort(X.begin(), X.end());

    loop(N){
        for(int x : X){
            if (x%10 == i)
            {
                cout << x << "\n";
            }
            
        }
    }

    return 0;
}