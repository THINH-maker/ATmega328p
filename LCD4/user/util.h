/*
 * util.h
 *
 *  Created on: May 4, 2020
 *      Author: KyThuat88
 */

#ifndef UTIL_H_
#define UTIL_H_


#include <avr/sfr_defs.h>

#define sbi(sfr,bit)	(sfr|=(1<<bit))
#define cbi(sfr,bit)	(sfr&=~(1<<bit))
#define tbi(sfr,bit)	(sfr^=(1<<bit))




#endif /* UTIL_H_ */
