#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[12] = {1, 0, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2};
int dy[12] = {0, -1, 0, 1, -1, -2, -2, -1, 1, 2, 2, 1};
int k, n, m, x, y, z, b[201][201], vis[31][201][201];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    queue<tuple<int, int, int> > Q;
    vis[0][0][0] = 1;
    Q.push({0, 0, 0});
    while(!Q.empty()) {
        tuple<int, int, int> cur = Q.front(); Q.pop();
        if((get<1>(cur) == n - 1) && (get<2>(cur) == m - 1)) {
            cout << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] - 1 << endl;
            return 0;
        }
        for(int dis = 0; dis < 4; dis++) {
            int x = get<1>(cur) + dx[dis];
            int y = get<2>(cur) + dy[dis];

            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(b[x][y] || vis[get<0>(cur)][x][y]) continue;

            vis[get<0>(cur)][x][y] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({get<0>(cur), x, y});
        }
        if(get<0>(cur) == k) continue;
        for(int dis = 4; dis < 12; dis++) {
            int x = get<1>(cur) + dx[dis];
            int y = get<2>(cur) + dy[dis];

            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(b[x][y] || vis[get<0>(cur) + 1][x][y]) continue;

            vis[get<0>(cur) + 1][x][y] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({get<0>(cur) + 1, x, y});
        }
    }
    cout << "-1" << endl;
    return 0;
}