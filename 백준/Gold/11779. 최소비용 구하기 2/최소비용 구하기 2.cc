#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 0x3fffffff

using namespace std;

vector<pair<int, int>> graph[1001];

void Dijkstra(int n, int start, int end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }

    int start, end;
    cin >> start >> end;

    Dijkstra(n, start, end);
}

void Dijkstra(int n, int start, int end) {
    int distance[n+1], touch[n+1];
    fill(distance, distance+(n+1), INF);
    distance[start] = 0; touch[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distance[node] < cost)
            continue;

        for (pair<int, int>& next : graph[node]) {
            if (distance[next.second] > cost + next.first) {
                distance[next.second] = cost + next.first;
                touch[next.second] = node;
                pq.emplace(distance[next.second], next.second);
            }
        }
    }

    vector<int> path;
    int city = end;
    path.push_back(city);
    while (touch[city]) {
        path.push_back(touch[city]);
        city = touch[city];
    }

    cout << distance[end] << '\n';
    cout << path.size() << '\n';
    for (auto riter = path.rbegin(); riter != path.rend(); riter++)
        cout << *riter << ' ';
}