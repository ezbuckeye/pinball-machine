#include <stdio.h>
#include "constants.h"
#include "debug.h"
#include "bits.h"
#include "output.h"
#include "lab2.h"
#include "physics.h"

double* ball;

unsigned char ch;

static int init_file_pointer(FILE** fp) {
	char file_path[200];
	scanf("%199s", file_path);
	*fp = fopen(file_path, "r");
	if(*fp == NULL) {
		printf("No such file.\n");
		return 0;
	}
	return 1;	
}
static int read_ball(FILE* fp, double* ball, unsigned char* ch) {
	return fscanf(fp, "%hhx %lf %lf %lf %lf", ch, &ball[X], &ball[Y], &ball[THETA], &ball[FORCE]);
}

static void after_read_ball(double* ball, unsigned char* ch) {
	/* output loaded */
	print_msg_loaded(ball, *ch);

	/* change status to in play */
	change_status_2(ch, ST_IN_PLAY);

	/* convert from polar -> rect */
	convert_polar_2_rect(ball);
	convert_THETA_FORCE_2_VX_VY(ball);	

	/* output launched */
	print_msg_launched(ball, *ch);
}

void input_loop_trigger() {
	FILE* fp;
	double ball[4];
	unsigned char ch;
	int ret;
	if(!init_file_pointer(&fp))	return;
	while((ret=read_ball(fp, ball, &ch))==5){
		after_read_ball(ball, &ch);	
		do_simulation(ball, ch);
	}
	if(TEXT) {
		printf("Final scanf call returned %d", ret);
	}
		
}
