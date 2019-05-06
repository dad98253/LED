/*
 * LED.c
 *
 *  Created on: Dec 5, 2016
 *      Author: dad
 */

// NOTE: to execute the LED program from a non-privileged account, set owner to root:root and chmod u+s
// otherwise, you will get:
// iolib_init: CM_PER mmap failure! ,error :Bad file descriptor
// Segmentation fault

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BBBiolib.h"

int
main(int argc, char *argv[])
{
	 if ( argc != 2 ) {
		printf("usage error:\n...program requires an argument of either \"boot\" or \"rebootnet\" or \"flash\"\n");
		return (0);
	 }
//         printf("\nprog name= %s", argv[0]);
 	 int i;
	 for (i=1; i< argc; i++) {
	     printf("\narg= %s", argv[i]);
	 }
	 printf("\n");
	 iolib_init();

	if ( strcmp(argv[1],"flash") == 0 ) {
		BBBIO_GPIO_set_dir(BBBIO_GPIO1 , 0 , BBBIO_GPIO_PIN_22 | BBBIO_GPIO_PIN_23 | BBBIO_GPIO_PIN_24 );    // pin 22 23 24  as output
		for (i=0; i< 5; i++) {
			printf("LEDs on\n");
			BBBIO_GPIO_high(BBBIO_GPIO1 , BBBIO_GPIO_PIN_22 | BBBIO_GPIO_PIN_23 | BBBIO_GPIO_PIN_24 );	// PIN 22 23 24 pin high simultaneously
			iolib_delay_ms(999);
			printf("LEDs off\n");
			BBBIO_GPIO_low(BBBIO_GPIO1 , BBBIO_GPIO_PIN_22 | BBBIO_GPIO_PIN_23 | BBBIO_GPIO_PIN_24 );	// PIN 22 23 24 pin high simultaneously
			iolib_delay_ms(999);
		}
	}

	if ( strcmp(argv[1],"boot") == 0 ) {

		int del = 100;
//		iolib_init();
//		BBBIO_sys_GPIO_CLK_status();  // display gpio clock status
//		BBBIO_sys_Expansion_Header_status(8);  // Show Beaglebone Black Expansion Header Information
//		BBBIO_sys_Expansion_Header_status(9);
//		printf("pin status plug 8 pin 11 : %i\n", BBBIO_sys_pinmux_check(8, 11, 1 ) );
		printf("setting plug 8 pin 11 to output: ");
		iolib_setdir(8,11, BBBIO_DIR_OUT);
//		iolib_setdir(8,12, BBBIO_DIR_OUT);
		printf("booting firewall11\n");
	        pin_high(8,11);
	        iolib_delay_ms(del);
	        pin_low(8,11);

        }

        if ( strcmp(argv[1],"rebootnet") == 0 ) {

                int del = 998;
 //               iolib_init();
                printf("setting plug 8 pin 12 to output: ");
//              iolib_setdir(8,11, BBBIO_DIR_OUT);
                iolib_setdir(8,12, BBBIO_DIR_OUT);
                printf("rebooting network\n");
                pin_high(8,12);
		printf("power off... waiting 11 seconds...\n");
		for (i=0; i<11; i++) {
               		 iolib_delay_ms(del);
		}
                pin_low(8,12);
		printf("power on... network should reboot now.\n");

        }

	iolib_free();
	printf("done\n");
	return(0);
}

