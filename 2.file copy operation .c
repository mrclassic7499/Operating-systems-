#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *src, *dest;
    char buffer[1024];
    size_t bytesRead;
    src = fopen("source.txt", "rb");
    if (src == NULL) {
        printf("Error: Cannot open source.txt\n");
        exit(1);
    }
    dest = fopen("destination.txt", "wb");
    if (dest == NULL) {
        printf("Error: Cannot open/create destination.txt\n");
        fclose(src);
        exit(1);
    }
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    printf("File copied successfully!\n");
    fclose(src);
    fclose(dest);

    return 0;
}

