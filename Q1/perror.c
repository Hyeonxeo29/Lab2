#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_perror(const char* str){
	fprintf(stderr, "%s : %s\n", str, strerror(errno));
}
int main(int argc, char *argv[]){
	FILE *f;

	if(argc<2){
		printf("Usage : perror file_name\n");
		exit(1);
	}

	if((f=fopen(argv[1], "r")) == NULL){
		my_perror("fopen");
		exit(1);
	}

	printf("\"%s\" 파일 오픈\n", argv[1]);
	fclose(f);
}
