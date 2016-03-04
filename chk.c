/*
 *	NAME: chk.c
 *	AUTHOR: madachuan
 *	DISCRIPTION: Check Methods
 *
 *	MODIFIED:
 *	| DATE		| TIME		| DONE
 *	| Jan.12th 2016	| Tue. 08:42	| Created by madachuan.
 */

#include <stdio.h>

#include "chk.h"

void dmchk(void)
{
	char buf[9] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
	printf("%d  ... chkadd\n", chkadd(buf, 9));
	printf("%d  ... chkxor\n", chkxor(buf, 9));
}

char chkadd(char *p, int n)
{
	if (!n)
	        return (0);
	return (*p + chkadd(p + 1, n - 1));
}

char chkxor(char *p, int n)
{
	if (!n)
	        return (0);
	return (*p ^ chkxor(p + 1, n - 1));
}
