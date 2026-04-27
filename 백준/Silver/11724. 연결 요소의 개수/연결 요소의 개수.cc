#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[10001] = {false};

void Bfs(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node, edge;
    cin >> node >> edge;

    int start, end;
    for (int i=0; i<edge; i++) {
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int cnt = 0;
    for (int i=1; i<node+1; i++) {
        if (!visited[i]) {
            Bfs(i);
            cnt++;
        }
    }

    cout << cnt;
}

void Bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i : graph[x]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
