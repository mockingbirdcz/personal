#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

#define E_DIR_404 ":( 404: this is not the path you're looking for, it doesn't lead anywhere\n"
#define E_COMM_404 ":( 404: this command doesn't exist\n"
#define I_HELP "!exit, !help\n"
#define I_GREETER "Hello there! Write '!help' if you don't know what to do.\nApplication will start in 5 seconds...\n"

void print_dir(char *path, char *cursor) {
    DIR *p_dir;
    struct dirent *ent;
    if ((p_dir = opendir (path)) != NULL) {
        while ((ent = readdir (p_dir)) != NULL) {
            printf ("%s\n", ent->d_name);
        }
        strcpy(cursor, path);
        closedir (p_dir);
    } else {
        printf(E_DIR_404);
    }
}

int main() {
    printf(I_GREETER);
    //sleep(5);
    char path[200] = "C:\\";
    char *p_print_dir;
    p_print_dir = path;
    char cursor[200] = "C:\\";
    char *p_cursor;
    p_cursor = cursor;
    print_dir(p_print_dir, p_cursor);
    while(1) {
        printf("\n%s > ", cursor);
        scanf(" %[^\n]", path);
        if (path[0] == '!') {
            if (strcmp(path,"!help")==0) {
                printf(I_HELP);
            } else if (strcmp(path,"!exit")==0) {
                return 1;
            } else {
                printf(E_COMM_404);
            }
        } else {
            print_dir(p_print_dir, p_cursor);
        }
    }
    return 0;
}