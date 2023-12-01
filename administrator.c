#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <fcntl.h>
#define MIN_VAL 0
#define MAX_VAL 9

void instanceAdd();
void instanceModify();
int main(void) {
    int n;
    printf("1 for instanceAdd , 2 for instanceModify:");
    scanf("%d", &n);
    if (n == 1) {
        instanceAdd();
    }
    else if (n == 2) {
        instanceModify();
    }

    return 0;
}

int error_handling[11][2] = { {MIN_VAL, 4}, {MIN_VAL, 1}, {MIN_VAL, 1}, {MIN_VAL, 1}, {MIN_VAL, 1},
{MIN_VAL, 1}, {MIN_VAL, 3}, {1, MAX_VAL}, {MIN_VAL, 1}, {MIN_VAL, 1}, {MIN_VAL, MAX_VAL} };
void instanceAdd() {
    char name[20] = { 0, };
    int i;
    FILE* f_destinations;

    f_destinations = fopen("destination_data", "a");

    printf("instance name: ");
    scanf("%s", name);


    bool scanning = true;
    char temp[12];
    while (scanning) {
        for (i = 0; i < 11; i++) temp[i] = 0;
        printf("11 values (with no space): ");
        scanf("%s", temp);

        for (i = 0; i < 11; i++) {
            if (temp[i] < error_handling[i][0] + 48 || temp[i] > error_handling[i][1] + 48) {
                printf("wrong value on %d\n", i + 1);
                scanning = false;
                break;
            }
        }
        if (scanning) {
            scanning = false;
        }
        else {
            scanning = true;
        }
    }

    putc('\n', f_destinations);
    fputs(name, f_destinations);
    for (i = 0; i < 11; i++) {
        putc(',', f_destinations);
        putc(temp[i], f_destinations);
    }

    fclose(f_destinations);
}

void instanceModify() {   //modifying instance
    int fd_destinations;
    char temp[8192] = { 0, };
    int n, num = 0, end = 1, i = 0, val;

    fd_destinations = open("destination_data", O_RDWR);

    n = read(fd_destinations, temp, 8192);

    printf("instance number: ");
    scanf("%d", &num);
    while (num != end) {
        if (temp[i] == '\n') end++;
        if (temp[i] == 0) {
            printf("number is too high");
            return;
        }
        i++;
    }

    while (temp[i] != ',') {
        i++;
        if (i > 8192) return;
    }

    while (1) { // for instance, infinitely select value
        printf("select attribute (0 ~ 10): ");
        scanf("%d", &num);
        if (num == -1) return;

        if (num > 10 || num < 0) {
            printf("wrong value\n");
        }
        else {
            printf("write value (%d ~ %d): ", error_handling[num][0], error_handling[num][1]);
            scanf("%s", &temp);

            if (temp[0] < error_handling[num][0] + 48 || temp[0] > error_handling[num][1] + 48) {
                printf("wrong value\n");
                continue;
            }
            lseek(fd_destinations, i + 2 * num + 1, SEEK_SET);
            write(fd_destinations, temp, 1);
        }
    }

    close(fd_destinations);
}
