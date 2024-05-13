#include <stdio.h>
#include <string.h>
#include <stdbool.h> 


FILE *infile;
FILE *outfile;

int main(int argc, char *argv[]) {

    char *DbugMode = "on";
    char *encryptionKey = NULL;
    int AddOrSub = 0; // 1 = add , -1 = sub
    FILE *infile = stdin;
    FILE *outfile = stdout;

    for (int i = 1; i < argc; i++) {

        // argv[i] == "-D" compares addresses and not values. thats why i used strcmp
        if (strcmp(argv[i], "-D") == 0) {
            DbugMode = "off";
        } else if (strcmp(argv[i], "+D") == 0) {
            DbugMode = "on";
        } else {
            if (strncmp(argv[i], "+e", 2) == 0 || strncmp(argv[i], "-e", 2) == 0) { 
                // Check if we have encryption key & save the key (as char array)
                AddOrSub = (strncmp(argv[i], "+e", 2) == 0)? 1 : -1; 
                encryptionKey = argv[i] + 2;
            }
            else if (strcmp(DbugMode, "on") == 0) {
                // %s\n ---> %s means argument is a string. \n tells the printer to add new line after printing the argument.
                fprintf(stderr, "%s\n", argv[i]);
            }
        }
    }


    int ch;
    int index_InEncryptionKey = 0;
    bool lowerCase = false;
    bool upperCase = false;
    bool digit = false;

    // fgetc : reads a single character from the specified input stream.
    // It returns the character read as an unsigned char cast to an int, 
    // or EOF if an error occurs or if the end of the file is reached.
    while ((ch = fgetc(infile)) != EOF) {
        lowerCase = (ch >= 'a' && ch <= 'z')? true: false;
        upperCase = (ch >= 'A' && ch <= 'Z')? true: false;
        digit = (ch >= '0' && ch <= '9')? true: false;
        if (strcmp(DbugMode, "on") == 0) {

            if (AddOrSub != 0) {
                if (ch != '\n' && (lowerCase | upperCase | digit)) {
                    // Convert char to int :
                    int digit_InEncryptionKey = encryptionKey[index_InEncryptionKey] - '0'; 
                    
                    if (AddOrSub == 1) {
                        // Encode
                        ch += digit_InEncryptionKey;
                    } else {
                        // Decode
                        ch -= digit_InEncryptionKey;
                    }
                    // Cases where z+1=a, a-1=z, etc.
                    if (lowerCase){
                        if (ch > 'z')
                            ch -= 26;
                        else if (ch < 'a')
                            ch += 26;
                    }
                    if (upperCase){
                        if (ch > 'Z')
                            ch -= 26;
                        else if (ch < 'A')
                            ch += 26;
                    }
                    if (digit){
                        if (ch > '9')
                            ch -= 26;
                        else if (ch < '0')
                            ch += 26;
                    }
                }
                // Move :
                index_InEncryptionKey = (index_InEncryptionKey + 1) % strlen(encryptionKey);
            }

            // fputc : writes a single character to the specified output stream.
            // It takes an int argument representing the character to write and returns the 
            // character written as an unsigned char cast to an int, or EOF if an error occurs
            fputc(ch, outfile);
        }
    }

    // fclose :  closes the file associated with the specified stream.
    // It flushes any buffered output and releases any resources associated with the file.
    // After closing a file, further operations on the stream (e.g., reading or writing) are not allowed.
    fclose(outfile);

    return 0;
}