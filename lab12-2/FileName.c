#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ".UTF8");

    struct tm* mytime;
    time_t t;

    t = time(NULL);
    mytime = localtime(&t);

    int m = mytime->tm_mon;
    const char* season = (m == 11 || m <= 1) ? "Зима" : (m <= 4) ? "Весна" : (m <= 7) ? "Лето" : "Осень";
    int year2 = (mytime->tm_year + 1900) % 100;

    char time_msg[100];
    char option_msg[100];

    sprintf(time_msg, " Московское время %02d:%02d:%02d ", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    sprintf(option_msg, " Время года: %s | Год: '%02d ", season, year2);

    int len1 = 27;
    int len2 = (m == 11 || m <= 1 || m >= 8) ? 30 : 29;

    int s1 = (80 - len1) / 2;
    int s2 = (80 - len2) / 2;

    for (int r = 1; r <= 10; r++) {
        if (r == 5) {
            for (int i = 0; i < s1; i++) printf("*");
            printf("%s", time_msg);
            for (int i = 0; i < (80 - s1 - len1); i++) printf("*");
        }
        else if (r == 6) {
            for (int i = 0; i < s2; i++) printf("*");
            printf("%s", option_msg);
            for (int i = 0; i < (80 - s2 - len2); i++) printf("*");
        }
        else {
            for (int i = 0; i < 80; i++) printf("*");
        }
        printf("\n");
    }

    return 0;
}