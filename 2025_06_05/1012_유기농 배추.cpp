#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int m, n, k; cin >> m >> n >> k;
        int arr[51][51] = {0};
        int vis[51][51] = {0};
        queue<pair<int, int> > Q;
        for(int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            arr[x][y] = 1;
        }

        int cnt = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == 0 || vis[i][j] == 1) continue;
                vis[i][j] = 1;
                Q.push({i, j});
                cnt++;

                while(!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int d = 0; d < 4; d++) {
                        int x = cur.first + dx[d];
                        int y = cur.second + dy[d];
                        if(x < 0 || y < 0 || x >= m || y >= n) continue;
                        if(arr[x][y] == 0 || vis[x][y] == 1) continue;
                        Q.push({x, y});
                    }
                    cout << Q.size() << endl;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}