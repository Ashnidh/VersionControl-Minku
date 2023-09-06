#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <direct.h>
#include <dirent.h>
#include<errno.h>

#include <ftw.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int cmtNoActive = 1;
// time_t mtime = 0;
// char newest[1024];

const char* getFileCreationTime(char *path) {
    struct stat attr;
    stat(path, &attr);
    static char date[14+1];
    strftime(date, 20, "%Y%m%d%H%M%S", localtime(&(attr.st_ctime)));
    return date;
}

// char* checkifnewer(const char *path, const struct stat *sb, int typeflag)
// {
//     static char newest[1024];
//     time_t mtime = 0;
//     if (typeflag == FTW_F && sb->st_mtime > mtime) {
//         mtime = sb->st_mtime;
//         strncpy(newest, path, 1024);
//     }
//     return newest;
// }

int cmitMinku () {
// Making Directory in cmt folder for the given commit
    _chdir("./.minku");
    _chdir("./cmt");


        int cmtCurrrent;
        char* cmtmaxYet =  "0";
        DIR * directory;
        struct dirent *entry ;
        directory = opendir(".");
        if(directory == NULL){
        printf("Error opening the directory.\n");
        return 1;
    }while((entry = readdir(directory)) != NULL){
        if(*(entry->d_name) == '.'){
            continue;
        }
        char * aa1 = entry->d_name;
        if(strcmp(cmtmaxYet, aa1)<0){
            cmtmaxYet = aa1;
        }
    }
    printf("\n%s\n\n", cmtmaxYet);
    int cmtmaxYet_int = atoi(cmtmaxYet);
    cmtCurrrent = cmtmaxYet_int+1;
    // printf("\n%s\n", sha1Final);
    if(closedir(directory) == -1){
        printf("Error closing the directory.\n");
        return 1;
    }

    char str[5];
    sprintf(str, "%d", cmtCurrrent);
    // char cmtWritten[10] = "cmt";
    // strcat(cmtWritten, str);
    int retrieval = _mkdir(str);
    _chdir(str);
    printf("Cmt no. - %d\n", cmtCurrrent);
    _chdir("..");
    _chdir("..");
    _chdir("obj");
    char buffer[1024];
    _getcwd(buffer, 1024);
    printf("CWD - %s\n", buffer);

//made a directory with name = cmt$No.
    DIR * directory_bahar;
    struct dirent *folder_obj ;
    directory_bahar = opendir(".");

    if(directory_bahar == NULL){
        printf("Error opening the directory.\n");
        return 1;
    }while((folder_obj = readdir(directory_bahar)) != NULL){
        if(*(folder_obj->d_name) == '.'){
            continue;
        }
        _chdir(folder_obj->d_name);
            
        // char buffer[1024];
        // _getcwd(buffer, 1024);
        // char * p1 = buffer;
        // printf("%s\n", p1);
                // getFileCreationTime(p1);        


        // printf("%s\n", buffer);
        char* sha1Final;
        char* dateMin =  "19700101052999";
        DIR * directory;
        struct dirent *entry ;
        directory = opendir(".");
        if(directory == NULL){
        printf("Error opening the directory.\n");
        return 1;
    }while((entry = readdir(directory)) != NULL){
        if(*(entry->d_name) == '.'){
            continue;
        }
        int * dateAndTimeArray;
        char buffer[1024];
        _getcwd(buffer, 1024);
        char * p1 = buffer;
        printf("%s\n", p1);
        char * w1 = entry->d_name;
        // strcat("\\", w1);
        char ghgh[1] = "\\";
        strcat(p1, ghgh);
        strcat(p1, w1);
        printf("%s\n", p1);
        // printf("%s\n", getFileCreationTime(p1));
        // if(k<=time1){
            // k = time1;
        //     sha1Final = w1;
        // }
        if(strcmp(dateMin, p1)<=0){
            dateMin = p1;
            sha1Final = w1;
        }
    }
    // printf("\n%s\n", sha1Final);
    if(closedir(directory) == -1){
        printf("Error closing the directory.\n");
        return 1;
    }        
        
        // struct stat buf;          

        // stat(p1, &buf);

        // ftw(".", checkifnewer(p1, buf, FTW_F), 1); 



        _chdir("..");
        _chdir("..");
        _chdir("./cmt");
        _chdir(str);
        char* objName = folder_obj->d_name;
        int retrieval = _mkdir(objName);
        // char iskaHash[30] = laaoSha1(file_contents);
        _chdir(objName);
        FILE * fptr;
        fptr = fopen(sha1Final, "w");
        fclose(fptr);
        _chdir("..");
        _chdir("..");
        _chdir("..");
        _chdir("./obj");
        

    }
    if(closedir(directory_bahar) == -1){
        printf("Error closing the directory.\n");
        return 1;
    }
    _chdir("..");
    _chdir("..");
    
    char buffer1[1024];
    _getcwd(buffer1, 1024);
    printf("CWD - %s\n", buffer1);

    return 0;
}