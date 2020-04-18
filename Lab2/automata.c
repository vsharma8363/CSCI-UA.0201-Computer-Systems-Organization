/**
 * Author: Vikram Aditya Sharma (vas360)
 * Course: CSO - SP2020
 * Description: Cellular Automation program based on Lab #2 Specification
 **/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ROWS 5
#define COLS 5

int(*current_gen)[COLS][ROWS]; // Pointer to the current generation
int(*new_gen)[COLS][ROWS]; // Pointer to the new (updated generation)
int(*temp_gen)[COLS][ROWS]; // Pointer to the temporary generation (intermediary)

/**
 * filename[]: String of the output file name (same as input file, '.out' is added in-function)
 **/
void print_world(char filename[])
{
	FILE *file_ptr;
	file_ptr = fopen(strcat(filename, ".out"), "w");

	for (int i = 0; i < COLS; i++) 
	{
		for (int j = 0; j < ROWS; j++) 
		{
			fprintf(file_ptr, "%d ", (*current_gen)[i][j]);
		}
		fprintf(file_ptr, "\n");
    }

	// Close the file when finished
	fclose(file_ptr);
}

/**
 * current_cell: The integer representation of the current cell isAlive value (1-live, 0-dead)
 * neighbors: Total number of neighbors to current_cell
 * return: integer to determine the cell's life status (1-live, 0-dead)
 **/
int decision(int current_cell, int neighbors)
{
	// A live cell with fewer than two live neighbors dies
	if(current_cell == 1 && neighbors < 2)
		return 0;
	// A live cell with more than three live neighbors dies
	if(current_cell == 1 && neighbors > 3)
		return 0;
	// A live cell with exactly two or three neighbors lives
	if(current_cell == 1 && (neighbors == 2 || neighbors == 3))
		return 1;
	// A dead cell with exactly three neighbors becomes alive
	if(current_cell == 0 && neighbors == 3)
		return 1;
	// Every other situation
	else
		return 0;
}


/**
 * Function uses method outlined in spec to update world values
 **/
void update_WORLD()
{
	for (int i = 0; i < COLS; i++) 
	{
		for (int j = 0; j < ROWS; j++) 
		{
			int num_neighbors = 0;
			// Loop through all 9 cells in the subgrid
			for(int i_offset = -1; i_offset <= 1; i_offset++)
			{
				for(int j_offset = -1; j_offset <= 1; j_offset++)
				{
					int new_i = i + i_offset;
					int new_j = j + j_offset;
					// Check if the neighbor is in bounds
					if ((0 <= new_i) && (new_i < COLS) && (0 <= new_j) && (new_j < ROWS)) 
					{
						num_neighbors += (*current_gen)[new_i][new_j];
					}
				}
			}
			// Subtract value of origin cell
			num_neighbors -= (*current_gen)[i][j];
			(*new_gen)[i][j] = decision((*current_gen)[i][j], num_neighbors);
		}
    }

	// Swap the current and new generations to prevent the need to create new arrays
	temp_gen = current_gen;
    current_gen = new_gen;
    new_gen = temp_gen;
}

/**
 * argc: number of arguments
 * argv[]: arguments from command-line
 **/
int main(int argc, char *argv[])
{
	if(argc <= 2)
	{
		printf("You did not enter the generations and/or filename");
		exit(0);
	}	
	else
	{
		// Find num of generations to evolve
		int num_generations = atoi(argv[1]);

		// Open the input file and define input grid
		FILE *input_file = fopen(argv[2], "r");		

		// Define intermediary and final matrices to hold world values
		int world_grid[COLS][ROWS];
		int empty_grid[COLS][ROWS];

		// Run file checks
		if(input_file == NULL)
		{
			printf("File did not open\n");
			exit(0);
		}
		else
		{
			// 2*ROWS because of the spaces between each cell
			for (int i = 0; i < 2*COLS; i++)
			{
    			for (int j = 0; j < ROWS; j++)
    			{
					char c;
					fscanf(input_file, "%c", &c);
					if(isdigit(c))
					{
						// Main input world grid
						world_grid[i][j] = atoi(&c);

						// Empty grid for initialization
						empty_grid[i][j] = 0;
					}
					else
					{
						fscanf(input_file, "%d", &world_grid[i][j]);
					}
					
				}
			}
			fclose(input_file);
		}

		// Set pointer values
		current_gen = &world_grid;
		new_gen = &empty_grid;

		// Run update loop using rule function for number of generations
		for(int i = 0; i < num_generations; i++)
		{
			update_WORLD();
		}

		// print world updated world grid to the output file following "input.txt.out" format
		print_world(argv[2]);

		return 0;
	}
}


