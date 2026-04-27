#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> lecture;

int MinLectureRoom(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    lecture.resize(n);
    for (int i=0; i<n; i++) {
        int start, end;
        cin >> start >> end;
        lecture[i] = {start, end};
    }

    cout << MinLectureRoom(n);
}

struct Pred {
     bool operator()(const pair<int, int>& left, const pair<int, int>& right) {
        if (left.second != right.second)
            return left.second > right.second;
        return left.first > right.first;
    }
};

int MinLectureRoom(int n) {
    sort(lecture.begin(), lecture.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, Pred> pq;

    pq.emplace(lecture[0].first, lecture[0].second);
    for (int i=1; i<n; i++) {
        if (pq.top().second <= lecture[i].first)
            pq.pop();

        pq.emplace(lecture[i].first, lecture[i].second);
    }

    return (int)pq.size();
}