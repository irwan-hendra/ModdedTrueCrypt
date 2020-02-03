#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPAD 8


void add_pad(FILE *out, long count)
{
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
	int z;
	for(z = 0; z < pad; z++)
	{
		fputc('0', out);
	}
	fprintf(out, "%ld\n", count);
}

void updateBatch(FILE *bf_out, int pi, char *passfile)
{
	fprintf(bf_out, "./truecrypt %s headerfile.enc RIPEMD160 AES > out%d &\n", passfile, pi++);

	// parallel processing at 2 processes at a time
	if(pi % 2 == 0)
	{
		fprintf(bf_out, "sleep 6h\n");
	}
	else
	{
		fprintf(bf_out, "sleep 5\n");
	}	
}

int main (int argc, char **argv)
{
	/* password and shell script files generation */
	int a,b,c,d,e,f,g,z,i, bi, pi;
	char *ch = "12345qwertasdfgzxcvb!@#$%QWERTASDFGZXCVB";
	int nch = strlen(ch);
	int ppr = 25; // pass per row
	int ppf = 600000; // pass per file

	// pre-loop, create batch and pass file
	char batchfile[20] = "";
	char passfile[20] = "";
	char *static_ppat = "dfk3^9";
	char *ppat = "%s%c%c%c%c";
	char *batchfilepat = "batch%d.sh";
	char *passfilepat = "passes%d.dat"; 
	bi = 2;
	pi = 11;
	sprintf(batchfile, batchfilepat, bi); 
	sprintf(passfile, passfilepat, pi);
	FILE *pf_out = fopen(passfile, "wb");
	FILE *bf_out = fopen(batchfile, "wb");

	// some info
	fprintf(stdout, "Batch File pattern: %s\n", batchfilepat);
	fprintf(stdout, "Pass File pattern: %s\n", passfilepat);
	fprintf(stdout, "Pass pattern: %s\n", ppat);
	fprintf(stdout, "Pass per row:%d\n", ppr);
	fprintf(stdout, "Pass per file:%ld\n", ppf);
	fprintf(stdout, "Total char pool:%d\n", nch);

	long count = 0;
	long totalcount = 0;
	for(a = 0; a < nch; a++){
	for(b = 0; b < nch; b++){
	if(ch[b] == ch[a]) continue;

	for(c = 0; c < nch; c++)
	{
		if(ch[c] == ch[b]) continue;
		if(ch[c] == ch[a]) continue;
			
		for(d = 0; d < nch; d++)
		{
			if(ch[d] == ch[c]) continue;
			if(ch[d] == ch[b]) continue;
			if(ch[d] == ch[a]) continue;
			
	//		for(e = 0; e < nch; e++)
	//		{
	//			if(ch[e] == ch[d]) continue;
	//			if(ch[e] == ch[c]) continue;
	//			if(ch[e] == ch[b]) continue;
	//			if(ch[e] == ch[a]) continue;

				fprintf(pf_out, ppat, static_ppat, ch[a], ch[b], ch[c], ch[d]);
				totalcount++;
				count++;
				if(count % ppr == 0) fprintf(pf_out, "\n");
				if(count == ppf)
				{
					// close, add to batch file
					add_pad(pf_out, count);
					fclose(pf_out);
					fprintf(stdout, "Created pass file: %s:: pass count:%ld\n", passfile, count);

					updateBatch(bf_out, pi, passfile);

					// open new one, reset count
					sprintf(passfile, "passes%d.dat", ++pi);
					pf_out = fopen(passfile, "wb");
					count = 0;
				}
	//		}
		}
	}}}


	// close, add to batch file
	add_pad(pf_out, count);
	fclose(pf_out);
	fprintf(stdout, "Created pass file: %s:: pass count:%ld\n", passfile, count);

	updateBatch(bf_out, pi, passfile);
	fclose(bf_out);
	fprintf(stdout, "Created batch file: %s\n", batchfile);

	// last display
	fprintf(stdout, "Total count: %ld\n", totalcount);

	return 0;
}
