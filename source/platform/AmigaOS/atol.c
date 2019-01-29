/* 
 * atol.c --
 *
 *	Source code for the "atol" library procedure.
 *
 * Copyright 1988 Regents of the University of California
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for any purpose and without
 * fee is hereby granted, provided that the above copyright
 * notice appear in all copies.  The University of California
 * makes no representations about the suitability of this
 * software for any purpose.  It is provided "as is" without
 * express or implied warranty.
 */

#include <stdlib.h>
#include <ctype.h>

/*
 *----------------------------------------------------------------------
 *
 * atol --
 *
 *	Convert an ASCII str into a longeger.
 *
 * Results:
 *	The return value is the integer equivalent of str.  If there
 *	are no decimal digits in str, then 0 is returned.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

long long atoll( const char *str ) {
    register long result = 0;
    register unsigned int digit;
    int sign;

    /*
     * Skip any leading blanks.
     */

    while (isspace(*str)) {
	str += 1;
    }

    /*
     * Check for a sign.
     */

    if (*str == '-') {
	sign = 1;
	str += 1;
    } else {
	sign = 0;
	if (*str == '+') {
	    str += 1;
	}
    }

    for ( ; ; str += 1) {
	digit = *str - '0';
	if (digit > 9) {
	    break;
	}
	result = (10*result) + digit;
    }

    if (sign) {
	return -result;
    }
    return result;
}
