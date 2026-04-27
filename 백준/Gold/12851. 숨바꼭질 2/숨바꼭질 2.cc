#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void Bfs(int n, int k);

int main() {
    int n, k;
    cin >> n >> k;
    Bfs(n, k);
}

vector<int> Move(int n, int k, int current) {
    vector<int> v;

    if (current * 2 <= max(k*2, n))
        v.push_back(current * 2);
    if (current + 1 <= max(k*2, n))
        v.push_back(current + 1);
    if (current - 1 >= 0)
        v.push_back(current - 1);

    return v;
}

void Bfs(int n, int k) {
    vector<pair<int, int>> visited(max(k*2, n)+1, {1000000, 0});
    vector<int> touch(max(k*2, n)+1, -1);
    queue<pair<int, int>> q;
    q.emplace(0, n);
    visited[n].first = 0; visited[n].second = 1;

    while (!q.empty()) {
        int time = q.front().first;
        int current = q.front().second;
        q.pop();

        if (current == k)
            break;

        vector<int> next = Move(n, k, current);
        for (int pos : next) {
            if (visited[pos].first > time + 1) {
                visited[pos].first = time + 1;
                visited[pos].second = visited[current].second;
                touch[pos] = current;
                q.emplace(time+1, pos);
            }
            else if (visited[pos].first == time + 1) {
                visited[pos].second += visited[current].second;
            }
        }
    }

    cout << visited[k].first << '\n' << visited[k].second;
}