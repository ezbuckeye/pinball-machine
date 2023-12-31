#include <math.h>
#include "bits.h"
#include "constants.h"
#include "output.h"

#define X_width 24.0
#define Y_depth 48.0
#define ACC_Y -47.052534795
#define ROB_LOSS 0.95


static void update_ball_pos(double* ball) {
	ball[X] += ball[VX] * DELTA_T;
	ball[Y] += ball[VY] * DELTA_T + 0.5*ACC_Y*DELTA_T*DELTA_T;
}

static void update_ball_vol(double* ball) {
	ball[VX] = ball[VX];
	ball[VY] += ACC_Y * DELTA_T;
}

void update_ball(double* ball) {
	update_ball_pos(ball);
	update_ball_vol(ball);
}
static void rob_energy_loss(double* ball) {
	ball[VX] *= ROB_LOSS;
	ball[VY] *= ROB_LOSS;
}

static void check_constr_L_wall(double* ball, unsigned char ch) {
	if(ball[X] < X_width/2){
		print_msg_L_wall(ball, ch);
		ball[X] += -X_width/2-ball[X];
		ball[VX] = -ball[VX];
		rob_energy_loss(ball);
	}
}

static void check_constr_R_wall(double* ball, unsigned char ch) {
	if(ball[X] > X_width/2){
		print_msg_R_wall(ball, ch);
		ball[X] -= ball[X]-X_width/2;
		ball[VX] = -ball[VX];
		rob_energy_loss(ball);
	}
}

static void check_constr_T_wall(double* ball, unsigned char ch) {
	if(ball[Y] > Y_depth){
		print_msg_T_wall(ball, ch);
		ball[Y] -= ball[Y]-Y_depth; 
		ball[VY] = -ball[VY];
		rob_energy_loss(ball);
	}
}
void check_constr_wall(double* ball, unsigned char ch) {
	check_constr_L_wall(ball, ch); 
	check_constr_R_wall(ball, ch); 
	check_constr_T_wall(ball, ch); 
}


int is_off_table(double* ball, unsigned char* ch) {
	int is_off;
	is_off = ball[Y]<0;
	if(is_off)	change_status_2(ch, ST_OFF_TABLE);	
	return is_off;
}

void convert_polar_2_rect(double* ball) {
	ball[THETA] = ball[THETA]*M_PI/180;
}

void convert_THETA_FORCE_2_VX_VY(double* ball) {
	double vx, vy;
	vx = ball[FORCE] * cos(ball[THETA]);
	vy = ball[FORCE] * sin(ball[THETA]);
	ball[VX] = vx;
	ball[VY] = vy;
}
