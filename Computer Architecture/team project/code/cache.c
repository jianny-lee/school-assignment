/*
* cache.c
*
* 20493-02 Computer Architecture
* Term Project on Implentation of Cache Mechanism
*
* Skeleton Code Prepared by Prof. HyungJune Lee
* Nov 13, 2017
*
*/


#include <stdio.h>
#include <string.h>
#include "cache_impl.h"


extern int num_cache_hits;
extern int num_cache_misses;

extern int num_bytes;
extern int num_access_cycles;

extern int global_timestamp;

cache_entry_t cache_array[CACHE_SET_SIZE][DEFAULT_CACHE_ASSOC];
int memory_array[DEFAULT_MEMORY_SIZE_WORD];


/* DO NOT CHANGE THE FOLLOWING FUNCTION */
void init_memory_content() {
	unsigned char sample_upward[16] = {0x001, 0x012, 0x023, 0x034, 0x045, 0x056, 0x067, 0x078, 0x089, 0x09a, 0x0ab, 0x0bc, 0x0cd, 0x0de, 0x0ef};
	unsigned char sample_downward[16] = {0x0fe, 0x0ed, 0x0dc, 0x0cb, 0x0ba, 0x0a9, 0x098, 0x087, 0x076, 0x065, 0x054, 0x043, 0x032, 0x021, 0x010};
	int index, i=0, j=1, gap = 1;

	for (index=0; index < DEFAULT_MEMORY_SIZE_WORD; index++) {
		memory_array[index] = (sample_upward[i] << 24) | (sample_upward[j] << 16) | (sample_downward[i] << 8) | (sample_downward[j]);
		if (++i >= 16)
			i = 0;
		if (++j >= 16)
			j = 0;

		if (i == 0 && j == i+gap)
			j = i + (++gap);

		printf("mem[%d] = %#x\n", index, memory_array[index]);
	}
}   

/* DO NOT CHANGE THE FOLLOWING FUNCTION */
void init_cache_content() {
	int i, j;

	for (i=0; i<CACHE_SET_SIZE; i++) {
		for (j=0; j < DEFAULT_CACHE_ASSOC; j++) {
			cache_entry_t *pEntry = &cache_array[i][j];
			pEntry->valid = 0;
			pEntry->tag = -1;
			pEntry->timestamp = 0;
		}
	}
}

/* DO NOT CHANGE THE FOLLOWING FUNCTION */
/* This function is a utility function to print all the cache entries. It will be useful for your debugging */
void print_cache_entries() {
	int i, j, k;

	for (i=0; i<CACHE_SET_SIZE; i++) {
		printf("[Set %d] ", i);
		for (j=0; j <DEFAULT_CACHE_ASSOC; j++) {
			cache_entry_t *pEntry = &cache_array[i][j];
			printf("V: %d Tag: %#x Time: %d Data: ", pEntry->valid, pEntry->tag, pEntry->timestamp);
			for (k=0; k<DEFAULT_CACHE_BLOCK_SIZE_BYTE; k++) {
				printf("%#x(%d) ", pEntry->data[k], k);
			}
			printf("\n");
		}
		printf("\n");
	}
}

int check_cache_data_hit(void *addr, char type) {
	/* Fill out here */
	int word=*(unsigned long int *)addr%DEFAULT_CACHE_BLOCK_SIZE_BYTE; //bit of word
	int block_addr=*(unsigned long int *)addr/DEFAULT_CACHE_BLOCK_SIZE_BYTE; //block_addrress
	int cache_index=block_addr%CACHE_SET_SIZE; //cache_index(block number)
	int byte_addr_tag=*(unsigned long int *)addr/((DEFAULT_CACHE_BLOCK_SIZE_BYTE)*(CACHE_SET_SIZE)); //value of byte_address_tag
	int result_data, i; //value of result_data -> value of data_accessed
	num_access_cycles+=CACHE_ACCESS_CYCLE; //clock cycles +1

	//this for loop is checking the cache data whether cache_array is hit and if hit, get the memory from hit
	for(i=0;i<DEFAULT_CACHE_ASSOC;i++){
		if((cache_array[cache_index][i].valid==1)&&(cache_array[cache_index][i].tag==byte_addr_tag)){ //cache_tag==byte_addr_tag(cache hit), valid=1
			++num_cache_hits; // cache hits +1
			cache_array[cache_index][i].timestamp=global_timestamp;
			//A switch statement is used each type
			switch(type){
			case 'b' : //if type is 'b'
				result_data=cache_array[cache_index][i].data[word];
				num_bytes++; //plus one to the num_bytes
				break;
			case 'h' : //if type is 'h'
				result_data=(unsigned char)(cache_array[cache_index][i].data[word])|(cache_array[cache_index][i].data[word+1])<<8;
				num_bytes+=2; //plus two to the num_bytes
				break;
			case 'w' : //if type is 'w'
				result_data=(unsigned char)(cache_array[cache_index][i].data[word])|(unsigned char)(cache_array[cache_index][i].data[word+1])<<8|(unsigned char)(cache_array[cache_index][i].data[word+2])<<16|(cache_array[cache_index][i].data[word+3]<<24);
				num_bytes+=4; //plus four to the num_bytes
				break;
			}
			return result_data; //return to result_data
		}
	}
	++num_cache_misses; // cache misses +1
	return -1;
	/* Return the data */
}

int find_entry_index_in_set(int cache_index) {
	int entry_index; //row of cache_array
	int timestamp[DEFAULT_CACHE_ASSOC]; //use to check the LRU

	//Directed mapped cache
	//This 'for' loop is find the entry_index and timestamp when DEFAULT_CACHE_ASSOC is 1
	for(entry_index=0;entry_index<DEFAULT_CACHE_ASSOC;entry_index++){
		//if valid of cache_array is empty
		if(cache_array[cache_index][entry_index].valid==0){
			return entry_index; //reutrn to entry_index
		}
		timestamp[entry_index]=cache_array[cache_index][entry_index].timestamp;
	}
	//LRU /* Otherwise, search over all entries to find the least recently used entry by checking 'timestamp' */
	//2-way set associative cache
	//if DEFAULT_CACHE_ASSOC is 2
	if(DEFAULT_CACHE_ASSOC==2){ 
		if(timestamp[0]<=timestamp[1]){
			return 0;
		}
		else{
			return 1;
		}
	}

	//Fully associative cache
	//if DEFAULT_CACHE_ASSOC is 4
	else if(DEFAULT_CACHE_ASSOC==4){
		entry_index=(timestamp[0]<=timestamp[1])?0:1;
		entry_index=(timestamp[entry_index]<=timestamp[2])?entry_index:2;
		entry_index=(timestamp[entry_index]<=timestamp[3])?entry_index:3;
		return entry_index;
	}
	return 0;//direct map cache
}

int access_memory(void *addr, char type) { //when cache miss 
	/* Fetch the data from the main memory and copy them to the cache */
	/* void *addr: addr is byte address, whereas your main memory address is word address due to 'int memory_array[]' */
	/* You need to invoke find_entry_index_in_set() for copying to the cache */
	int word=*(unsigned long int *)addr%DEFAULT_CACHE_BLOCK_SIZE_BYTE; //bit of word
	int block_addr=*(unsigned long int *)addr/DEFAULT_CACHE_BLOCK_SIZE_BYTE; //block_addrress
	int cache_index=block_addr%CACHE_SET_SIZE; //cache_index(block number)
	int block_start_mem_index=block_addr*2; //memory index of start of memory address in word access block_addr
	int byte_addr_tag=*(unsigned long int *)addr/((DEFAULT_CACHE_BLOCK_SIZE_BYTE)*(CACHE_SET_SIZE)); //value of byte_address_tag
	int result_data, entry_index, i; //value of result_data -> value of data_accessed, entry_index -> entry

	num_access_cycles+=MEMORY_ACCESS_CYCLE ; //clock cycles +100(plan to use in bandwidth)
	//if cache miss, num_access_cycles add 100

	entry_index=find_entry_index_in_set(cache_index);//find the entry_index of index in set

	//insert the data of memory_array in cache_array data
	for(i=0;i<DEFAULT_CACHE_BLOCK_SIZE_BYTE;i++){
		if(i<4){
			cache_array[cache_index][entry_index].data[i]=(memory_array[block_start_mem_index]>>8*i);
		}
		else{
			cache_array[cache_index][entry_index].data[i]=(memory_array[block_start_mem_index+1]>>8*(i-4));
		}
	}

	cache_array[cache_index][entry_index].tag=byte_addr_tag; //byte_addr_tag is the tag of cache_array 
	cache_array[cache_index][entry_index].valid=1; //the valid of cahce_array is '1' if access the memory
	cache_array[cache_index][entry_index].timestamp=global_timestamp;//global_timestamp is timestamp of cache_array

	//A switch statement is used each type to get the memory
	switch(type){
	case 'b' : //if type is 'b'
		//read the 1 byte
		result_data=cache_array[cache_index][entry_index].data[word];
		num_bytes++; //plus one to the num_bytes
		break;
	case 'h' : //if type is 'h'
		//read the 2 bytes
		result_data=(unsigned char)(cache_array[cache_index][entry_index].data[word])|(cache_array[cache_index][entry_index].data[word+1])<<8;
		num_bytes+=2; //plus two to the num_bytes
		break;
	case 'w' : //if type is 'w'
		//read the 4 bytes
		result_data=(unsigned char)(cache_array[cache_index][entry_index].data[word])|(unsigned char)(cache_array[cache_index][entry_index].data[word+1])<<8|(unsigned char)(cache_array[cache_index][entry_index].data[word+2])<<16|(cache_array[cache_index][entry_index].data[word+3]<<24);
		num_bytes+=4; //plus four to the num_bytes
		break;
	}
	return result_data; //return to result_data

	/* Return the accessed data with a suitable type */   
	//cache_array[cache_index][DEFAULT_CACHE_ASSOC].tag=byte_addr_tag;
}