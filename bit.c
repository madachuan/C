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
	unsigned char c = 0x75;
	printf("%d  ... bitsum0\n", bitsum0(c));
	printf("%d  ... bitsum1\n", bitsum1(c));
	printf("%02X  ... bitrev\n", bitrev(c));
}

unsigned bitsum0(unsigned char byte)
{
	unsigned ret;
	unsigned i;
	for (i = 0, ret = 0; i < 8; i++)
		if (!(byte & 0x01 << i))
			ret++;
	return ret;
}

unsigned bitsum1(unsigned char byte)
{
	unsigned ret;
	unsigned i;
	for (i = 0, ret = 0; i < 8; i++)
		if (byte & 0x01 << i)
			ret++;
	return ret;
}

unsigned char bitrev(unsigned char byte)
{
	unsigned char ret;
	unsigned i;
	for (i = 0, ret = 0; i < 8; i++)
		if (7 - i * 2 > 0)
			ret |= (byte & 0x01 << i) << (7 - i * 2);
		else
			ret |= (byte & 0x01 << i) >> (i * 2 - 7);
	return ret;
}
