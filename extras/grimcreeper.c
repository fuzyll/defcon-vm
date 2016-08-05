/*
 * Hi Kenshoto. <3
 * 
 * -drraid, 
 *  and the rest of SophSec
 *
 *  sophsec: sketchy shit, competitive prices.
 *
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "common.h"

#define SERVICE_NAME "GrimCreeper"
#define SERVICE_PORT 9001
#define VERSION      "0.01"
#define BAD_FUNCTION "BAD FUNCTION!\n"
#define SIZE_2BIG    "SIZE TOO BIG!\n"
#define NOT_FOUND    "NO MATCH FOUND"
#define FUNC_FACT    0x1
#define FUNC_TIME    0x2
#define FUNC_LIES    0x3 
#define FUNC_ECHO    0x4 
#define FUNC_SLEN    0x5
#define TYPE_RANDOM  0x6
#define TYPE_STRING  0x7

const char *lies[]=
{
	"You'll be able to exploit the strcpy() to win ;]\n",
	"Theres no such thing as implementation errors in compilers\n",
	"Visigoth is new at this, plz give him time 2 catch up. k thx\n", 
	"Chix dig remote service exploits\n",
	"None of these statements are just slightly incorrect\n", 
	"Ninjas *never* flip out and kill people\n", 
	"You're success is a shr thing\n"
};

const char *facts[]=
{
	"Kenshoto ownz u!!\n",
	"GCC can be a bit shifty\n",
	"drraid is a skript kiddie\n",
	"Toby is still a sexy beast\n", 
	"What does the scanner say about TCP port? Its over nine thousand!\n",
	"Rick Astley is never gonna give you up, never gonna let you down\n",
	"Ninjas are waaay cooler than pirates\n"
};

char user_data[]="\x25\x73";
struct timeval tval;

int handleConnection(int sockfd);
void parse_options(int sockfd, char *buf, ssize_t len);

void func_fact(int sockfd, char *s, ssize_t len);
void func_time(int sockfd, char *s, ssize_t len);
void func_lies(int sockfd, char *s, ssize_t len);
void func_echo(int sockfd, char *s, ssize_t len);
void func_slen(int sockfd, char *s, ssize_t len);

void find_lies_string(int sockfd, char *string);
void find_fact_string(int sockfd, char *string);
void get_echo_string(char *d, char *s, char *fmt);

void die_foo(size_t line);
void stringNcopy(char *dst, char *src, size_t len);

/* lets get dangerous */	
int main(int argc, char *argv[])
{
	int sock;

	sock = init(SERVICE_PORT);
	if (sock == -1)
	{
		die_foo(__LINE__);
	}

	if (drop_privs_user("grimcreeper") != 0)
	{
		die_foo(__LINE__);
	}

	daemon(0,0);
	
	loop(sock, handleConnection);
	return 0;
}

int handleConnection(int sockfd)
{
	ssize_t readtotal = 0;
	ssize_t maxread;
	char inbuf[4096];

	printf("inbuf %p\n", inbuf);

	/* clean memory */
	memset(inbuf, 0, sizeof(inbuf));

	/* Tell them who we iz */
	sendMsgf(sockfd, "%s v%s\n", SERVICE_NAME, VERSION);

	/* read ssize_t value.. */
	if (-1 == readAll(sockfd, (char *)&maxread, sizeof(maxread)))
	{
		return -1;
	}

	/* check the size.. */
	if (maxread > sizeof(inbuf)-1)
	{
		/* obvious trap has obvious */
		sendMsg(sockfd, SIZE_2BIG, 1);
		return -1;
	}

	/* get data.. */
	if (-1 == (readtotal = readAll(sockfd, inbuf, maxread)))
	{
		return -1;
	}

	/* parse data */
	parse_options(sockfd, inbuf, readtotal);

	return 0;
}

/*
 * Parse data sent by the user
 * call appropriate function handler
 * or alert the user that they've requested
 * a bad function.
 */
void parse_options(int sockfd, char *buf, ssize_t len)
{

	if (len < 1)
	{
		return;	
	}

	switch (buf[0])
	{
		case FUNC_FACT:
			func_fact(sockfd, &buf[1], (len-1));
			return;
		case FUNC_TIME:
			func_time(sockfd, &buf[1], (len-1));
			return;
		case FUNC_LIES:
			func_lies(sockfd, &buf[1], (len-1));
			return;
		case FUNC_ECHO:
			func_echo(sockfd, &buf[1], (len-1));
			return;
		case FUNC_SLEN:
			func_slen(sockfd, &buf[1], (len-1));
			return;
		default:
			sendMsg(sockfd, BAD_FUNCTION, 1);
			close(sockfd);
			return;
	}

	return;
}


/* 
 * some user sizes are specified as unsigned, however
 * we also use signed size_t and other signed values
 * throughout the code.
 *
 * The following functions are to check that the unsigned
 * values aren't too big for their signed counterparts.
*/
int check_signed2big4int(unsigned int x)
{
	unsigned int check;
	check = ~0;
	check = ((check << 1) >> 1);

	if (x > check)
	{
		return 1;
	}

	return 0;
}

int check_signed2big4short(unsigned short x)
{
	unsigned short check;
	check = ~0;
	check = ((check << 1) >> 1);

	if (x > check)
	{
		return 1;
	}

	return 0;
}


/* Die Foo. */
void die_foo(size_t line)
{
	exit(line);		
}


/* 
 * Write the time_t back to the user.
 * Nice and handy.
*/
void func_time(int sockfd, char *s, ssize_t len)
{
	sendMsgf(sockfd, "TIME: %i\n", time(0));
	return;
}

/* echo the user string. be careful with those format strings. */
void func_echo(int sockfd, char *s, ssize_t len)
{
	char buf[4096];
	memset(buf, 0, sizeof(buf));
	get_echo_string(buf, s, user_data); 
	sendMsg(sockfd, buf, 1);	
	return;
}

/* 
 * Whew. Had to becareful here.
 * Those format specifiers can be trouble.
*/
void get_echo_string(char *d, char *s, char *fmt)
{
	/*
	** shameless.
	*/
	char buf[4096];
	char format[16];
	char OTc3Y2EzMDA5MGM2ZmZkMjA2YWNkZmQ1NzZjOWMwYTI[]="ECHO: %s\n";
	char *p = OTc3Y2EzMDA5MGM2ZmZkMjA2YWNkZmQ1NzZjOWMwYTI;
	sprintf(format, fmt, p);
	snprintf(buf, sizeof(buf)-1, format, s);
	strcpy(d, buf);
}


/*
 * Tell the user a lie.
 * either chosen at random,
 * or one which matches the string they provide
*/
void func_lies(int sockfd, char *s, ssize_t len)
{	
	char buf[1024];
	int rlie;
	int buflen = sizeof(buf)-1;
	int copylen = 0;

	struct 
	{
		unsigned char type;
		unsigned int len;
	} lies_header;

	if (len < sizeof(lies_header))
	{
		sendMsg(sockfd, BAD_FUNCTION, 1);
		return;
	}

	memcpy((char *)&lies_header, s, sizeof(lies_header));

	if (check_signed2big4int(lies_header.len))
	{
		sendMsg(sockfd, SIZE_2BIG, 1);
		return;
	}

	copylen = lies_header.len;

	if (buflen < copylen)
	{
		copylen = buflen;
	}

	memset(buf, 0, sizeof(buf));

	switch(lies_header.type)
	{
		case TYPE_RANDOM:
			/* 
			 * DEBIAN-GRADE ENTROPY LOLOL 
			*/ 
			gettimeofday(&tval, 0);
			srand(tval.tv_usec);
			rlie = rand();
			rlie %= (sizeof(lies)/sizeof(lies[0]));
			sendMsgf(sockfd, "RANDOM LIE: %s", lies[rlie]);
			return;

		case TYPE_STRING:
			stringNcopy(buf, &s[sizeof(lies_header)], copylen);
			find_lies_string(sockfd, buf);	
			return;

		default:
			sendMsg(sockfd, BAD_FUNCTION, 1);
			return;
	}

	return;
}

/* 
 * Does the user supplied phrase
 * match anything in the lie table?
 *
 * it would be ironic if we lied to them about
 * whether or not it existed in the lies table..
 * but.. that might be too confuing for them.
 *
*/
void find_lies_string(int sockfd, char *string)
{
	size_t loop;
	int found = 0;

	if (strlen(string) < 1)
	{
		sendMsgf(sockfd, "%s: %s\n", NOT_FOUND, string);
	}

	for (loop = 0; loop < (sizeof(lies)/sizeof(lies[0])); ++loop)
	{
		if (strstr(lies[loop], string))
		{
			found = 1;
			sendMsg(sockfd, lies[loop], 1);
		}
	}
	if (!found)
	{
		sendMsgf(sockfd, "%s: %s", NOT_FOUND, string);
	}

	return;
}

/* 
 * Tell the user a fact.
 * Either at random, or one containing a string
 * which they've provided.
*/
void func_fact(int sockfd, char *s, ssize_t len)
{	
	char buf[1024];
	short rfact;
	short buflen = sizeof(buf)-1;
	short copylen = 0;

	struct 
	{
		unsigned char type;
		unsigned char reserved;
		unsigned short len;
	} fact_header;

	if (len < sizeof(fact_header))
	{
		sendMsg(sockfd, BAD_FUNCTION, 1);
		return;
	}

	memcpy((char *)&fact_header, s, sizeof(fact_header));

	if (check_signed2big4short(fact_header.len))
	{
		sendMsg(sockfd, SIZE_2BIG, 1);
		return;
	}

	copylen = fact_header.len;

	if (buflen < copylen)
	{
		copylen = buflen;
	}

	memset(buf, 0, sizeof(buf));

	switch(fact_header.type)
	{
		case TYPE_RANDOM:
			/* 
			 * DEBIAN-GRADE ENTROPY LOLOL 
			*/
			gettimeofday(&tval, 0);
			srand(tval.tv_usec);
			rfact = rand();
			rfact %= (sizeof(facts)/sizeof(facts[0]));
			sendMsgf(sockfd, "RANDOM FACT: %s", facts[rfact]);
			return;

		case TYPE_STRING:
			stringNcopy(buf, &s[sizeof(fact_header)], copylen);
			find_fact_string(sockfd, buf);	
			return;

		default:
			sendMsg(sockfd, BAD_FUNCTION, 1);
			return;
			
	}

	return;
}

/*
 * Does the string the user provided
 * match any fact in our table?
*/
void find_fact_string(int sockfd, char *string)
{
	size_t loop;
	int found = 0;

	if (strlen(string) < 1)
	{
		sendMsgf(sockfd, "%s: %s\n", NOT_FOUND, string);
	}

	for (loop = 0; loop < (sizeof(facts)/sizeof(facts[0])); ++loop)
	{
		if (strstr(facts[loop], string))
		{
			found = 1;
			sendMsg(sockfd, facts[loop], 1);
		}
	}

	if (!found)
	{
		sendMsgf(sockfd, "%s: %s\n", NOT_FOUND, string);
	}

	return;
}

/* find the length of the user string.
 * optimized version (safe) */
void func_slen(int sockfd, char *s, ssize_t len)
{
        char *p1=NULL,*p2=NULL,*p3=NULL;
        size_t x1=len,x2=sizeof(char),x3=sizeof(short);
        char buffer[1024];

        x3=len;
        x1=sizeof(buffer);
        x2=x1-1;
        memset(buffer, 0, x1);
        p2=s;
        p3=buffer;
        goto truth;

lies:
        strcpy(p3, p2);
        x3=strlen(p3);
        sendMsgf(sockfd, "STRLEN: %i\n", x3);
        return;

truth:
        x3=x1-x2;
        p1=p2!=p3?p2:p1;
        p3=p1!=p3?p3:p1;
        p1[(x2!=x1?x2:x1)]=(x3-(x1-x2));
        goto lies;
}

/* 
 * I noticed we hadn't re-invented/implemented enough wheels.
 * This wheel has nifty edges to help it climb curbs.
 *
 * tomorrow: re-writing printf().
 *
*/
void stringNcopy(char *dst, char *src, size_t len)
{
	size_t loop;
	char *s1, *s2;

	s1 = dst;	
	s2 = src;
	loop = len;

	while (loop)
	{
		*s1 = *s2++;
		if (!*s1++)
			break;
		--loop;
	}
	return;
}

