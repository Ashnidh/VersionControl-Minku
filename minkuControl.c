#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "initialiser.h"
#include "getsha1.h"
#include "cmt.h"
#include "st.h"

int main(){
    char msg[30];
    while(1){
        printf("Tell minku what to do: ");
        scanf("%[^\n]%*c", msg);
        if(strcmp(msg,"minku_ini")==0){
            initialiseMinkuRepo();
        }
        else if(strcmp(msg,"minku_st")==0){
            sttsMinku();
        }
        else if(strcmp(msg,"minku_cmt")==0){
            cmitMinku();
        }
        else if(strcmp(msg,"minku_quit")==0 || strcmp(msg,"minku_exit")==0){
            printf("Mujhe chhodkar...Jo tum jaaoge...\n");
            break;
        }
        else{
            printf("Invalid input bhai...Readme padhkar nahi aaye the kya ghar se..?\n");
        }
    }
    return 0;
}