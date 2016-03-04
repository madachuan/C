struct cll {
	char key;
	struct cll *next;
};

struct cll *cllcreate(void);
struct cll *clltail(struct cll *head, struct cll *p);
struct cll *cllmax(struct cll *head, struct cll *p);
struct cll *cllmin(struct cll *head, struct cll *p);
int clllen(struct cll *head, struct cll *p);
void cllinstail(struct cll *head, struct cll *p, char key);
