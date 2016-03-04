/*
 *	NAME: ll.c
 *	AUTHOR: madachuan
 *	DISCRIPTION: Linked List
 *
 *	MODIFIED:
 *	| DATE		| TIME		| DONE
 *	| Jan.12th 2016	| Tue. 00:39	| Created by madachuan.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

void dmll(void)
{
	int i;
	struct ll *p = NULL;
	struct ll *head = llcreate();
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llcreate ... lllen\n");
	llbuild(head, 5, 0xCC);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llbuild\n");
	llclean(head);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llclean\n");
	char buf[9] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
	llinit(head, 9, buf);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llinit\n");
	printf("%02X  ... llmax\n", llmax(head)->key);
	printf("%02X  ... llmin\n", llmin(head)->key);
	char bufcpy[20];
	llcpy(bufcpy, 9, head);
	for (i = 0; i < sizeof(bufcpy); i++) {
	        printf("%02X  ", (unsigned char)bufcpy[i]);
	}
	printf("... llcpy\n");
	llrev(head);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llrev ... llstrip ... lltail\n");
	llrep(head, 0x01, 0x09);
	llrep(head, 0x05, 0x09);
	llrep(head, 0x09, 0xAA);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llrep\n");
	printf("%d  ", llscan(head, 0xAA));
	printf("... llscan\n");
	lldelscan(head, 0xAA);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... lldelscan\n");
	printf("|%02X|  ", llfind(head, 0x04)->key);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llfind\n");
	lldelfind(head, 0x04);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... lldelfind\n");
	struct ll *get = llget(head, 0x03);
	printf("|%02X|  ", get->key);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llget\n");
	lladd(head, get);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... lladd\n");
	get = llget(head, 0x07);
	lladdtail(head, get);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... lladdtail\n");
	head = llbehead(head);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llbehead\n");
	llins(head, 0xEE);
	llinstail(head, 0xBB);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... llins ... llinstail\n");
	lldel(head);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... lldel\n");
	lldeltail(head);
	for (i = 0, p = head; i < lllen(head); i++) {
	        printf("%02X  ", (unsigned char)p->next->key);
	        p = p->next;
	}
	printf("... lldeltail\n");
	lldestroy(head);
}

struct ll *llcreate(void)
{
	struct ll *head = malloc(sizeof(*head));
	if (!head)
	        exit(ENOMEM);
	head->key = 0;
	head->next = NULL;
	return (head);
}

struct ll *lltail(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (p);
	return (lltail(p->next));
}

struct ll *llmax(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (NULL);
	if (!p->next->next)
	        return (p->next);
	struct ll *tmp = llmax(p->next);
	return (p->next->key > tmp->key ? p->next : tmp);
}

struct ll *llmin(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (NULL);
	if (!p->next->next)
	        return (p->next);
	struct ll *tmp = llmin(p->next);
	return (p->next->key < tmp->key ? p->next : tmp);
}

struct ll *llfind(struct ll *p, char key)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (NULL);
	if (p->next->key == key)
	        return (p->next);
	return (llfind(p->next, key));
}

struct ll *llget(struct ll *p, char key)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (NULL);
	if (p->next->key == key) {
	        struct ll *ret = p->next;
	        p->next = p->next->next;
	        return (ret);
	}
	return (llget(p->next, key));
}

struct ll *llstrip(struct ll *p, struct ll *node)
{
	if (!p || !node)
	        exit(EFAULT);
	if (!p->next)
	        return (NULL);
	if (p->next == node) {
	        p->next = p->next->next;
	        return (node);
	}
	return (llstrip(p->next, node));
}

struct ll *llbehead(struct ll *head)
{
	if (!head)
	        exit(EFAULT);
	struct ll *ret = head->next;
	ret->key = 0;
	free(head);
	return (ret);
}

int lllen(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (0);
	return (1 + lllen(p->next));
}

int llscan(struct ll *p, char key)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (0);
	if (p->next->key == key)
	        return (1 + llscan(p->next, key));
	return (llscan(p->next, key));
}

int lldelscan(struct ll *p, char key)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (0);
	if (p->next->key == key) {
	        struct ll *tmp = p->next;
	        p->next = p->next->next;
	        free(tmp);
	        if (!p->next)
	                return (1);
	        return (1 + lldelscan(p->next, key));
	}
	return (lldelscan(p->next, key));
}

int llrep(struct ll *p, char key, char new)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return (0);
	if (p->next->key == key) {
	        p->next->key = new;
	        return (1 + llrep(p->next, key, new));
	}
	return (llrep(p->next, key, new));
}

void llins(struct ll *p, char key)
{
	if (!p)
	        exit(EFAULT);
	struct ll *tmp = p->next;
	p->next = malloc(sizeof(*p));
	if (!p->next)
	        exit(ENOMEM);
	p->next->key = key;
	p->next->next = tmp;
}

void llinstail(struct ll *p, char key)
{
	if (!p)
	        exit(EFAULT);
	struct ll *tail = lltail(p);
	tail->next = malloc(sizeof(*p));
	if (!tail->next)
	        exit(ENOMEM);
	tail->next->key = key;
	tail->next->next = NULL;
}

void lladd(struct ll *p, struct ll *node)
{
	if (!p || !node)
	        exit(EFAULT);
	struct ll *tmp = p->next;
	p->next = node;
	p->next->next = tmp;
}

void lladdtail(struct ll *p, struct ll *node)
{
	if (!p || !node)
	        exit(EFAULT);
	struct ll *tail = lltail(p);
	tail->next = node;
	tail->next->next = NULL;
}

void lldel(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return;
	struct ll *tmp = p->next;
	p->next = p->next->next;
	free(tmp);
}

void lldeltail(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return;
	if (!p->next->next) {
	        struct ll *tmp = p->next;
	        p->next = NULL;
	        free(tmp);
	        return;
	}
	lldeltail(p->next);
}

void lldelfind(struct ll *p, char key)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return;
	if (p->next->key == key) {
	        struct ll *tmp = p->next;
	        p->next = p->next->next;
	        free(tmp);
	        return;
	}
	lldelfind(p->next, key);
}

void llbuild(struct ll *p, int n, char key)
{
	if (!p)
	        exit(EFAULT);
	if (!n)
	        return;
	llins(p, key);
	llbuild(p, n - 1, key);
}

void llinit(struct ll *p, int n, char *buf)
{
	if (!p)
	        exit(EFAULT);
	if (!n)
	        return;
	if (!p->next)
	        llinstail(p, *buf);
	else
	        p->next->key = *buf;
	llinit(p->next, n - 1, buf + 1);
}

void llcpy(char *buf, int n, struct ll *p)
{
	if (!buf || !p)
	        exit(EFAULT);
	if (!n)
	        return;
	if (!p->next)
	        return;
	else
	        *buf = p->next->key;
	llcpy(buf + 1, n - 1, p->next);
}

void llclean(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	if (!lllen(p))
	        return;
	lldel(p);
	llclean(p);
}

void lldestroy(struct ll *p)
{
	if (!p)
	        return;
	if (lllen(p))
	        llclean(p);
	free(p);
}

void llrev(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	if (!p->next)
	        return;
	lladd(p, llstrip(p, lltail(p)));
	llrev(p->next);
}

void llwrap(struct ll *p)
{
	if (!p)
	        exit(EFAULT);
	lltail(p)->next = p->next;
}
