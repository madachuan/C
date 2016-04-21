typedef struct {
	struct {
		struct {
			unsigned char :3;
			unsigned char find:1;
			unsigned char :1;
			unsigned char ir:1;
			unsigned char track:1;
			unsigned char :1;
			unsigned char err;
			short azi;
			short pit;
			unsigned short laser;
			unsigned short stamp;
		} __attribute__((packed)) ir;
		struct {
			unsigned char :4;
			unsigned char mov:1;
			unsigned char :3;
			unsigned char err;
			short azi;
			short pit;
			unsigned short res;
			unsigned short stamp;
		} __attribute__((packed)) sv;
		struct {
			unsigned char num;
			unsigned char :5;
			unsigned char ajc:1;
			unsigned char tail:1;
			unsigned char mod:1;
			unsigned char res;
			unsigned char exist:1;
			unsigned char cut:1;
			unsigned char pin0:1;
			unsigned char pin1:1;
			unsigned char ready:1;
			unsigned char safe:1;
			unsigned char regret:1;
			unsigned char :1;
			unsigned char :4;
			unsigned char battery:1;
			unsigned char feedback:1;
			unsigned char :1;
			unsigned char engine:1;
			struct {
				unsigned char core:1;
				unsigned char p20:1;
				unsigned char n20:1;
				unsigned char pin:1;
				unsigned char top:1;
				unsigned char timeout:1;
				unsigned char :1;
				unsigned char dumb:1;
			} err;
			unsigned char res1;
			unsigned char gas;
			unsigned short stamp;
		} m[8];
		struct {
			unsigned char sv1:1;
			unsigned char sv2:1;
			unsigned char get:1;
			unsigned char guide:1;
			unsigned char pos:1;
			unsigned char num:3;
			unsigned char mx;
			unsigned char launch:1;
			unsigned char safe:1;
			unsigned char cage:1;
			unsigned char chk:1;
			unsigned char rst:1;
			unsigned char ajc:1;
			unsigned char tail:1;
			unsigned char mod:1;
			signed char rkra;
			signed char rkrp;
			unsigned char laser5hz:1;
			unsigned char laser1hz:1;
			unsigned char background:1;
			unsigned char shutter:1;
			unsigned char ir:1;
			unsigned char whiteblack:1;
			unsigned char backmid:1;
			unsigned char channel:1;
			unsigned char :1;
			unsigned char display:1;
			unsigned char ccdzoomsub:1;
			unsigned char ccdzoomplus:1;
			unsigned char ccdfocussub:1;
			unsigned char ccdfocusplus:1;
			unsigned char irfocussub:1;
			unsigned char irfocusplus:1;
			unsigned char res;
			unsigned short stamp1;
			signed char stp1l;
			signed char stp1r;
			signed char fbd1l;
			signed char fbd1r;
			signed char fbd2l;
			signed char fbd2r;
			short heading;
			unsigned short stamp2;
			unsigned long lat:23;
			unsigned long ns:1;
			unsigned long lon:23;
			unsigned long ew:1;
			short alt;
			unsigned short stamp3;
		} __attribute__((packed)) dp;
		struct {
			double week;
			double time;
			double heading;
			double pit;
			double track;
			double lat;
			double lon;
			double alt;
			double ve;
			double vn;
			double vu;
			double baseline;
			double nsv1;
			double nsv2;
		} gps;
		struct {
			unsigned char flag;
			unsigned char num;
			unsigned char tgtnum;
			unsigned long lat:23;
			unsigned long ns:1;
			unsigned long lon:23;
			unsigned long ew:1;
			short hgt;
			signed char vx;
			signed char vy;
			signed char vz;
			unsigned short stamp;
			unsigned char xor;
		} __attribute__((packed)) acs;
	} r;
	struct {
		struct {
			unsigned char :5;
			unsigned char ir:1;
			unsigned char get:1;
			unsigned char :1;
			unsigned char res;
			short azi;
			short pit;
			unsigned short res1;
		} __attribute__((packed)) ir;
		struct {
			unsigned char :4;
			unsigned char sv:1;
			unsigned char :3;
			unsigned char res;
			short azi;
			short pit;
			unsigned short res1;
		} __attribute__((packed)) sv;
		struct {
			unsigned char umask;
			unsigned char :5;
			unsigned char ajc:1;
			unsigned char tail:1;
			unsigned char mod:1;
			unsigned long cmd;
			unsigned char res;
			unsigned char ctr;
		} __attribute__((packed)) m;
		unsigned char pw[8];
		struct {
			unsigned char spd:6;
			unsigned char direct:1;
			unsigned char attack:1;
			unsigned char remain;
			short hgt;
			unsigned short dist;
			short ppi;
			signed char stp1l;
			signed char stp1r;
			signed char fbd1l;
			signed char fbd1r;
			signed char fbd2l;
			signed char fbd2r;
			short heading;
			unsigned long lat:23;
			unsigned long ns:1;
			unsigned long lon:23;
			unsigned long ew:1;
			short alt;
		} __attribute__((packed)) dp;
		struct {
			unsigned char head;
			unsigned char len;
			unsigned char ctr;
			unsigned char errm:1;
			unsigned char errsv:1;
			unsigned char errir:1;
			unsigned char attack:1;
			unsigned char num:4;
			unsigned long lat:23;
			unsigned long ns:1;
			unsigned long lon:23;
			unsigned long ew:1;
			short alt;
			unsigned short mls;
			signed char stp1l;
			signed char stp1r;
			signed char fbd1l;
			signed char fbd1r;
			signed char fbd2l;
			signed char fbd2r;
			short ppi;
			unsigned char end;
			unsigned char xor;
		} __attribute__((packed)) acs;
	} t;
} Fcsd;

typedef struct {
	struct {
		struct {
			unsigned char stp:1;
			unsigned char fbd:1;
			unsigned char ir:1;
			unsigned char get:1;
			unsigned char laser:1;
			unsigned char freq:1;
			unsigned char :2;
			short azi;
			short pit;
		} __attribute__((packed)) ir;
		struct {
			unsigned char stp:1;
			unsigned char fbd:1;
			unsigned char sv1:1;
			unsigned char sv2:1;
			unsigned char ahead:1;
			unsigned char :3;
			short azi;
			short pit;
		} __attribute__((packed)) sv;
		struct {
			unsigned char direct:1;
			unsigned char attack:1;
			unsigned char :6;
			unsigned char remain;
			unsigned short shortcut;
			unsigned short dist;
			short int hgt;
			signed char vx;
			signed char vy;
			signed char vz;
		} __attribute__((packed)) guide;
	} r;
	struct {
		struct {
			unsigned short stamp;
			unsigned char err;
			unsigned char find:1;
			unsigned char track:1;
			unsigned char freq:1;
			unsigned char :5;
			short azi;
			short pit;
			unsigned short laser;
		} __attribute__((packed)) ir;
		struct {
			unsigned short stamp;
			unsigned char err;
			unsigned char stop:1;
			unsigned char mov:1;
			unsigned char :6;
			short azi;
			short pit;
		} __attribute__((packed)) sv;
		struct {
			unsigned char err;
			unsigned char ready;
		} m;
		struct {
			unsigned char pos:1;
			unsigned char guide:1;
			unsigned char ir:1;
			unsigned char get:1;
			unsigned char laser:1;
			unsigned char freq:1;
			unsigned char sv1:1;
			unsigned char sv2:1;
			signed char rkra;
			signed char rkrp;
			unsigned long lat:23;
			unsigned long ns:1;
			unsigned long lon:23;
			unsigned long ew:1;
			short alt;
			short heading;
			signed char stp1l;
			signed char stp1r;
			signed char fbd1l;
			signed char fbd1r;
			signed char fbd2l;
			signed char fbd2r;
		} __attribute__((packed)) dp;
		struct {
			unsigned short stamp;
			unsigned long lat:23;
			unsigned long ns:1;
			unsigned long lon:23;
			unsigned long ew:1;
			short alt;
			short heading;
		} __attribute__((packed)) gps;
		struct {
			unsigned short stamp;
			unsigned long lat:23;
			unsigned long ns:1;
			unsigned long lon:23;
			unsigned long ew:1;
			short hgt;
			signed char vx;
			signed char vy;
			signed char vz;
		} __attribute__((packed)) acs;
	} t;
} Etsd;

typedef struct {
	struct {
		unsigned char umask;
		struct {
			unsigned char mod:1;
			unsigned char tail:1;
			unsigned char ajc:1;
			unsigned char rst:1;
			unsigned char chk:1;
			unsigned char up:1;
			unsigned char cage:1;
			unsigned char safe:1;
			unsigned char launch:1;
			unsigned char :7;
		} m[8];
	} r;
	struct {
		struct {
			unsigned char svstp:1;
			unsigned char svfbd:1;
			unsigned char ahead:1;
			unsigned char :5;
		} ets;
		struct {
			struct {
				unsigned char core:1;
				unsigned char p20:1;
				unsigned char n20:1;
				unsigned char pin:1;
				unsigned char top:1;
				unsigned char timeout:1;
				unsigned char :1;
				unsigned char dumb:1;
			} err;
			unsigned char mod:1;
			unsigned char tail:1;
			unsigned char ajc:1;
			unsigned char exist:1;
			unsigned char cut:1;
			unsigned char pin0:1;
			unsigned char pin1:1;
			unsigned char ready:1;
			unsigned char safe:1;
			unsigned char regret:1;
			unsigned char battery:1;
			unsigned char feedback:1;
			unsigned char engine:1;
			unsigned char :3;
			unsigned char gas;
		} m[8];
		struct {
			unsigned char mx;
			unsigned char mod:1;
			unsigned char tail:1;
			unsigned char ajc:1;
			unsigned char chk:1;
			unsigned char cage:1;
			unsigned char safe:1;
			unsigned char launch:1;
			unsigned char rst:1;
		} dp;
	} t;
} Mlsd;
