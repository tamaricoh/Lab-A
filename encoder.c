#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *Dbug_mode = "on";

    for (int i = 1; i < argc; i++) {

        // argv[i] == "-D" compares addresses and not values. thats why i used strcmp
        if (strcmp(argv[i], "-D") == 0) {
            Dbug_mode = "off";
        } else if (strcmp(argv[i], "+D") == 0) {
            Dbug_mode = "on";
        } else {
            if (strcmp(Dbug_mode, "on") == 0) {
                // %s\n ---> %s means argument is a string. \n tells the printer to add new line after printing the argument.
                fprintf(stderr, "%s\n", argv[i]);
            }
        }
    }
    return 0;
}