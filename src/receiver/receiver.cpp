#include"util.hpp"
#include"receiver.hpp"
#include <stdio.h>

int main(int argc, char **argv)
{
    BufferedReader reader(getCacheSets());

	printf("Attacker now listening.\n");

	while (1) {
        reader.read(reader.getBit());
	}

	return 0;
}
