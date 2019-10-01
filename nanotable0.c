/*CS1010 Lab 2
Program description:Nanotable is a simple table system that parses users' commands and
calculates the sum or average depending on user command
Name:Zhou Shikai
Tutorial:T02
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int parse_command();

int check_command(char* input);

void print_help();

int simple_sum();

int simple_average();

int get_sum(int);


int main() {
	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	parse_command();

	return 0;
}

// parse user command in a REPL style
int parse_command() {
	char tmp_command[100] = "";
	int command_code;
	//Prompt user for command in REPL style if exit command not given
	do {

		printf("Waiting for command...\n");
		scanf("%s", tmp_command);

		command_code = check_command(tmp_command);

		if (command_code == COMMAND_HELP) {
				print_help();
		}
		else if (command_code == COMMAND_EXIT) {
				printf("See you!\n");
		}
		else if (command_code == COMMAND_SUM) {
				simple_sum();
		}
		else if (command_code == COMMAND_AVE) {
				simple_average();
		}
		else {
		// others
		printf("No such command: %s, please input command again!\n", tmp_command);
		}
	} while(command_code != COMMAND_EXIT);

	return 0;
}

//Calculate the sum of input numbers
int simple_sum() {
	int num_of_int, sum;

	printf("Please indicate the number of integers:\n" );
	scanf("%d", &num_of_int);

	sum = get_sum(num_of_int);
	printf("sum is %d\n", sum);
	return 0;
}

//calculate average of input numbers rounded to the nearest integer
int simple_average() {
	int num_of_int, sum;
	float average;

	printf("Please indicate the number of integers:\n" );
	scanf("%d", &num_of_int);

	sum = get_sum(num_of_int);
	average = (float)sum/num_of_int;
	//round up the number if decimal place is more than equals .5
	if (fmod(average,1.0) >= 0.5) {
		average += 1;
	}
	average = (int)average;//truncate to nearest integer

	printf("average is %1.f\n", average);

	return 0;
}

//Prints out prompt for user to enter number and returns the sum of the inputs
int get_sum (int num_of_int) {
    int i, sum = 0;

	for (i = 1; i <= num_of_int; i++) {
		//create a string to show ordinal form of the number
		char ordinal[3] ;
		//create a variable to store the input number
		int number;
		//adding the corresponding ordinal form of the number
		if (i % 10 == 1) {
			strcpy(ordinal,"st");
		}
		else if (i % 10 == 2) {
			strcpy(ordinal,"nd");
		}
		else if (i % 10 == 3) {
			strcpy(ordinal,"rd");
		}
		else{
			strcpy(ordinal,"th");
		}
		printf("Please input the %d%s number:\n", i, ordinal);
		scanf("%d", &number);
		sum += number;
	}
    return sum;
}

// DO NOT MODIFY THE FOLLOWING PART!

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}
