#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
int dz[6] = {1, -1, 0, 0, 0, 0};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h; cin >> m >> n >> h;
    int arr[101][101][101] = {-1};
    int vis[101][101][101] = {0};
    queue<tuple<int, int, int> >Q;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                int n; cin >> n;
                arr[k][j][i] = n;
                if(n == 1) Q.push({k, j, i});
            }
        }
    }
    int cnt = 0;
    while(!Q.empty()) {
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for(int d = 0; d < 6; d++) {
            int x = get<0>(cur) + dx[d];
            int y = get<1>(cur) + dy[d];
            int z = get<2>(cur) + dz[d];
            if(x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= h) continue;
            if(arr[x][y][z] != 0) continue;
            arr[x][y][z] = arr[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            cnt = arr[x][y][z] - 1;
            Q.push({x, y, z});
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(arr[k][j][i] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}