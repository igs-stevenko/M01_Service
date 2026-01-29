#include <utils/Log.h>
#include <fcntl.h>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>
#include <cutils/android_reboot.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

enum {

		TYPE_DIR = 0,
		TYPE_FILE,
		TYPE_UNKNOW
};

int get_type(mode_t mode){

	int rtn = TYPE_UNKNOW;

	switch(S_IFMT & mode){
		case S_IFREG:
			rtn = TYPE_FILE;
			break;

		case S_IFDIR:
			rtn = TYPE_DIR;
			break;

		default:
			break;

	}

	return rtn;
}

int rm_dir(const char *cur_dir){

	int rtn = 0;
	DIR *dp = NULL;
	struct dirent *de = NULL;
	struct stat st;
	int type = TYPE_UNKNOW;
	unsigned char obj_full_name[256] = {0x00};
	unsigned char dir_full_name[256] = {0x00};


	dp = opendir(cur_dir);
	if(dp == NULL){
		printf("### [%s][%d] : failed to open %s ###\n"
					, __func__, __LINE__, cur_dir); 
		rtn = -1;
		goto end;
	}

	de = readdir(dp);

	for(;de != NULL; de=readdir(dp)){

		if(strncmp(de->d_name, ".", 1) == 0 && strlen(de->d_name) == 1){
			continue;
		}

		if(strncmp(de->d_name, "..", 2) == 0){
			continue;
		}

		memset(obj_full_name, 0, sizeof(obj_full_name));
		memset(dir_full_name, 0, sizeof(dir_full_name));

		memset(&st, 0, sizeof(struct stat));

		sprintf((char *)obj_full_name, "%s%s", (char *)cur_dir, (char *)de->d_name);

		rtn = lstat((const char *)obj_full_name, &st);
		if(rtn < 0){
			perror("lstat failed\n");
			printf("### [%s][%d] : %s lstat failed \n###\n"
						, __func__, __LINE__, obj_full_name); 
			rtn = -2;
			goto end;
		}

		type = get_type(st.st_mode);

		switch(type){

			case TYPE_FILE:
				{
					rtn = remove((const char *)obj_full_name);
					if(rtn != 0){
						printf("RM %s failed\n", obj_full_name);
						perror("[ERROR] : ");
					}

					break;
				}
			case TYPE_DIR:
				{
					unsigned char next_path[256] = {0x00};
					sprintf((char *)next_path, "%s/", obj_full_name);
					rtn = rm_dir((const char *)next_path);
					if(rtn != 0){
						printf("### [%s][%d] ###\n", __func__, __LINE__);
					}


					break;
				}
			default:
				break;
		}
	}

	rtn = remove((const char *)cur_dir);
	if(rtn != 0){
		printf("RM %s failed\n", cur_dir);
		perror("[ERROR] : ");
	}

	rtn = 0;

	closedir(dp);

end:

	return rtn;
}


void remove_data(const char *pkgname){

	unsigned char remove_cache[128] = {0x00};
	unsigned char remove_files[128] = {0x00};
	unsigned char remove_shared_prefs[128] = {0x00};

	struct timeval start;
	struct timeval finish;
	unsigned long total_finish = 0;

	sprintf((char *)remove_cache, "/data/data/%s/cache/", pkgname);
	sprintf((char *)remove_files, "/data/data/%s/files/", pkgname);
	sprintf((char *)remove_shared_prefs, "/data/data/%s/shared_prefs/", pkgname);


	gettimeofday(&start, NULL);

	rm_dir((const char *)remove_cache);
	rm_dir((const char *)remove_files);
	rm_dir((const char *)remove_shared_prefs);

	gettimeofday(&finish, NULL);
	total_finish = (1000000 * (finish.tv_sec - start.tv_sec)) + (finish.tv_usec - start.tv_usec);
	printf("total_finish = %lu\n", total_finish);
}


