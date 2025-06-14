#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, cnt, ans, b[101][101], vis[101][101];
queue<pair <int, int> > Q;
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    for(int m = 0; m <= 100; m++) {
        cnt = 0;
        for(int i = 0; i < n; i++) {
            fill(vis[i], vis[i] + n, 0);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(b[i][j] > m && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    Q.push({i, j});
                    cnt++;
                    while(!Q.empty()) {
                        pair<int, int> cur = Q.front(); Q.pop();
                        for(int d = 0; d < 4; d++) {
                            int x = cur.first + dx[d];
                            int y = cur.second + dy[d];
                            if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y] == 1 || b[x][y] <= m) continue;
                            vis[x][y] = 1;
                            Q.push({x, y});
                        }
                    }
                }
            }
        }
        if(cnt == 0) break;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}