/** Team Tolli!!!
 *  Tom Ricciuti & Linus Brinkmeier
 */

#include "guessing.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *	Guesses a number:
 *  Eine 5 Stellige Zahl wird erraten in dem die Intervalle von möglichen Zahlen immer halbiert wird.
 *  Durchschnittlich 15 Rateversuche pro Zahl
 *
 */
unsigned int guess_the_number(void)
{
	unsigned int lower_limit = 0;
	unsigned int upper_limit = 99999;
	unsigned int guess = 50000;

	//default wert um undefiniertes verhalten vorzubeugen
	int status = 2;

	while(1){
		status = evaluate(guess);
		if(status == 0){
			return guess;
		}else if(status == 1){
			lower_limit = guess;
			// 1 ist addiert um eine endlosschleife bei einer differenz von 1 vorzubeugen
			guess = guess + 1 + ((upper_limit - guess)/2);
		}else if(status == -1){
			upper_limit = guess;
			guess = guess - (guess - lower_limit)/ 2;
		}else{
			printf("Error occured in evaluate return\n");
			exit(1);
		}
	}
	return 1; // Return the correct number
}
