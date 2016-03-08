struct cll {
	unsigned char key;
	struct cll *next;
};

struct cll *cllcreate(void);
struct cll *clltail(struct cll *head, struct cll *p);
struct cll *cllmax(struct cll *head, struct cll *p);
struct cll *cllmin(struct cll *head, struct cll *p);
unsigned clllen(struct cll *head, struct cll *p);
void cllinstail(struct cll *head, struct cll *p, unsigned char key);
