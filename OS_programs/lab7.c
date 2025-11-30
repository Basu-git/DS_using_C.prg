#include <stdio.h>

/* Function Prototypes */
void removeNewline(char str[]);
void replaceAll(char str[], char pat[], char rep[], char result[]);

/* Function: main */
int main()
{
	char str[100], pat[50], rep[50], result[200];

	printf("Enter the main text string (STR): ");
	fgets(str, sizeof(str), stdin);
	removeNewline(str);

	printf("Enter the pattern string (PAT): ");
	fgets(pat, sizeof(pat), stdin);
	removeNewline(pat);

	printf("Enter the replacement string (REP): ");
	fgets(rep, sizeof(rep), stdin);
	removeNewline(rep);

	replaceAll(str, pat, rep, result);

	return 0;
}

/* Function: removeNewline */
void removeNewline(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
		i++;
	}
}

/* Function: replaceAll */
void replaceAll(char str[], char pat[], char rep[], char result[])
{
	int i = 0, j = 0, k;
	int found = 0;
	int patLen = 0, repLen = 0, strLen = 0;

	while (str[strLen] != '\0') strLen++;
	while (pat[patLen] != '\0') patLen++;
	while (rep[repLen] != '\0') repLen++;

	while (str[i] != '\0')
	{
		// Simple if..else logic instead of calling patternMatch()
		int match = 1; // assume pattern matches
		for (k = 0; k < patLen; k++)
		{
			if (str[i + k] == '\0' || str[i + k] != pat[k])
			{
				match = 0; // mismatch found
				break;
			}
		}

		if (match == 1)
		{
			found = 1;
			for (k = 0; k < repLen; k++)
				result[j++] = rep[k];
			i += patLen; // skip over matched pattern
		}
		else
		{
			result[j++] = str[i++];
		}
	}

	result[j] = '\0';

	if (found)
		printf("\nReplaced String is: %s\n", result);
	else
		printf("\nPattern \"%s\" not found in the text.\n", pat);
}