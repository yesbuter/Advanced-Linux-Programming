#include <stdio.h>

int main(int argc, char * argv[]){
    printf("The name of this program is '%s'.\n", argv[0]);
    printf("This program was invoked with %d arguments.\n", argc - 1);

    /*指定了命令行参数吗？*/
    if(argc > 1){
        /*有则输出这些参数*/
        int i;
        printf("The arguments are:\n");
        for(i = 1; i < argc; i++){
            printf(" %s\n", argv[i]);
        }
    }
    return 0;
}
