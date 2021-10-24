#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

// A structure for storong entries
typedef struct {
    int iNum;
    char links[100];
    long numLinks;
    char nameFile[100];
} FileEntry;

// Constructing new entry
FileEntry newFileEntry(int iNum, char *name) {
    FileEntry entry;
    
    entry.iNum = iNum;
    strcpy(entry.links, name);
    entry.numLinks = 1;
    strcpy(entry.nameFile, name);

    return entry;
}

int main() {

    struct dirent *dirEntry;
    struct stat eStat;
    FileEntry entries[200];
    unsigned int entryNum = 0;

    // openning a directory
    DIR *tmpDir = opendir("tmp");
    if (!tmpDir) {
        perror("Cannot open the directory.\n");
        return -1;
    }

    while ((dirEntry = readdir(tmpDir))) {
        
        char fileName[100];
        strcpy(fileName, "tmp/");
        strcat(fileName, dirEntry->d_name);

        if (stat(fileName, &eStat)) {
            return ENOENT; //Error NO ENTry
        }
        
        char num = 0;
        for (int i = 0; i < entryNum; ++i) {
          // searching the links
            if (entries[i].iNum == eStat.st_ino) {
                num++;
                strcat(strcat(entries[i].links, ", "), dirEntry->d_name);
                entries[i].numLinks++;
                
                break;
            }
        }
        if (!num) {
            entryNum++;
            entries[entryNum] = newFileEntry(eStat.st_ino, dirEntry->d_name);
        }
    }
    
    // printing the results
    for (int i = 0; i < entryNum; i++) {
        if (entries[i].numLinks >= 2) {
            printf("%s - ", entries[i].nameFile);
            printf("%s, ", entries[i].links);
            printf("\n");
        }
    }

    closedir(tmpDir);

    return 0;
}