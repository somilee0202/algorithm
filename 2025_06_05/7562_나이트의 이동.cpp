#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int l; cin >> l;
        int start_x, start_y; cin >> start_x >> start_y;
        int end_x, end_y; cin >> end_x >> end_y;
        int vis[301][301] = {0};

        queue<pair<int, int> >Q;
        Q.push({start_x, start_y});
        while(!Q.empty()) {
            pair<int, int> cur = Q.front(); Q.pop();
            if(cur.first == end_x && cur.second == end_y) {
                cout << vis[cur.first][cur.second] << endl;
                break;
            }
            for(int d = 0; d < 8; d++) {
                int x = cur.first + dx[d];
                int y = cur.second + dy[d];
                if(x < 0 || y < 0 || x >= l || y >= l) continue;
                if(vis[x][y] > 0) continue;
                vis[x][y] = vis[cur.first][cur.second] + 1;
                Q.push({x, y});
            }
        }
    }
    return 0;
}