#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define TMP_PATH	"/data/app-lib/FortuneZombie"

void rm_tmpfile(void){

	struct stat st;

	if(stat(TMP_PATH, &st) == -1){
		printf("## Didn't detecet %s\n", TMP_PATH);
		exit(EXIT_FAILURE);
	}

	DIR *dir = opendir(TMP_PATH);
	if(dir == NULL){
		perror("Open Dir failed");
		exit(EXIT_FAILURE);
	}

	struct dirent *entry;
	while((entry = readdir(dir)) != NULL){
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
		  continue;

		char path[1024];
		snprintf(path, sizeof(path), "%s/%s", TMP_PATH, entry->d_name);

		if (lstat(path, &st) == -1) {
			perror("lstat");
			exit(EXIT_FAILURE);
		}

		if(strncmp(entry->d_name, "tmp.", 4) == 0){
			unsigned char rm_file[1024] = {0x00};
			printf("filename : %s\n", entry->d_name);
			sprintf(rm_file, "%s/%s", TMP_PATH, entry->d_name);	
			remove(rm_file);
		}
		/*
		if (S_ISDIR(st.st_mode)) {
			chmod_recursive(path, mode);
		}
		if (chmod(path, mode) == -1) {
			perror("chmod");
			exit(EXIT_FAILURE);
		}
		*/
	}
    closedir(dir);
}

int main(void){

	sleep(60);

	rm_tmpfile();

	return 0;
}
