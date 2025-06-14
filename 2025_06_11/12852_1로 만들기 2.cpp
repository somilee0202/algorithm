#include <iostream>

using namespace std;

int n, b[2][1000002];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    b[0][1] = 0;
    for(int i = 2; i <= n; i++) {
        b[0][i] = b[0][i - 1] + 1;
        b[1][i] = i - 1;
        if(i % 2 == 0 && b[0][i] > b[0][i / 2] + 1) {
            b[0][i] = b[0][i / 2] + 1;
            b[1][i] = i / 2;
        }
        if(i % 3 == 0 && b[0][i] > b[0][i / 3] + 1) {
            b[0][i] = b[0][i / 3] + 1;
            b[1][i] = i / 3;
        }
    }
    cout << b[0][n] << endl;
    cout << n << ' ';
    while(n > 1) {
        cout << b[1][n] << ' ';
        n = b[1][n];
    }
    return 0;
}