#include<stdio.h>
#include<stdlib.h>
#include<direct.h>
#include<errno.h>

int initialiseMinkuRepo (){
    int retrieval = _mkdir(".minku");
        if(errno==EEXIST){
            printf("Manhh..! It's already a '.minku' repo...\n");
        }
        else {
            _chdir("./.minku");
            _mkdir("obj");
            _mkdir("cmt");
            _mkdir("refsss");
            _chdir("./refsss");
            _mkdir("heads");
            _chdir("..");
            char path_for_HEAD[30] = "ref: refsss/heads/origBranch";
            FILE * fptr;
            fptr = fopen("./HEAD", "w");
            fprintf(fptr, path_for_HEAD);
            fclose(fptr);
            _chdir("..");
        }
    // Printing the path for current working directory
        char buffer[1024];
        _getcwd(buffer, 1024);
        printf("%s\n", buffer);
    return 0;
}