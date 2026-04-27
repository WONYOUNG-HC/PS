#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

int n;
vector<int> students;
vector<int> group;

int randint() {
    return rand() % (n + 1) + 1;
}

bool dfs(set<int>& route, const int start, int point) {
    if (start == point)
        return true;

    if (group[point] != -1)
        return false;

    if (route.find(point) != route.end()) {
        group[point] = 1;

        int next = students[point];
        while (point != next) {
            group[next] = 1;
            next = students[next];
        }

        return false;
    }

    route.insert(point);
    return dfs(route, start, students[point]);
}

int grouping() {
    int ans = 0;
    //try {
        group.resize(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (group[i] != -1)
                continue;

            set<int> s = {i};
            if (dfs(s, i, students[i])) {
                for (int j: s)
                    group[j] = 1;
            } else {
                for (int j: s)
                    if (group[j] == -1) group[j] = 0;
            }
        }

        //int ans = 0;
        for (int i = 1; i <= n; i++)
            if (group[i] == 0) ans++;

        group.clear();
    //}
    /*catch(exception& e) {
        cout << "exception \n";
        cout << n << '\n';
        for (int i = 1; i <= n; i++)
            cout << students[i] << ' ';
        exit(0);
    }*/

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //srand(time(NULL));
    int tc; cin >> tc;
    //int t = 1;
    while (tc--) {
        cin >> n;
        //n = rand() % 100001 + 1;
        students.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> students[i];
            //students[i] = randint();
        cout << grouping() << '\n';
        //grouping();
        //cout << '#' << t++ << " clear \n";
        students.clear();
    }
}