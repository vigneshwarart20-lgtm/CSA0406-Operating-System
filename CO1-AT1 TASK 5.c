
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        perror("File opening failed");
        return 1;
    }

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}

