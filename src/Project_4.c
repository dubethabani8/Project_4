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
	printf("                --------------PART 1 -----------\n\n");
	printf("             INSERTING ALL DATA FROM FIGURES INTO DATABASE\n\n");
	insertALL();
	printf("              RESULTING DATABASE:\n\n");
	printDatabase();
	printf("\n            EXAMPLE 8.2 OPERATIONS:\n\n");
	//(a)
	printf("(a) Perfoming lookup((\"CS101\", \"12345\", \"*\"), Course-StudentId-Grade)...\nResult: \n");
	lookup_CSG("CS101", "12345", "*");
	//(b)
	printf("\n(b) Performing  lookup((\"CS205\", \"CS120\"), Course-Prerequisite)...\nResult: \n");
	lookup_CP("CS205", "CS120");
	//(c)
	printf("\n(c) Perfoming delete((\"CS101\", \"*\"), Course-Room)...\n");
	printf("CR tuples BEFORE deletion: \n");
	printCR();
	delete_CR("CS101", "*");
	printf("Remaining CR tuples AFTER deletion: \n");
	printCR();
	//(d)
	printf("(d) Perfoming insert(\"CS205\", \"CS120\"), Course-Prerequisite)\n");
	printf("CP tuples BEFORE insertion: \n");
	printCP();
	insert_CP("CS205", "CS120");
	printf("Remaining CP tuples AFTER insertion: \n");
	printCP();
	//(e)
	printf("(d) Perfoming insert(\"CS205\", \"CS101\"), Course-Prerequisite)\n");
	printf("CP tuples BEFORE insertion: \n");
	printCP();
	insert_CP("CS205", "CS101");
	printf("Remaining CP tuples AFTER insertion: \n");
	printCP();

	printf("DEMONSTRATING READ/WRITE TO FILE: \n");
	printf("\n\nWriting current database to file: database.txt\n");
	printf("Clearing the database (see source code reinitialization of tables) \n");
	printf("READING FROM SAME DATABASE FILE:\nBELOW IS THE READ DATABASE: \n\n");

	printf("REINSERTING EVERYTHING\nProcessing...\n");
	insertALL(); //Reinsert all for next Parts
	printf("REINSERTION COMPLETE\n");

	printf("\n\n                --------------PART 2 -----------\n\n");
	query1();
	query2();

	printf("\n\n                --------------PART 3 -----------\n\n");

	printf("Example 8.12: Selection: select Course =\"CS101\" (CSG)\n");
	select_CSG("CS101");
	printf("Example 8.13: Projection: Projecting the above tuples on StudentId \n");
	project_S();
	printf("Result:\n");
	printS();
	printf("Example 8.14: Join: Joining relations CR and CDH on Course \nProcessing...\n");
	join_CR_CDH();
	printf("Result: \n");
	printCRDH();
	allThree();
	return EXIT_SUCCESS;
}
