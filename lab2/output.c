#include <stdio.h>
#include "constants.h"
#include "debug.h"
#include "bits.h"

static void print_ST_X_Y_VX_VY(double* ball, unsigned char ch) {
	printf("%hhX    %9.5f %9.5f    %9.5f %9.5f\n", ch, ball[X], ball[Y], ball[VX], ball[VY]);	
}

void print_tab(double* ball, unsigned char ch, double time) {
	if(TEXT) {
		printf("ST    ___X_____ ___Y_____    ___VX____ ____VY____    ET= %.6f\n", time);
		print_ST_X_Y_VX_VY(ball, ch);
	}
}

void print_msg_off_table(double* ball, unsigned char ch) {
	if(TEXT) {
		printf("Off table: ");
		print_ST_X_Y_VX_VY(ball, ch);
	}
}

void print_msg_loaded(double* ball, unsigned char ch) {
	if(TEXT) {
		printf("Loaded %hhX %d ball at %.5f, %.5f %.5f deg %.5f ips\n", ch, get_color(ch), ball[X], ball[Y], ball[THETA], ball[FORCE]);
	}
}

void print_msg_launched(double* ball, unsigned char ch) {
	if(TEXT) {
		printf("Launched %hhX %d ball at %.5f, %.5f at %.5f, %.5f\n", ch, get_color(ch), ball[X], ball[Y], ball[VX], ball[VY]);
	}
}

void print_msg_L_wall(double* ball, unsigned char ch) {
	if(TEXT){
		printf("Left_ wall: ");
		print_ST_X_Y_VX_VY(ball, ch);
	}
}

void print_msg_R_wall(double* ball, unsigned char ch) {
	if(TEXT){
		printf("Right wall: ");
		print_ST_X_Y_VX_VY(ball, ch);
	}
}

void print_msg_T_wall(double* ball, unsigned char ch) {
	if(TEXT){
		printf("Upper wall: ");
		print_ST_X_Y_VX_VY(ball, ch);
	}
}
