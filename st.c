#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <dirent.h>
#include<errno.h>

#include "getsha1.h"

char * read_file(char * filename){
    FILE *file;

    file = fopen (filename, "r");
    if(file==NULL){
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char * string1 = malloc(sizeof(char) * (length+1));

    char c;
    int i = 0;
    while((c = fgetc(file)) != EOF){
        string1 [i] = c;
        i++;
    }
    string1[i] = '\0';

    fclose(file);
    return string1;
}

int sttsMinku () {
    DIR * directory;
    struct dirent *entry ;

    directory = opendir(".");
    if(directory == NULL){
        printf("Error opening the directory.\n");
        return 1;
    }

    while((entry = readdir(directory)) != NULL){
        if(*(entry->d_name) == '.'){
            continue;
        }
        char * file_contents = read_file(entry->d_name);
        if(file_contents==NULL){
            printf("Error reading the file: %s", entry->d_name);
            continue;
        }

        printf("%s\n", entry->d_name);
        // printf("%s\n\n\n\n", file_contents);

//         printf("%s\n", entry->d_name);
//         unsigned char msg[]  = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";

        _chdir("./.minku");
        _chdir("obj");
        char* objName = entry->d_name;
        int retrieval = _mkdir(objName);
        // char iskaHash[30] = laaoSha1(file_contents);
        _chdir(objName);
        FILE * fptr;
        fptr = fopen(laaoSha1(file_contents), "w");
        fclose(fptr);
        _chdir("..");
        _chdir("..");
        _chdir("..");

        printf("%s\n\n\n" , laaoSha1(file_contents));
        // free(objName);
        free(file_contents);

    }

    if(closedir(directory) == -1){
        printf("Error closing the directory.\n");
        return 1;
    }
    return 0;
}