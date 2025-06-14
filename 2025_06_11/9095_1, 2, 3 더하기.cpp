#include <iostream>

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int n, b[11]; cin >> n;
        b[1] = 1; b[2] = 2; b[3] = 4;
        for(int i = 4; i <= n; i++)
            b[i] = b[i - 1] + b[i - 2] + b[i - 3];
        cout << b[n] << endl;
    }
    return 0;
}