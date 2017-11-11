#include <stdio.h>
#include <stdlib.h>

/* ENVIRON 变量包含了整个环境 */
extern char** environ;

int main(){
    char** var;
    for(var = environ; *var != NULL; var++){
        printf("%s\n", *var);
    }
    //getenv测试
    printf("-----------分割线----------\n");
    if(getenv("USER") != NULL){
        printf("USER=%s\n", getenv("USER"));
    }
    else
      printf("USER IS NULL\n");
    return 0;
}
