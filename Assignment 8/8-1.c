#include <stdio.h>
#include <stdlib.h>

struct Line {
	unsigned char data[2]; // 2-byte blocks
	unsigned int tag; // assume tag is at most 32 bits
	unsigned char valid; // valid bit
};

struct Cache {
	struct Line *lines;
	int numLines;
};

unsigned int getOffset(unsigned int address){
	return address & 0x1; // 2-byte blocks, so 1 offset bit
}

unsigned int getSet(unsigned int address) {
	return (address >> 1) & 0x7; // 2-byte blocks; 8 sets so 3 set bits
}

unsigned int getTag(unsigned int address) {
	return address >> 4; // total of 4 bits for offset and set
}

struct Cache* mallocCache(int numLines) {
	//malloc a pointer to a struct Cache 
	struct Cache* cache = malloc(numLines * sizeof(struct Cache));
	cache->numLines = numLines;	
	//malloc a pointer to an array of struct Line instances (array length is numLines). 
	cache->lines = malloc(sizeof(struct Line) * numLines);
	//Also initialize valid to 0 for each struct Line.
	for (int i = 0; i < numLines; i++) {
		cache->lines[i].valid = 0;
		}
	//Return the struct Cache pointer.
	return cache;
}

void freeCache(struct Cache *cache) {
	free(cache->lines);
	free(cache);
}

void printLine(struct Line *line, unsigned int set) {
	unsigned char *data = line->data;
	printf("set: %x - tag: %x - valid: %u - data: %.2x %.2x\n", set, line->tag, line->valid, data[0], data[1]);
}

void printCache(struct Cache *cache) {
	//print all valid lines in the cache.
	int v = 1;
	for (int i = 0; i < cache->numLines; i++) {
		if (cache->lines[i].valid == v) {
			printLine(&cache->lines[i], i);
			
		}
	}

}

void readValue(struct Cache *cache, unsigned int address) {
	unsigned int t = getTag(address);
	unsigned int s = getSet(address);
	//check the cache for a cached byte at the specificed address.
	printf("Looking for set: %x - tag: %x\n", s, t); 
	int tracker = 0;
	int counter = 0;
	//If found, indicate a hit and print the byte.
	for (int i = 0; i < cache->numLines; i++){
		if ((s == i) && (t == cache->lines[i].tag) && (cache->lines[i].valid == 1)){
			tracker = 1;
			counter = i;
			break;
			}
			
		}		
		if (tracker == 1) {
			//if found, indicate a hit and print the byte
			printf("found ");
			printLine(&cache->lines[counter:wq
			], counter);
			printf("hit!\n");
		}
		else
		{
			// if not found, indicate a miss
			printf("no valid line found - miss!\n");
		}
	
}

void writeValue(struct Cache *cache, unsigned int address, unsigned char *newData) {
	unsigned int s = getSet(address);
	unsigned int t = getTag(address);
        
	struct Line *line = &cache->lines[s];
	if (line->valid && line->tag != t) {
		unsigned char *data = line->data;
		printLine(line, s);
	}

	for (int i = 0; i < 4; ++i) {
		line->data[i] = newData[i];
	}

	line->tag = t;
	line->valid = 1;

	printf("wrote set: ");
	printLine(line, s);
}

unsigned int readUnsignedIntFromHex() {
	char buffer[10];
	char *p = NULL;
	unsigned int n;
	while (1) {
		fgets(buffer, sizeof(buffer), stdin);
		n = strtoul(buffer, &p, 16);
		if (buffer != p) {
			break;
		}
		printf("Invalid input - try again: ");
	}
	return n;
}

int main() {
	struct Cache *cache = mallocCache(8);

	char buffer[10];
	char c;
	do {
		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
		fgets(buffer, sizeof(buffer), stdin);

		c = buffer[0];
		if (c == 'r') {
			printf("Enter 32-bit unsigned hex address: ");
			unsigned int a = readUnsignedIntFromHex();
			readValue(cache, a);
		} else if (c == 'w') {
			printf("Enter a 32-bit unsigned hex address: ");
			unsigned int a = readUnsignedIntFromHex();

			printf("Enter 32-bit unsigned hex value: ");
			unsigned int v = readUnsignedIntFromHex();
			unsigned char *data = (unsigned char*) &v;
			writeValue(cache, a, data);
		} else if (c == 'p') {
			printCache(cache);
		}
	} while (c != 'q') ;
	freeCache(cache);
}

