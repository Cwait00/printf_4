#ifndef _MAIN_H_
#define _MAIN_H_

int get_flags(const char *format, int *x);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int for_precision(const char *format, int *x);

#endif
