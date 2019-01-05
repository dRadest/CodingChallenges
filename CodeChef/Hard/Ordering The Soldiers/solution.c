/*
* https://www.codechef.com/problems/ORDERS
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define LEVELS 18

static uint32_t cnts32[4];
static uint16_t cnts16[1<<(LEVELS-8)];
static uint8_t cnts8[1<<LEVELS];

uint32_t walk32(uint32_t* pos, uint32_t j, int k) 
{
  	uint32_t np = *pos + cnts32[j];
  	if ((np >> k) & 1) 
  	{
    	*pos = np;
    	j = (j<<1) + 1;
  	} 
  	else 
  	{
    	++cnts32[j];
    	j <<= 1;
  	}
  	return j;
} 

uint32_t walk16(uint32_t* pos, uint32_t j, int k) 
{
  	uint32_t np = *pos + cnts16[j];
  	if ((np >> k) & 1) 
  	{
    	*pos = np;
    	j = (j<<1) + 1;
  	} 
  	else 
  	{
    	++cnts16[j];
    	j <<= 1;
  	}
  	return j;
} 

uint32_t walk8(uint32_t* pos, uint32_t j, int k) 
{
  	uint32_t np = *pos + cnts8[j];
  	if ((np >> k) & 1) 
  	{
    	*pos = np;
    	j = (j<<1) + 1;
  	} 
  	else 
  	{
    	++cnts8[j];
    	j <<= 1;
  	}
  	return j;
}  

int add(uint32_t pos) 
{
  	uint32_t j=1;
  	j = walk32(&pos, j, 17);
  	j = walk32(&pos, j, 16);
  	j = walk16(&pos, j, 15);
  	j = walk16(&pos, j, 14);
  	j = walk16(&pos, j, 13);
  	j = walk16(&pos, j, 12);
  	j = walk16(&pos, j, 11);
  	j = walk16(&pos, j, 10);
  	j = walk16(&pos, j, 9);
  	j = walk16(&pos, j, 8);
  	j = walk8(&pos, j, 7);
  	j = walk8(&pos, j, 6);
  	j = walk8(&pos, j, 5);
  	j = walk8(&pos, j, 4);
  	j = walk8(&pos, j, 3);
  	j = walk8(&pos, j, 2);
  	j = walk8(&pos, j, 1);
  	j = walk8(&pos, j, 0);
  	return pos;
}
char *output_buffer;
int* order;
uint32_t tbl[1000];
uint32_t tblp[2000];
uint8_t tbl_cnt[2000];
 
void init_tbl()
{
  	char buf[8];
  	int i;
  	for (i=0;i<1000;i++) 
  	{
    	sprintf(buf, "%03d", i);
    	memcpy(tbl+i, buf, 4);
  	}
  	for (i=0;i<2000;i++) 
  	{
    	sprintf(buf, "%d", i);
    	memcpy(tblp+i, buf, 4);
  	}
  	tbl_cnt[0] = 0;
  	for (i=1;i<10;i++)
    	tbl_cnt[i] = 1;
  	for (i=10;i<100;i++) 
    	tbl_cnt[i] = 2;
  	for (i=100;i<1000;i++)
    	tbl_cnt[i] = 3;
  	for (i=1000;i<2000;i++)
    	tbl_cnt[i] = 4;
}

char* print_int(char* p, int val)
{
  	//char* q = p;
  	if (val >= 1000) 
  	{
    	char* q = p + tbl_cnt[val/1000];
    	*(uint32_t *)p = tblp[val/1000];
    	*(uint32_t *)q = tbl[val % 1000];
    	p = q + 3;
  	} 
  	else 
  	{
    	*(uint32_t *)p = tblp[val];
    	p += tbl_cnt[val];
  	}
  	return p;
}

int read_int()
{
  	static char buf[64*1024];
  	static int start, end;
 
  	if (end-start < 10) 
  	{
    	memmove(buf, buf+start, end-start);
    	end = end-start;
    	start = 0;
    	end += fread(buf+end, 1, sizeof(buf)-end, stdin);
  	}
  	char* p = buf+start;
  	while (*p < '0' || *p > '9') 
  		++p;
  	int value = *p++ - '0';
  	while (1) 
  	{
    	char c = *p++;
    	if (c < '0' || c > '9') 
    		break; 
    	value = value*10 + (c - '0');
  	}
  	start = p-buf;
  	return value;
}

void find_order(int n)
{
  	int i;
  	memset(cnts32,0,sizeof(cnts32));
  	memset(cnts16,0,sizeof(cnts16));
  	for (i=0;i<8;i++)
    	memset(cnts8 + (1<<(17-i)),0,(n>>(i+1))+1);
 
	for (i=0;i<n;i++) 
		order[i] = read_int(); 
  	for (i=n-1;i>=0;--i)
    	order[i] = add(i-order[i])+1;
 
  	char* p = output_buffer;
  	p = print_int(p, order[0]);
  	for (i=1;i<n;i++) 
  	{
    	*p++ = ' ';
    	p = print_int(p, order[i]);
  	}
  	*p++ = '\n';
  	fwrite(output_buffer, p-output_buffer, 1, stdout);
}
 
int main()
{
  	int i, t, n;
 
  	init_tbl();
  	output_buffer = malloc(7*200000+1);
  	order = malloc(200000*sizeof(int));
  	t = read_int();
  	for (i=0;i<t;i++) 
  	{
    	n = read_int();
    	find_order(n);
  	}
  	return 0;
} 