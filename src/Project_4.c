/*
 ============================================================================
 Name        : Project_4.c
 Author      : Thabani
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void) {
	TUPLELIST_CSG csgT = newCSG("CSC173", "30849952", "A");
	TUPLELIST_CSG csgN = newCSG("CSC173", "30849952", "B");
	csgT->next = csgN;
	insert_CSG("CSC173", "30849952", "A");

	//TABLE_CSG[73] = csgT;

	printf("LOOKUP RESULT: %d\n", lookup_CSG("CSC173", "30849952", "*"));

	delete_CSG("CSC173", "30849952", "*");

	printf("LOOKUP RESULT AFTER DEL: %d\n", lookup_CSG("CSC173", "30849952", "*"));

	return EXIT_SUCCESS;
}
