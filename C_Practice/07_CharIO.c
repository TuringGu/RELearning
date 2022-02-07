#include <stdio.h>
#include <ctype.h>  

int main(){
	char string;

	// Input CTRL+C, CTRL+Z , or any other unvisible char to stop the program 
	// Note: the input string is saving into buffer zones, and program get the char in order
	while ((string = getchar()) != EOF){
		putchar(string);
	}
	return 0;
}