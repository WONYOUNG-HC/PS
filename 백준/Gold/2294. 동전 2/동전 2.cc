#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int Bfs(int k, vector<int>& coins);

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i=0; i<n; i++)
        cin >> coins[i];

    cout << Bfs(k, coins);
}
struct Compare {
    bool operator()(const pair<int, int> &left, const pair<int, int> &right) {
        if (left.first != right.first)
            return left.first > right.first;

        return left.second < right.second;
    }
};

int Bfs(int k, vector<int>& coins) {
    bool visited[k+1];
    fill_n(visited, k+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        int cnt = pq.top().first;
        int money = pq.top().second;
        pq.pop();

        if (money == k)
            return cnt;

        for (int coin : coins) {
            if (money+coin > k || visited[money+coin])
                continue;

            visited[money+coin] = true;
            pq.emplace(cnt+1, money+coin);
        }
    }

    return -1;
}