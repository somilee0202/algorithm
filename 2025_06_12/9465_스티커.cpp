#include <iostream>

using namespace std;

int T, n, b[2][100001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> b[i][j];
            }
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 2; j++) {
                b[(j + 1) % 2][i] += max(b[j][i - 1], b[j][i - 2]);
            }
        }
        cout << max(b[0][n], b[1][n]) << endl;
    }
    return 0;
}