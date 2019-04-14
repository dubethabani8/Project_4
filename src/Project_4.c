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
	TUPLELIST_SNAP snapT = newSNAP("30849952", "Thabani", "CMC", "5855128303");
	TUPLELIST_SNAP snapN = newSNAP("30849952", "Thabani", "CMC", "5855128303");
	snapT->next = snapN;
	insert_SNAP("30849952", "Thabani", "CMC", "5855128303");
	insert_CR("CSC172", "Hoyt");
	//TABLE_SNAP[73] = snapT;

	printf("LOOKUP RESULT: %d\n", lookup_CR("CSC172", "Hoyt"));

	delete_CR("CSC172","Hoyt");

	printf("LOOKUP RESULT AFTER DEL: %d\n", lookup_CR("CSC172", "Hoyt"));

	return EXIT_SUCCESS;
}
