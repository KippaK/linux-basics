#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Käyttö: %s <tiedostonimi>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    struct stat file_info;

    // Käytetään stat-järjestelmäkutsua tiedoston tietojen hakemiseen
    if (stat(filename, &file_info) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Tulostetaan tiedoston tiedot
    printf("Tiedoston tiedot: %s\n", filename);
    printf("Koko: %lld tavua\n", (long long)file_info.st_size);
    printf("Luontiaika: %s", ctime(&file_info.st_ctime));

    return 0;
}
