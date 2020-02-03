#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPAD 8

int main (int argc, char **argv)
{
	/* pattern generation */
	int x,y,p,pt,lp;
	char *chx = "s$";
	char *is = "dfk3^9";
	char pat[20][20] = {};

	lp = 0;
	for(x = 0; x < 5; x++)
	{
		for(y = 0; y < 5; y++)
		{
			if(y == x) continue;
			strcpy(pat[lp], is);
			pt = 6;
			for(p = 0; p < 5; p++)
			{
				if(p != x && p != y)
				{
					pat[lp][pt++] = '%';
					pat[lp][pt++] = 'c';
				}
				else
				{
					if(p == x) pat[lp][pt++] = *(chx + 0);
					if(p == y) pat[lp][pt++] = *(chx + 1);
				}
			}
			pat[lp][pt]= '\n';
			lp++;
		}
	}

	/* password and shell script files generation */
	int a,b,c,d,e,f,g,z,i;
//	char *ch = "`1234567890qwertyuiopasdfghjklzxcvbnm;,.><MNBVCXZASDFGHJKL:POIUYTREWQ~!@#$%^&*()_+-=";
	char *ch = "123456789~!@#$asdfASDF";
	int nchar = strlen(ch);
	char *shellscript = "batch.sh";
	char *passcript = "pass";
	int ppr = 25;

	FILE *batch = fopen(shellscript, "wb");
	for(i = 0; i < 1; i++)
	{
		char passfile[10] = "";
		sprintf(passfile, "%s%d", passcript, i + 1);
		FILE *out = fopen(passfile, "wb");

		long count = 0;
		for(a = 0; a < nchar; a++)
		{
			for(b = 0; b < nchar; b++)
			{
				if(ch[b] == ch[a]) continue;
				for(c = 0; c < nchar; c++)
				{
					if(ch[c] == ch[b]) continue;
					if(ch[c] == ch[a]) continue;
				//	fprintf(out, pat[i], ch[a], ch[b], ch[c]);
					fprintf(out, "dfk3^9$%c%c%c", ch[a], ch[b], ch[c]);
					count++;
					if(count % ppr == 0) fprintf(out, "\n");
				}
			}
		}
	
		/* padding */
		int pad = 0;
		if(count < 10) pad = 7;
		else if( count < 100) pad = 6;
		else if( count < 1000) pad = 5;
		else if( count < 10000) pad = 4;
		else if( count < 100000) pad = 3;
		else if( count < 1000000) pad = 2;
		else if( count < 10000000) pad = 1;
		else if( count < 100000000) pad = 0;

		fprintf(out, "\n");	
		for(z = 0; z < pad; z++)
		{
			fputc('0', out);
		}
		fprintf(out, "%ld\n", count);
		fclose(out);

		/* write to the shell script file */
		fprintf(batch, "time ./truecrypt %s > %s%d\n", passfile, "out", i + 1);
	}

	fclose(batch);

	return 0;
}
