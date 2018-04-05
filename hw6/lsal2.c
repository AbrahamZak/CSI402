#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void filePermissions(struct stat info);

int main(int argc, const char * argv[]) {
    //Set up to get all information needed
    DIR *p;
    struct dirent *d;
    struct stat info;
    
    //If there are no arguments, print details of everything in current directory
    if (argc==1){
        p=opendir("./");
        //If any errors opening, print the error to stderr
        if(p==NULL)
        {
            fprintf(stderr, "ls: %s: No such file or directory\n", argv[1]);
            return 0;
        }
        //Read through everything in directory
        while((d=readdir(p))){
            //String for current spot
            char current[256];
            strcpy(current, "./");
            strcat(current, d->d_name);
            if (stat(current, &info) == -1)
            {
            }
            //Get the user owner of file/directory and group owner of file/directory
            struct passwd *pw = getpwuid(info.st_uid);
            struct group  *gr = getgrgid(info.st_gid);
            //Print the permissions
            filePermissions(info);
            printf(" ");
            //Print the amount of links
            printf("%ld ", (long) info.st_nlink);
            //Print the owner
            printf("%s ", pw->pw_name);
            //Print the group
            printf("%s ", gr->gr_name);
            //Print the file/directory size
            printf("%ld ", (long) info.st_size);
            //Print last access date/time
            //We make a time struct to alter our format to match ls
            struct tm *tm;
            // Store or calculated time into tm
            tm = localtime(&info.st_mtime);
            //Buffer for our new time format
            char buffer[200];
            if (tm->tm_year == 118){
                //If current year reformat it according to ls with time
                strftime(buffer, sizeof(buffer), "%b %d %H:%M", tm);
            }
            //If not reformat according to ls with year
            else{
                strftime(buffer, sizeof(buffer), "%b %d %Y", tm);
            }
            //Print the time
            printf("%s ", buffer);
            //Print the file/directory name
            printf("%s\n", d->d_name);
        }
        
    }
    //If there is an argument, print details of everything in that directory/file
    if (argc>=2){
        int i;
        for (i=1; i<=argc-1; i++){
        //Check if we have a file or directory in our arguments
        struct stat path_stat;
        stat(argv[i], &path_stat);
        //If it's a file continue printing details of the file
        if (S_ISREG(path_stat.st_mode)==1){
            if (stat(argv[i], &info) == -1)
            {
                fprintf(stderr, "Something went wrong at %s", argv[1]);
            }
            //Get the user owner of file and group owner of file
            struct passwd *pw = getpwuid(info.st_uid);
            struct group  *gr = getgrgid(info.st_gid);
            //Print the permissions
            filePermissions(info);
            printf(" ");
            //Print the amount of links
            printf("%ld ", (long) info.st_nlink);
            //Print the owner
            printf("%s ", pw->pw_name);
            //Print the group
            printf("%s ", gr->gr_name);
            //Print the file size
            printf("%ld ", (long) info.st_size);
            //Print last access date/time
            //We make a time struct to alter our format to match ls
            struct tm *tm;
            // Store or calculated time into tm
            tm = localtime(&info.st_mtime);
            //Buffer for our new time format
            char buffer[200];
            if (tm->tm_year == 118){
                //If current year reformat it according to ls with time
                strftime(buffer, sizeof(buffer), "%b %d %H:%M", tm);
            }
            //If not reformat according to ls with year
            else{
                strftime(buffer, sizeof(buffer), "%b %d %Y", tm);
            }
            //Print the time
            printf("%s ", buffer);
            //Print the file name
            printf("%s\n", argv[i]);
            continue;
        }
        if (argc>2){
            //If there are multiple directories/files, print the current one
            printf("%s: \n", argv[i]);
        }
        //If directory, we must open it and iterate through
        p=opendir(argv[i]);
        //If any errors opening, print the error to stderr
        if(p==NULL)
        {
            fprintf(stderr, "ls: %s: No such file or directory\n", argv[1]);
            return 0;
        }
        //Read through everything in directory
        while((d=readdir(p))){
            //String for current spot
            char current[256];
            strcpy(current, argv[i]);
            strcat(current, d->d_name);
            //If any errors, print to stderr
            if (stat(current, &info) == -1)
            {
                fprintf(stderr, "Something went wrong at %s", current);
            }
            //Get the user owner of file/directory and group owner of file/directory
            struct passwd *pw = getpwuid(info.st_uid);
            struct group  *gr = getgrgid(info.st_gid);
            //Print the permissions
            filePermissions(info);
            printf(" ");
            //Print the amount of links
            printf("%ld ", (long) info.st_nlink);
            //Print the owner
            printf("%s ", pw->pw_name);
            //Print the group
            printf("%s ", gr->gr_name);
            //Print the file/directory size
            printf("%ld ", (long) info.st_size);
            //Print last access date/time
            //We make a time struct to alter our format to match ls
            struct tm *tm;
            // Store or calculated time into tm
            tm = localtime(&info.st_mtime);
            //Buffer for our new time format
            char buffer[200];
            if (tm->tm_year == 118){
                //If current year reformat it according to ls with time
                strftime(buffer, sizeof(buffer), "%b %d %H:%M", tm);
            }
            //If not reformat according to ls with year
            else{
                strftime(buffer, sizeof(buffer), "%b %d %Y", tm);
            }
            //Print the time
            printf("%s ", buffer);
            //Print the file/directory name
            printf("%s\n", d->d_name);
        }
    }
    }
    return 0;
}

//Method to print the file/directory permissions using struct stat
void filePermissions(struct stat info)
{
    printf((S_ISDIR(info.st_mode)) ? "d" : "-");
    printf((info.st_mode & S_IRUSR) ? "r" : "-");
    printf((info.st_mode & S_IWUSR) ? "w" : "-");
    printf((info.st_mode & S_IXUSR) ? "x" : "-");
    printf((info.st_mode & S_IRGRP) ? "r" : "-");
    printf((info.st_mode & S_IWGRP) ? "w" : "-");
    printf((info.st_mode & S_IXGRP) ? "x" : "-");
    printf((info.st_mode & S_IROTH) ? "r" : "-");
    printf((info.st_mode & S_IWOTH) ? "w" : "-");
    printf((info.st_mode & S_IXOTH) ? "x" : "-");
}


