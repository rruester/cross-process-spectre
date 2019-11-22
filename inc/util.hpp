#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <inttypes.h>
#include <time.h>

#ifndef UTIL_H_
#define UTIL_H_

#define ADDR_PTR uint64_t 
#define CYCLES long long int

using namespace std;
CYCLES measure_one_block_access_time(ADDR_PTR addr);

#define cacheSize 32 * 1024
#define ways 8
#define channels 16

class BufferedWriter{
public:
    BufferedWriter(char* text_buf, ADDR_PTR** sets): text_buf_(text_buf), cacheSets(sets) {} 
    void write();
    void write_one_char(char c);
    void write_one_bit(bool b);

private:
	char startByte = 0b11111111;
	char junk = 0b11001100;
	ADDR_PTR** cacheSets;
    char* text_buf_;
};

class BufferedReader{
public:
    BufferedReader(ADDR_PTR** sets): cacheSets(sets) {} 
    void read(bool b);
    bool getBit();
    bool doGetBit();

private:
    int counter = 0;
    char buffer = 0;
    bool isReading = false;
    int measureCt = 10000;
	char startByte = 0b11111111;
	ADDR_PTR** cacheSets;

	// if 1s are turning to 0s, decrease.
	// if 0s are turning to 1s, increase.
	int cutoff = 10300000; // 16 channels, 10k measureCt
};

CYCLES measure_one_block_access_time(ADDR_PTR addr);
CYCLES rdtsc();
CYCLES getCycleEnd(CYCLES start);
ADDR_PTR** getCacheSets();
bool getBit();
bool doGetBit();

#endif
