#define st_shift 6
#define st_mask 0X03
#define cl_shift 3
#define cl_mask 0X07

void change_status_2(unsigned char* ch, unsigned char new_st) {
	unsigned char mask;
	mask = st_mask;
	mask <<= st_shift;
	mask = ~mask;
	*ch &= mask;
	new_st <<= st_shift;	
	*ch |= new_st; 
}

int get_color(unsigned char ch) {
	unsigned char ch_cpy;
	ch_cpy = ch;
	ch_cpy >>= cl_shift;
	ch_cpy &= cl_mask; 
	return (int)ch_cpy; 
}

