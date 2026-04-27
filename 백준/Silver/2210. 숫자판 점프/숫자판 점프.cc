#include <iostream>
#include <set>

using namespace std;

char arr[5][5];
set<string> s;
string str;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int y, int x) {
    if (y < 0 || y > 4 || x < 0 || x > 4)
        return;

    str.push_back(arr[y][x]);
    if (str.size() == 6) {
        s.insert(str);
        str.pop_back();
        return;
    }

    for (int *d : dir)
        dfs(y + d[0], x + d[1]);
    
    str.pop_back();
}

int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) 
            dfs(i, j);

    cout << s.size();
}