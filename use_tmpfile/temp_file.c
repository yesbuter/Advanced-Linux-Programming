#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

FILE* write_temp_file(char* buffer)
{
    /* 创建一个临时文件 */
    FILE* temp_file = tmpfile();
    /* 写入数据 */
    printf("写入长度:%d\n",fprintf(temp_file, "%s", buffer));
    return temp_file;
}

char* read_temp_file(FILE* temp)
{
    /* 把指针移动到文件的结尾，获取文件长度 */
    fseek(temp, 0, SEEK_END);
    int len = ftell(temp);
    /* 把指针移动到文件开头，读取文件 */
    rewind(temp);
    char* buffer = (char*) malloc (len + 1);
    //printf("读出:%s\n", fgets(buffer, len + 1, temp));
    fgets(buffer, len + 1, temp);
    return buffer;
}
