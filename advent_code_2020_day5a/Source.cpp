#include <stdio.h>


int main() {
	char s[12];

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Unable to open input file\n");
		return 1;
	}

	int maxid = -1;
	while (fscanf(fin, "%s", s) == 1) {
		int id = 0;
		for (char *p = s; *p; p++) {
			id <<= 1;
			if (*p == 'B' || *p == 'R')
				id++;
		}

		if (id > maxid)
			maxid = id;
	}

	printf("%d\n", maxid);

	fclose(fin);
	return 0;
}