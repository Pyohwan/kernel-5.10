/* Stub extract-cert - no openssl needed when SYSTEM_TRUSTED_KEYS is empty */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "Usage: scripts/extract-cert <source> <dest>\n");
		exit(2);
	}
	/* If source is empty string, create empty dest file (normal case when
	 * CONFIG_SYSTEM_TRUSTED_KEYS="") */
	if (!argv[1][0]) {
		FILE *f = fopen(argv[2], "wb");
		if (!f) {
			perror(argv[2]);
			exit(1);
		}
		fclose(f);
		exit(0);
	}
	fprintf(stderr, "extract-cert: stub does not support non-empty cert source\n");
	exit(1);
}
