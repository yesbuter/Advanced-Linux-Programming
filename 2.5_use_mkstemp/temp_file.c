#include <stdlib.h>
#include <unistd.h>

/* 用于保存write_temp_file创建的临时文件的句柄类型，在这个实现中他是一个文件描述符*/
typedef int temp_file_handle;

/*将BUFFER中的LENGTH字节内容写入临时文件。
  临时文件会立刻被执行unlink操作。
  返回指向临时文件的句柄*/
temp_file_handle write_temp_file(char* buffer, size_t length)
{
    /* 创建文件名和文件。XXXXXX会被替换以生成不重复的文件名 */
    char temp_filename[] = "/tmp/temp_file.XXXXXX";
    int fd = mkstemp(temp_filename);
    /* 立刻进行unlink，从而使这个文件在我们关闭描述符的时候被删除 */
    unlink(temp_filename);
    /* 将数据的长度写入文件 */
    write(fd, &length, sizeof(length));
    /* 现在再写入数据本身 */
    write(fd, buffer, length);
    /* 将文件描述符作为指向文件的句柄 */
    return fd;
}

/*将wirte_temp_file建立的临时文件TEMP_FILE中的内容读。
  函数返回一块新分配的缓冲区，其中包含了这些内容。调用者必须使用free释放这个缓冲区。
  *LENGTH被设置为数据的长度，以字节计。临时文件最后被删除。*/
char* read_temp_file(temp_file_handle temp_file, size_t* length)
{
    char* buffer;
    /* 句柄TEMP_FILE是一个指向临时文件的描述符 */
    int fd = temp_file;
    /* 回滚到文件开始的地方 */
    lseek(fd, 0, SEEK_SET);
    /* 读取数据的长度 */
    read(fd, length, sizeof(*length));
    /* 分配缓冲区，然后读取内存 */
    buffer = (char*) malloc (*length);
    read(fd, buffer, *length);
    /* 关闭文件描述符。这会导致临时文件从系统中删除 */
    close(fd);
    return buffer;
}
