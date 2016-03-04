/*
 *	NAME: bit.c
 *	AUTHOR: madachuan
 *	DISCRIPTION: Bit Operation inside one Byte
 *
 *	MODIFIED:
 *	| DATE		| TIME		| DONE
 *	| Jan.12th 2016	| Tue. 11:42	| Created by madachuan.
 */

#include <stdio.h>

#include "bit.h"

void dmbit(void)
{
	char c = 0x75;
	printf("%d  ... bitsum0\n", bitsum0(c));
	printf("%d  ... bitsum1\n", bitsum1(c));
	printf("%02X  ... bitrev\n", (unsigned char)bitrev(c));
}

int bitsum0(char byte)
{
	int ret;
	int i;
	for (i = 0, ret = 0; i < 8; i++)
	        if (!(byte & (0x01 << i)))
	                ret++;
	return (ret);
}

int bitsum1(char byte)
{
	int ret;
	int i;
	for (i = 0, ret = 0; i < 8; i++)
	        if (byte & (0x01 << i))
	                ret++;
	return (ret);
}

char bitrev(char byte)
{
	char ret;
	int i;
	for (i = 0, ret = 0; i < 8; i++) {
	        if (7 - i * 2 > 0)
	                ret |= (byte & (0x01 << i)) << (7 - i * 2);
	        else
	                ret |= (byte & (0x01 << i)) >> (i * 2 - 7);
	}
	return (ret);
}
