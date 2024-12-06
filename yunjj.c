#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int BinToInt(const char *str) {
    int r = 0;
    size_t len = strlen(str);
    for (int i = 0; i < len; i++) {
        r |= ((str[i] - '0') << (len - 1 - i));
    }
    return r;
}

int main(void) {
    char str[][32] = {"1", "10", "11", "100", "11111111", "1110000111100001111000011110000"};
    int org[] = {1, 2, 3, 4, 255, 1894838512};

    for (int i = 0; i < 6; i++) {
        printf("%s의 원래 숫자는 %d이며, BintoInt를 거친 결과는 %d이며 이는 %s똑같습니다.\n",
        str[i], org[i], BinToInt(str[i]), org[i] == BinToInt(str[i]) ? "" : "안 ");
    }
}
