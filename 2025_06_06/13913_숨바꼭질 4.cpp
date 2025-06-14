#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int n, k, arr[100001];
queue<int> Q;
void ft_print() {
    int cur = k;
    stack<int> S;
    while(cur != n) {
        S.push(cur);
        cur = arr[cur];
    } S.push(n);
    
    cout << S.size() - 1 << endl;
    while(!S.empty()) {
        cout << S.top() << ' ';
        S.pop();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fill(arr, arr + 100001, -1);
    arr[n] = n;
    Q.push(n);

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == k) {
            ft_print();
            return 0;
        }
        if(cur -1 >= 0 && arr[cur - 1] == -1) {
            arr[cur - 1] = cur;
            Q.push(cur - 1);
        } 
        if(cur + 1 <= 100000 && arr[cur + 1] == -1) {
            arr[cur + 1] = cur;
            Q.push(cur + 1);
        }
        if(cur * 2 <= 100000 && arr[cur * 2] == -1) {
            arr[cur * 2] = cur;
            Q.push(cur *2);
        }
    }
    return 0;
}