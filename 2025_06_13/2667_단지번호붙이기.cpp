#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    char c[26][26];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    int cnt = 0;
    int vis[26][26] = {0};
    queue<pair<int, int> > Q;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(c[i][j] == '0' || vis[i][j] == 1) continue;
            cnt++;
            vis[i][j] = 1;
            Q.push({i, j});

            int area = 0;
            while(!Q.empty()) {
                area++;
                pair<int, int> cur = Q.front(); Q.pop();
                for(int dis = 0; dis < 4; dis++) {
                    int x = cur.first + dx[dis];
                    int y = cur.second + dy[dis];
                    if(x < 0 || y < 0 || x >= n || y >= n) continue;
                    if(c[x][y] == '0' || vis[x][y] == 1) continue;
                    vis[x][y] = 1;
                    Q.push({x, y});
                }
            }
            pq.push(area);
        }
    }
    cout << cnt << endl;
    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}