/*
 *	NAME: cll.c
 *	AUTHOR: madachuan
 *	DISCRIPTION: Circular Linked List
 *
 *	MODIFIED:
 *	| DATE		| TIME		| DONE
 *	| Jan.25th 2016	| Mon. 08:39	| Created by madachuan.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "cll.h"

void dmcll(void)
{
	unsigned i;
	struct cll *p = NULL;
	struct cll *head = cllcreate();
	for (i = 0, p = head; i < 2 * clllen(head, head->next); i++, p = p->next)
		printf("%02X  ", p->next->key);
	printf("... cllcreate ... clllen\n");
	cllinstail(head, head->next, 0x01);
	cllinstail(head, head->next, 0x02);
	cllinstail(head, head->next, 0x03);
	for (i = 0, p = head; i < 2 * clllen(head, head->next); i++, p = p->next)
		printf("%02X  ", p->next->key);
	printf("... cllinstail ... cllins\n");
	printf("%02X ... cllmax\n", cllmax(head, head->next)->key);
	printf("%02X ... cllmin\n", cllmin(head, head->next)->key);
}

struct cll *cllcreate(void)
{
	struct cll *head = malloc(sizeof(*head));
	if (!head)
		exit(ENOMEM);
	head->key = 0;
	head->next = NULL;
	return (head);
}

struct cll *clltail(struct cll *head, struct cll *p)
{
	if (!head)
		exit(EFAULT);
	if (!p)
		return (head);
	if (!p->next)
		return (p);
	if (p->next == head->next)
		return (p);
	return (clltail(head, p->next));
}

struct cll *cllmax(struct cll *head, struct cll *p)
{
	if (!head)
		exit(EFAULT);
	if (!p)
		return (NULL);
	if (!p->next)
		return (p);
	if (p->next == head->next)
		return (p);
	struct cll *tmp = cllmax(head, p->next);
	return (p->key > tmp->key ? p : tmp);
}

struct cll *cllmin(struct cll *head, struct cll *p)
{
	if (!head)
		exit(EFAULT);
	if (!p)
		return (NULL);
	if (!p->next)
		return (p);
	if (p->next == head->next)
		return (p);
	struct cll *tmp = cllmin(head, p->next);
	return (p->key < tmp->key ? p : tmp);
}

unsigned clllen(struct cll *head, struct cll *p)
{
	if (!head)
		exit(EFAULT);
	if (!p)
		return (0);
	if (!p->next)
		return (1);
	if (p->next == head->next)
		return (1);
	return (1 + clllen(head, p->next));
}

void cllinstail(struct cll *head, struct cll *p, unsigned char key)
{
	if (!head)
		exit(EFAULT);
	struct cll *tail = clltail(head, p);
	tail->next = malloc(sizeof(*p));
	if (!tail->next)
		exit(ENOMEM);
	tail->next->key = key;
	tail->next->next = head->next;
}
