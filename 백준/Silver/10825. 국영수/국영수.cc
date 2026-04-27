#include <iostream>
#include <algorithm>

using namespace std;

struct Info {
    int kor;
    int eng;
    int math;
    string name;
};

bool Pred(const Info &left, const Info &right) {
    if (left.kor != right.kor)
        return left.kor > right.kor;
    if (left.eng != right.eng)
        return left.eng < right.eng;
    if (left.math != right.math)
        return left.math > right.math;
    return left.name < right.name;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Info student[n];
    for (int i = 0; i < n; i++) {
        int kor, eng, math;
        string name;
        cin >> name >> kor >> eng >> math;

        student[i].name = name;
        student[i].kor = kor;
        student[i].eng = eng;
        student[i].math = math;
    }

    sort(student, student + n, Pred);

    for (Info &i: student)
        cout << i.name << '\n';
}