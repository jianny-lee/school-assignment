/*
 * main.c
 *
 * 20493-02 Computer Architecture
 * Term Project on Implentation of Cache Mechanism
 *
 * Skeleton Code Prepared by Prof. HyungJune Lee
 * Nov 13, 2017
 *
 */

#include <stdio.h>
#include "cache_impl.h"

int num_cache_hits = 0;
int num_cache_misses = 0;

int num_bytes = 0;
int num_access_cycles = 0;

int global_timestamp = 0;

int retrieve_data(void *addr, char data_type) {
    int value_returned = -1; /* accessed data (miss라고 우선 가정)*/
    
    /* Invoke check_cache_data_hit() */
   value_returned=check_cache_data_hit(addr,data_type);

   /* In case of the cache miss event, access the main memory by invoking access_memory() */
   if(value_returned==-1){
      value_returned=access_memory(addr,data_type);
   }

   ++global_timestamp; //data access trial no. +1

    return value_returned;    
}

int main(void) {
    FILE *ifp = NULL, *ofp = NULL;
    unsigned long int access_addr; /* byte address (located at 1st column) in "access_input.txt" */
    char access_type; /* 'b'(byte), 'h'(halfword), or 'w'(word) (located at 2nd column) in "access_input.txt" */
    int accessed_data; /* This is the data that you want to retrieve first from cache, and then from memory */ 
    
    init_memory_content();
    init_cache_content();
    
    ifp = fopen("access_input.txt", "r");
    if (ifp == NULL) {
        printf("Can't open input file\n");
        return -1;
    }
    ofp = fopen("access_output1_3.txt", "w");
    if (ofp == NULL) {
        printf("Can't open output file\n");
        fclose(ifp);
        return -1;
    }
    /* Fill out here by invoking retrieve_data() */
   fprintf(ofp,"[Accessed Data]\n");

   while(fscanf(ifp,"%d   %c",&access_addr,&access_type)!=EOF){
      accessed_data=retrieve_data(&access_addr,access_type);
      fprintf(ofp,"%d	%c	%#x\n",access_addr,access_type,accessed_data);
   }

   fprintf(ofp,"------------------------------------\n");
   switch(DEFAULT_CACHE_ASSOC){
   case 1 :{
   fprintf(ofp,"[Direct mapped cache performance]\n");
   fprintf(ofp,"Hit ratio = %.2f(%d/%d)\n",(float)num_cache_hits/global_timestamp,num_cache_hits,global_timestamp);
   fprintf(ofp,"Bandwidth = %.2f(%d/%d)\n",(float)num_bytes/num_access_cycles,num_bytes,num_access_cycles);
   break;
        }
   case 2 :{
   fprintf(ofp,"[2-way set associative cache performance]\n");
   fprintf(ofp,"Hit ratio = %.2f(%d/%d)\n",(float)num_cache_hits/global_timestamp,num_cache_hits,global_timestamp);
   fprintf(ofp,"Bandwidth = %.2f(%d/%d)\n",(float)num_bytes/num_access_cycles,num_bytes,num_access_cycles);
   break;
        }
   case 4 :{
      fprintf(ofp,"[Fully associative cache performance]\n");
   fprintf(ofp,"Hit ratio = %.2f(%d/%d)\n",(float)num_cache_hits/global_timestamp,num_cache_hits,global_timestamp);
   fprintf(ofp,"Bandwidth = %.2f(%d/%d)\n",(float)num_bytes/num_access_cycles,num_bytes,num_access_cycles);
         }
   }

   fclose(ifp);
    fclose(ofp);
    
    print_cache_entries();
    return 0;
}