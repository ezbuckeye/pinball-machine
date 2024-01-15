#include <stdio.h>
#include "constants.h"
#include "debug.h"
#include "bits.h"
#include "output.h"
#include "lab2.h"
#include "physics.h"

static int read_ball(double* ball, unsigned char* ch) {
	return scanf("%hhx %lf %lf %lf %lf", ch, &ball[CX], &ball[CY], &ball[THETA], &ball[FORCE]);
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
	double ball[4];
	unsigned char ch;
	int ret;
	while((ret=read_ball(ball, &ch))==5){
		after_read_ball(ball, &ch);	
		do_simulation(ball, ch);
	}
	if(TEXT) {
		printf("Final scanf call returned %d\n", ret);
	}
		
}
