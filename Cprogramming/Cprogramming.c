#include <stdio.h>
void main() {

    int mines[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
    int field[4][4] = { {0,1,0,1},{0,0,0,1},{1,1,1,0},{0,1,1,1} };

    int w = 4, h = 4;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (field[y][x] == 0) continue;
            for (int j = y - 1; j <= y + 1; j++) {
                for (int i = x - 1; i <= x + 1; i++) {
                    if (chkover(w, h, j, i) == 1)
                        mines[j][i] += 1;
                }
            }
        }
    }
}

int chkover(int w, int h, int j, int i) {
    if (i >= 0 && i < w && j >= 0 && j < h) return 1;
    return 0;
}

// 정보처리기사 기출 문제
// 1	1	3	2
// 3	4	5	3
// 3	5	6	4
// 3	5	5	3