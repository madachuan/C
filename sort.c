/*
 *	NAME: sort.c
 *	AUTHOR: madachuan
 *	DISCRIPTION: Sort Methods
 *
 *	MODIFIED:
 *	| DATE		| TIME		| DONE
 *	| Jan.12th 2016	| Tue. 13:31	| Created by madachuan.
 */

#include <stdio.h>
#include <string.h>

#include "sort.h"

void dmsort(void)
{
	unsigned i;
	unsigned char bufi[21] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	sorti(bufi, 21);
	for (i = 0; i < 21; i++)
		printf("%2d ", bufi[i]);
	printf("... sorti\n");
	unsigned char bufm[21] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	sortm(bufm, 21);
	for (i = 0; i < 21; i++)
		printf("%2d ", bufm[i]);
	printf("... sortm\n");
	unsigned char bufq[21] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	sortq(bufq, 21);
	for (i = 0; i < 21; i++)
		printf("%2d ", bufq[i]);
	printf("... sortq\n");
}

void sorti(unsigned char *buf, unsigned n)
{
	unsigned i = 1;
	while (i < n) {
		unsigned char tmp = buf[i];
		int j = i - 1;
		while (j >= 0 && buf[j] > tmp) {
			buf[j + 1] = buf[j];
			j--;
		}
		buf[j + 1] = tmp;
		i++;
	}
}

void sortm(unsigned char *buf, unsigned n)
{
	if (n < 2)
		return;
	unsigned nl = n / 2 + n % 2;
	unsigned nr = n - nl;
	sortm(buf, nl);
	sortm(buf + nl, nr);
	merge(buf, nl, nr);
}

void sortq(unsigned char *buf, unsigned n)
{
	if (n < 2)
		return;
	unsigned m = part(buf, n);
	sortq(buf, m);
	sortq(buf + m + 1, n - m - 1);
}

void merge(unsigned char *buf, unsigned nl, unsigned nr)
{
	unsigned i = 0;
	unsigned j = 0;
	unsigned k = 0;
	unsigned char bufl[nl];
	unsigned char bufr[nr];
	memcpy(bufl, buf, nl);
	memcpy(bufr, buf + nl, nr);
	while (i < nl || j < nr) {
		if (i >= nl) {
			buf[k] = bufr[j];
			j++;
		} else if (j >= nr) {
			buf[k] = bufl[i];
			i++;
		} else if (bufl[i] < bufr[j]) {
			buf[k] = bufl[i];
			i++;
		} else {
			buf[k] = bufr[j];
			j++;
		}
		k++;
	}
}

unsigned part(unsigned char *buf, unsigned n)
{
	unsigned i = 0;
	unsigned j = 0;
	while (i < n - 1) {
		if (buf[i] < buf[n - 1]) {
			exchange(&buf[i], &buf[j]);
			j++;
		}
		i++;
	}
	exchange(&buf[j], &buf[n - 1]);
	return (j);
}

void exchange(unsigned char *x, unsigned char *y)
{
	unsigned char tmp = *x;
	*x = *y;
	*y = tmp;
}
