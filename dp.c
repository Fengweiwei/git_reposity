/*
 ============================================================================
 Name        : dp.c
 Author      : fww
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Fibnacci_dp.h"
int main(void) {
	int i;
	for(i=1; i<15; i++)
		printf("%4d", fib_dp(i));

	return EXIT_SUCCESS;
}
