#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

struct MEMORY {
	int page_num;
	int reference_bit;
	int dirty_bit;
};

struct PAGE {
	int memory_location;
	int valid_bit;
};
struct PAGE page[200000];

int main(int argc, char *argv[]) {
	if (argc < 2)
	{
		printf("Argc is Error!\n");
	}
	else {
		int memory_size = atoi(argv[1]);
		int i, pg, op, clock = 0, out_pg = 0;
		int pg_fault = 0, disk_write = 0, head_movement = 0, now_loc = 0, before_loc = 0, after_loc = 0;
		FILE *input_file = fopen("a.txt", "r");
		struct MEMORY *memory = (struct MEMORY*)malloc(memory_size * sizeof(struct MEMORY));

		if (input_file == NULL) {
			fprintf(stderr, "Can't oepn file\n");
			exit(1);
		}

		for (i = 0; i < memory_size; i++) {
			memory[i].reference_bit = 0;
			memory[i].dirty_bit = 0;
		}

		for (i = 0; i < 200000; i++)
			page[i].valid_bit = 0;

		while (!feof(input_file)) {
			fscanf(input_file, "%d %d", &pg, &op); 
			if (page[pg].valid_bit == 1) { 
				memory[page[pg].memory_location].reference_bit = 1;
				if (op == 1)
					memory[page[pg].memory_location].dirty_bit = 1;
			}
			else {
				pg_fault++;

				if (pg_fault <= memory_size) {
					after_loc = pg / 1000;
					head_movement += abs(after_loc - before_loc);
					before_loc = after_loc;
					memory[clock].page_num = pg;
					memory[clock].dirty_bit = op;
					page[pg].memory_location = clock;
					page[pg].valid_bit = 1;
					clock++;
					if (clock == memory_size)
						clock = 0;
				}

				else if (pg_fault > memory_size) {

					while (memory[clock].reference_bit == 1) {
						memory[clock].reference_bit = 0;
						clock++;
						if (clock == memory_size)
							clock = 0;
					}

					page[memory[clock].page_num].valid_bit = 0;
					if (memory[clock].dirty_bit == 1) {
						disk_write++;
						memory[clock].dirty_bit = op;
						now_loc = memory[clock].page_num / 1000;
						after_loc = pg / 1000;
						head_movement += abs(now_loc - before_loc);
						head_movement += abs(after_loc - now_loc);
						before_loc = after_loc;
					}

					else {
						now_loc = memory[clock].page_num / 1000;
						after_loc = pg / 1000;
						head_movement += abs(after_loc - before_loc);
						before_loc = after_loc;
						memory[clock].dirty_bit = op;
					}

					memory[clock].page_num = pg;
					page[pg].memory_location = clock;
					page[pg].valid_bit = 1;
					clock++;
					if (clock == memory_size)
						clock = 0;
				}
			}
		}
		fclose(input_file);
		free(memory);
		printf("Page fault count = %d\n", pg_fault);
		printf("Disk write count = %d\n", disk_write);
		printf("Disk head moving distance=%d\n\n", head_movement);

	}
}

