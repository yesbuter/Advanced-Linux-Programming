#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int temp_file_handle;

extern temp_file_handle write_temp_file(char* buffer, size_t length);
extern char* read_temp_file(temp_file_handle temp_file, size_t* length);

int main(int argc, char* argv[])
{
    char* read_buffer;
    size_t length;
    temp_file_handle fd;
    if(argc > 1){
        /* 有参数就用第一个字符串来测试两个函数 */
        printf("The argument is %s\n", argv[1]);
        length = strlen(argv[1]);
        printf("Length is %ld\n", length);
        fd = write_temp_file(argv[1], length);
        read_buffer = read_temp_file(fd, &length);
    }
    printf("Output: %s\n", read_buffer);
    free(read_buffer);
    return 0;
}
