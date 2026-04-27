#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Pred{
    bool operator()(const pair<int, int>& left, const pair<int, int>& right) const {
        if (left.second == right.second)
            return left.first < right.first;

        return left.second < right.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<pair<int, int>, Pred> meet;
    int start, end;
    for (int i=0; i<n; i++) {
        cin >> start >> end;
        meet.insert(make_pair(start, end));
    }

    vector<pair<int, int>> room;
    auto iter = meet.begin();
    start = iter->first;
    end = iter->second;
    room.emplace_back(start, end);

    int room_end;
    while (++iter != meet.end()) {
        start = iter->first;
        room_end = room.back().second;

        if (room_end <= start) {
            end = iter->second;
            room.emplace_back(start, end);
        }
    }

    cout << room.size();
}