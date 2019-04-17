/*
 * part_2.c
 *
 *  Created on: Apr 15, 2019
 *      Author: Thabani Dube
 */
void query1();
void query1();

void query1(){
	printf("QUESTION 1: Query to answer - What grade did StudentName get in CourseName?\n");
	char Name[15];
	char Course[15];
	printf("Enter Student Name: ");
	gets(Name);
	printf("Enter Course: ");
	gets(Course);
	
	printf("Proccessing... \n");
	int valid = lookup_SNAP("*",Name,"*","*");
	if(valid){
		for(int i=0; i<20; i++){
		if(last_snap[i] != NULL) valid = lookup_CSG(Course, last_snap[i]->StudentId, "*");
		}
		if(valid){
			for(int i=0; i<20;i++){
			if(last_csg[i] != NULL) printf("\nResult:\n%s got grade %s in %s\n",Name,last_csg[i]->Grade,Course);
		}
		}

		else printf("\nResult:\nCannot find data\n");
	}
	else{
		printf("\nResult:\nCannot find data\n");
	}
}

void query2(){
	printf("\n\nQUESTION 2: Query to answer - Where is StudentName at Time on Day?\n");
	char Name[15];
	char Day[5];
	char Hour[5];

	printf("Enter Student Name: ");
	gets(Name);
	printf("Enter Day: ");
	gets(Day);
	printf("Enter Hour: ");
	gets(Hour);

	printf("Proccessing... \n");
	int valid = lookup_SNAP("*",Name,"*","*");
	if(valid){
		for(int i=0; i<20; i++){
			if(last_snap[i] != NULL){
			valid = lookup_CSG("*",last_snap[i]->StudentId, "*");
			if(valid){
				for(int k=0; k<20; k++){
				if(last_csg[k] != NULL) valid = lookup_CDH(last_csg[k]->Course, Day, Hour);
			}
			}
		}
		}
		if(valid) lookup_CR(last_cdh[0]->Course, "*");
		printf("\nResult:\n%s is in %s at %s on %s\n",Name, last_cr[0]->Room, Hour, Day);
	}
	else printf("\nResult:\nCannot find data\n");
}

