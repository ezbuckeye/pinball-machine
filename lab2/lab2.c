#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "bits.h"
#include "n2.h"
#include "output.h"
#include "physics.h"
#include "constants.h"

int main() {
	double start, runtime;

	start = now();

	/* initialization */
	input_loop_trigger(); 

	runtime = now() - start;
	printf("Total runtime is %.9lf seconds\n", runtime);\

	return EXIT_SUCCESS;
}

void do_simulation(double* ball, unsigned char ch) {
	double start, clock;
	int cur_interval;

	start = now();
	cur_interval = 0;
	while(!is_off_table(ball, ch)) { 
		clock = now() - start;
		if(clock >= cur_interval*DELTA_T){
			/* if hit the wall */
			check_constr_wall(ball, ch);
			/* Output the ball */
			print_tab(ball, ch, cur_interval*DELTA_T);
			/* Update the clock */
			cur_interval++;
			/* Update the ball floating point data */	
			update_ball(ball); 
		}
	}
	print_msg_off_table(ball, ch);
	change_status_2(&ch, ST_OFF_TABLE); 
}
