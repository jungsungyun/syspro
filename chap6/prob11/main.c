#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char type(mode_t);
void printStat(char*, char*, struct stat*, int, int, int);

int main(int argc, char **argv) {
    DIR *dp;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];
    char *dir;
    int show_inode = 0, show_quoted = 0, show_dir_slash = 0;

    int opt;
    while ((opt = getopt(argc, argv, "Qpi")) != -1) {
        switch (opt) {
            case 'Q': show_quoted = 1; break;
            case 'p': show_dir_slash = 1; break;
            case 'i': show_inode = 1; break;
            default:
               
                exit(1);
        }
    }

    dir = (optind < argc) ? argv[optind] : ".";

    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        exit(1);
    }

    while ((d = readdir(dp)) != NULL) {
        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0) {
            perror(path);
        } else {
            printStat(path, d->d_name, &st, show_inode, show_quoted, show_dir_slash);
        }
    }

    closedir(dp);
    return 0;
}

void printStat(char *pathname, char *file, struct stat *st, int show_inode, int show_quoted, int show_dir_slash) {
    if (show_inode) {
        printf("%8lu ", st->st_ino);
    }

    if (show_quoted) {
        printf("\"%s\"", file);
    } else {
        printf("%s", file);
    }

    if (show_dir_slash && S_ISDIR(st->st_mode)) {
        printf("/");
    }

    printf("\n");
}

