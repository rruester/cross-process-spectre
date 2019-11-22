#include "util.hpp"
#include "sender.hpp"

ADDR_PTR** cacheSets = getCacheSets();

// Loads data into cache based on secret value.
// Read by attacker using prime+probe attack.
void writeSecret() {
	char text_buf[] = "Secret data\n\0";
	BufferedWriter writer(text_buf, cacheSets);
	writer.write();
}

int main(int argc, char **argv)
{
	while (1) {
		// Explicitly call writeSecret().
		// Todo: Trick victim into calling writeSecret() speculatively by priming the return address stack
		// from attacker process.
		writeSecret();
	}

	printf("Sender finished.\n");

	return 0;
}