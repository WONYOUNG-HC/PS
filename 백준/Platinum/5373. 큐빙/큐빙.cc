#include <iostream>
#include <string>

int n;
std::string command;

char up[3][3];
char down[3][3];
char front[3][3];
char right[3][3];
char back[3][3];
char left[3][3];

void init_cube() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            up[i][j] = 'w';
            down[i][j] = 'y';
            front[i][j] = 'r';
            right[i][j] = 'b';
            back[i][j] = 'o';
            left[i][j] = 'g';
        }
    }
}

void y(int col) {
    char tmp[3][3];

    for (int i = 0; i < 3; i++) {
        tmp[i][col] = front[i][col];
    }

    for (int i = 0; i < 3; i++) {
        front[i][col] = up[i][col];
    }

    for (int i = 0; i < 3; i++) {
        up[2 - i][col] = back[i][col];
    }

    for (int i = 0; i < 3; i++) {
        back[i][col] = down[i][col];
    }

    for (int i = 0; i < 3; i++) {
        down[2 - i][col] = tmp[i][col];
    }

    if (col == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = left[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                left[2 - j][i] = tmp[i][j];
            }
        }
    } else if (col == 2) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = right[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                right[2 - j][i] = tmp[i][j];
            }
        }
    }
}

void z(int row) {
    char tmp[3][3];

    for (int i = 0; i < 3; i++) {
        tmp[row][i] = front[row][i];
    }

    for (int i = 0; i < 3; i++) {
        front[row][i] = right[row][i];
    }

    for (int i = 0; i < 3; i++) {
        right[row][2 - i] = back[row][i];
    }

    for (int i = 0; i < 3; i++) {
        back[row][i] = left[row][i];
    }

    for (int i = 0; i < 3; i++) {
        left[row][2 - i] = tmp[row][i];
    }

    if (row == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = up[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                up[j][2 - i] = tmp[i][j];
            }
        }
    } else if (row == 2) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = down[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                down[j][2 - i] = tmp[i][j];
            }
        }
    }
}

void x(int row) {
    char tmp[3][3];

    for (int i = 0; i < 3; i++) {
        tmp[row][i] = up[row][i];
    }

    for (int i = 0; i < 3; i++) {
        up[row][2 - i] = left[i][2 - row];
    }

    for (int i = 0; i < 3; i++) {
        left[i][2 - row] = down[row][i];
    }

    for (int i = 0; i < 3; i++) {
        down[row][2 - i] = right[i][2 - row];
    }

    for (int i = 0; i < 3; i++) {
        right[i][2 - row] = tmp[row][i];
    }

    if (row == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = back[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                back[j][2 - i] = tmp[i][j];
            }
        }
    } else if (row == 2) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = front[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                front[j][2 - i] = tmp[i][j];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc;

    std::cin >> tc;

    while (tc--) {
        std::cin >> n;

        init_cube();

        for (int i = 0; i < n; i++) {
            std::cin >> command;
            
            switch (command[0]) {
            case 'U':
                z(0);

                if (command[1] == '-') {
                    z(0);
                    z(0);
                }

                break;
            case 'D':
                z(2);

                if (command[1] == '+') {
                    z(2);
                    z(2);
                }
                
                break;
            case 'F':
                x(2);

                if (command[1] == '-') {
                    x(2);
                    x(2);
                }

                break;
            case 'B':
                x(0);

                if (command[1] == '+') {
                    x(0);
                    x(0);
                }

                break;
            case 'L':
                y(0);

                if (command[1] == '-') {
                    y(0);
                    y(0);
                }

                break;
            case 'R':
                y(2);

                if (command[1] == '+') {
                    y(2);
                    y(2);
                }

                break;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << up[i][j];
            }
            std::cout << '\n';
        }
    }
}