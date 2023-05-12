#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>



int main(){
    printf("Microservice running:\n");
    char test[] = "go";
    while(1){
        Sleep(1000);
        FILE* readfile = fopen("starterfile.txt", "r");
        if(readfile == NULL){
            printf("File didn't open correctly. Terminating.");
            return 1;
        }

        char isGo[10];
        fscanf(readfile, "%s", isGo);
        int result = strcmp(test, isGo);
        
        if(result == 0){
            fclose((fopen("starterfile.txt", "w")));
            FILE* writefile = fopen("transferfile.txt", "w");
            printf("Please enter the token of the stock that you would like to see: ");
            char token[10];
            scanf("%s", &token);
            fprintf(writefile, "%s", token);
            fclose(writefile);
            printf("Resetting...\n");
            result = 1;
            strcpy(isGo, "");
        }
        fclose(readfile);
    }
    return 0;
}
