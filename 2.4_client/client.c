#include <stdio.h>
#include <stdlib.h>

int main(){
    char* server_name = getenv("SERVER_NAME");
    if(server_name == NULL){
        /*环境变量SERVER_NAME不存在，使用默认值*/
        server_name = "server.my-company.com";
    }

    printf("accessing server %s\n", server_name);
    
    /*todo:在这里访问服务器*/

    return 0;
}
