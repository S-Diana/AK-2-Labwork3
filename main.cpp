#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "V:L:hv";

	const struct option long_options[] = {
		{"Value",	required_argument,	NULL,'V'},
		{"List",	required_argument,	NULL,'L'},
		{"help",	no_argument,		NULL,'h'},
		{"version",	no_argument,		NULL,'v'},
		{NULL,		0,					NULL, 0}
	};

	int parse, idx = -1;

	bool cnt[4] = {false, false, false, false};

	while ((parse=getopt_long(argc, argv, 
							short_options, 
							long_options, 
							&idx))!=-1){
		switch(parse){
			case 'V': {
				if (!cnt[0]){
					
					printf("value = %s\n",optarg);
					cnt[0] = true;
				}
				break;
			}
			case 'L': {
				if (!cnt[1]){
					
					printf("list = %s\n",optarg);
					cnt[1] = true;
				}
				break;
			}
			case 'h': {
				if (!cnt[2]){
					
					printf("help.\n");
					cnt[2] = true;
				}
				break;
			}
			case 'v': {
				if (!cnt[3]){
					
					printf("version is 1.0.\n");
					cnt[3] = true;
				}
				break;
			}
			case '?': default: {
				printf("unknown option.\n");
				break;
			}
		}
		idx = -1;
	}
	return 0;
}