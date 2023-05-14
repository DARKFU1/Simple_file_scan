#include <stdio.h>

#define watch_int(x) printf("%s: %i\n", #x, x);

int IsALetter(const char ch)
{
	return (ch > 64 && ch < 91) || (ch > 96 && ch < 123);
}

int main(const int argc, const char** argv)
{
	FILE* file;

	if(argc > 1)
	{
		file = fopen(argv[1], "a");
		fprintf(file, "");
		fclose(file);

		file = fopen(argv[1], "r");
	}
	else
	{
		file = stdin;
	}

	int inp;
	int i = 0; 

	int lines = 0;
	unsigned int words = 0;

	char buffer = malloc(10000000);

	while(inp != EOF)
	{
		inp = getc(file);
		buffer[i++] = inp;

		if(inp == '\n')
		{
			++lines;
		}

		if( i < 2 ) continue;

		if((buffer[i-2] != ' ' &&\
			buffer[i-2] != '\t') &&\
			(inp == ' ' || inp == '\t'))
		{
			++words;
		}

	}

	printf("\n~~~~~~~~~~~~~~~~~~ FILE CONSISTANCE ~~~~~~~~~~~~~~~~~~\n");
	printf("Lines: %i\n", lines);
	printf("Words: %i\n", words + 1);
	printf("Symbols: %i\n", i - 1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

 free(buffer);

	return 0;
}
