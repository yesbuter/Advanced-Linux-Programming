#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE* write_temp_file(char* buffer);
extern char* read_temp_file(FILE* temp);

int main(int argc, char* argv[])
{
    char* buffer;
    FILE* fd;
    if(argc > 0){
        printf("Argument is: %s\n", argv[1]);
        fd = write_temp_file(argv[1]);
        buffer = read_temp_file(fd);
        printf("Output: %s\n", buffer);
        free(buffer);
    }
    fclose(fd);
    return 0;
}
