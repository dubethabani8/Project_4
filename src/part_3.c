/*
 * part_3.c
 *
 *  Created on: Apr 16, 2019
 *      Author: Thabani Dube
 */

typedef struct TUPLE_S *TUPLELIST_S; //Primary index on Course-StudentId
struct TUPLE_S {
char * StudentId;
TUPLELIST_S next;
};
typedef TUPLELIST_S HASHTABLE_S[197];

typedef struct TUPLE_CRDH *TUPLELIST_CRDH; //Primary index on Course-StudentId
struct TUPLE_CRDH {
char * Course;
char * Room;
char * Day;
char * Hour;
TUPLELIST_CRDH next;
};
typedef TUPLELIST_CRDH HASHTABLE_CRDH[197];

typedef struct TUPLE_DH *TUPLELIST_DH; //Primary index on Course-StudentId
struct TUPLE_DH {
char * Day;
char * Hour;
TUPLELIST_DH next;
};
typedef TUPLELIST_DH HASHTABLE_DH[197];


//New Tables
HASHTABLE_S TABLE_S;
HASHTABLE_CRDH TABLE_CRDH;
HASHTABLE_DH TABLE_DH;


void select_CSG(char * Course);
void project_S();
void join_CR_CDH();
void allThree();

void insert_S();
void insert_CRDH(char * Course, char * Room, char * Day, char * Hour);
void insert_DH(char * Day, char * Hour);

int lookup_S(char * StudentId);
int lookup_CRDH(char * Course, char * Room, char * Day, char * Hour);
int lookup_DH(char * Day, char * Hour);


void printS();
void printCRDH();

void toString_S(TUPLELIST_S s);
void toString_CRDH(TUPLELIST_CRDH crdh);
void toString_DH(TUPLELIST_DH dh);

TUPLELIST_S last_s[15];
TUPLELIST_CRDH last_crdh[15];
TUPLELIST_DH last_dh[15];

TUPLELIST_S newS(char * StudentId);
TUPLELIST_CRDH newCRDH(char * Course,char * Room, char * Day, char * Hour);
TUPLELIST_DH newDH(char * Day, char * Hour);

void select_CSG(char * Course){
	lookup_CSG(Course,"*","*");
	//These are also stored in last_CSG but the fuction also prints them
}

void project_S(){
	for(int i=0; i<15; i++){
		if(last_csg[i] != NULL)
			insert_S(last_csg[i]->StudentId);
	}
}

void allThree(){
	int valid = lookup_CRDH("*","Turing Aud.","*","*");
	if(valid){
			for(int i=0; i<15; i++){
		if(last_crdh[i] != NULL){
			insert_DH(last_crdh[i]->Day, last_crdh[i]->Hour);
		toString_CRDH(last_crdh[i]);
	}
	}
	}
	else printf("Cannot find data\n");
}

void join_CR_CDH(){
		for(int i=0; i<197; i++){
			TUPLELIST_CDH cdh = TABLE_CDH[i];
			if(cdh == NULL) continue;
			else{
				while(cdh != NULL){
					lookup_CR(cdh->Course, "*");
					TUPLELIST_CR cr = last_cr[0];
					j = 0;
					if(strcmp(cdh->Course, cr->Course) == 0){
						insert_CRDH(cdh->Course, cr->Room, cdh->Day, cdh->Hour);
					}
					cdh = cdh->next;
				}
			}
		}
}

void insert_S(char * StudentId){
		//Make cdh struct and insert if not already there
	int present = lookup_S(StudentId);
	if(!present){
		//insert into hashtable
		TUPLELIST_S s = newS(StudentId);

			char key[strlen(s->StudentId)];
			strcpy(key, s->StudentId);
			int index = hash(key);
			TUPLELIST_S current = TABLE_S[index];
			if(current == NULL) {
				TABLE_S[index] = s;}
			else {
				while(current->next != NULL)
					current = current->next;
				current->next = s;
			}
	}
	else return;
}

void insert_CRDH(char * Course, char * Room, char * Day, char * Hour){
	//Make cdh struct and insert if not already there
	int present = lookup_CRDH(Course, Room, Day, Hour);
	if(!present){
		//insert into hashtable
		TUPLELIST_CRDH crdh = newCRDH(Course, Room ,Day,Hour);

			char key[strlen(crdh->Course)];
			strcpy(key, crdh->Course);
			strcat(key, crdh->Day);
			int index = hash(key);
			TUPLELIST_CRDH current = TABLE_CRDH[index];
			if(current == NULL) {
				TABLE_CRDH[index] = crdh;}
			else {
				while(current->next != NULL)
					current = current->next;
				current->next = crdh;
			}
	}
	else return;
}

void insert_DH(char * Day, char * Hour){
		//Make csg struct and insert if not already there
	int present = lookup_CP(Day, Hour);
	if(!present){
		//insert into hashtable
		TUPLELIST_DH dh = newDH(Day, Hour);
			char key[strlen(dh->Day)];
			strcpy(key, dh->Day);
			strcat(key, dh->Hour);
			int index = hash(key);
			TUPLELIST_DH current = TABLE_DH[index];
			if(current == NULL) {
				TABLE_DH[index] = dh;}
			else {
				while(current->next != NULL)
					current = current->next;
				current->next = dh;
			}
	}
	else return;
}


int lookup_S(char * StudentId){
	int found = 0;
	j = 0;
	//If possible, get key and search that bucket for the tuple quickly
	if(strcmp("*", StudentId) != 0){
	char key[strlen(StudentId)];
	strcpy(key, StudentId);
	int index = hash(key);
	TUPLELIST_S s = TABLE_S[index];
	if(s == NULL) return 0;
	else {
		while(s != NULL){
			if(strcmp(s->StudentId, StudentId) == 0 || strcmp(StudentId, "*") == 0) {
				found = 1;
				lastLookupIndex = index;
				last_s[j] = s;
				j++;
				toString_S(s);
				s = s->next;
			}
			else s = s->next;
		}
		return found;
	}
	}
	else { //Search all buckets if key cannot be used. Could use secondary indexing???
		for(int i=0; i<197; i++){
			TUPLELIST_S s = TABLE_S[i];
			if(s == NULL) continue;
			else{
				while(s != NULL){
					if(strcmp(s->StudentId, StudentId) == 0 || strcmp(StudentId, "*") == 0){
						lastLookupIndex = i;
						found = 1;
						last_s[j] = s;
						j++;
						toString_S(s);
						s = s->next;
			}
				else s = s->next;
				}
			}
		}
	}
	return found;
}

int lookup_CRDH(char * Course, char * Room, char * Day, char * Hour){
	int found = 0;
	j = 0;
	//If possible, get key and search that bucket for the tuple quickly
	if(strcmp("*", Course) != 0 && strcmp("*", Day) != 0){
	char key[strlen(Course)];
	strcpy(key, Course);
	strcat(key, Day);
	int index = hash(key);
	TUPLELIST_CRDH crdh = TABLE_CRDH[index];
	if(crdh == NULL) return 0;
	else {
		while(crdh != NULL){
			if((strcmp(crdh->Hour, Hour) == 0 || strcmp(Hour, "*") == 0) &&
				(strcmp(crdh->Room, Room) == 0 || strcmp(Room, "*") == 0) &&
				(strcmp(crdh->Course, Course) == 0 || strcmp(Course, "*") == 0)&&
					(strcmp(crdh->Day, Day) == 0 || strcmp(Day, "*") == 0)
				) {
				found = 1;
				lastLookupIndex = index;
				last_crdh[j] = crdh;
				j++;
				toString_CRDH(crdh);
				crdh = crdh->next;
			}
			else crdh = crdh->next;
		}
		return found;
	}
	}
	else { //Search all buckets if key cannot be used. Could use secondary indexing???
		for(int i=0; i<197; i++){
			TUPLELIST_CRDH crdh = TABLE_CRDH[i];
			if(crdh == NULL) continue;
			else{
				while(crdh != NULL){
					if((strcmp(crdh->Course, Course) == 0 || strcmp(Course, "*") == 0)&&
						(strcmp(crdh->Room, Room) == 0 || strcmp(Room, "*") == 0) &&
					(strcmp(crdh->Day, Day) == 0 || strcmp(Day, "*") == 0) &&
					(strcmp(crdh->Hour, Hour) == 0 || strcmp(Hour, "*") == 0)){
						lastLookupIndex = i;
						found = 1;
						last_crdh[j] = crdh;
						j++;
						toString_CRDH(crdh);
						crdh = crdh->next;
			}
				else crdh = crdh->next;
				}
			}
		}
	}
	return found;
}

int lookup_DH(char * Day, char * Hour){
	int found = 0;
	j = 0;
	//If possible, get key and search that bucket for the tuple quickly
	if(strcmp("*", Day) != 0 && strcmp("*", Hour) != 0){
	char key[strlen(Day)];
	strcpy(key, Day);
	strcat(key, Hour);
	int index = hash(key);
	TUPLELIST_DH dh = TABLE_DH[index];
	
	if(dh == NULL) return 0;
	else {
		while(dh != NULL){
			if((strcmp(dh->Day, Day) == 0 || strcmp(Day, "*") == 0) &&
				(strcmp(dh->Hour, Hour) == 0 || strcmp(Hour, "*") == 0)
				) {
				lastLookupIndex = index;
				last_dh[j] = dh;
				j++;
				toString_DH(dh);
				dh = dh->next;
				found = 1;
			}
			else dh = dh->next;
		}
		return found;
	}
	}
	else { //Search all buckets if key cannot be used. Could use secondary indexing???

		for(int i=0; i<197; i++){
			TUPLELIST_DH dh = TABLE_DH[i];
			if(dh == NULL) continue;
			else{
				while(dh != NULL){
					//printf("HERE!!! Current dh is: \n");
					//toString_DH(dh);
					if((strcmp(dh->Day, Day) == 0 || strcmp(Day, "*") == 0) &&
					(strcmp(dh->Hour, Hour) == 0 || strcmp(Hour, "*") == 0)){
						lastLookupIndex = i;
						last_dh[j] = dh;
						j++;
						toString_DH(dh);
						dh = dh->next;
						found = 1;
			}
				else dh = dh->next;
				}
				
			}
		}
	}
	return found;
}

TUPLELIST_S newS(char * StudentId){ //Create new CSG tuple
	char * S;
		if(strcmp(StudentId, "*") == 0){
			S = (char*) malloc(sizeof(char));
			strcpy(S, "");
		} 
		else {
			S = (char*) malloc(strlen(StudentId) * sizeof(char));
			strcpy(S, StudentId);
		}

	TUPLELIST_S s;
	s = (struct TUPLE_S *) malloc(sizeof(struct TUPLE_S));
	s->StudentId = (char*) malloc(strlen(S)* sizeof(char));
	strcpy(s->StudentId, S);
	s->next = NULL;
	return s;
}

TUPLELIST_CRDH newCRDH(char * Course,char * Room, char * Day, char * Hour){ //Create new CSG tuple
	char * C;
		if(strcmp(Course, "*") == 0){
			C = (char*) malloc(sizeof(char));
			strcpy(C, "");
		} 
		else {
			C = (char*) malloc(strlen(Course) * sizeof(char));
			strcpy(C, Course);
		}
		char * R;
		if(strcmp(Room, "*") == 0){
			R = (char*) malloc(sizeof(char));
			strcpy(R, "");
		} 
		else {
			R = (char*) malloc(strlen(Room) * sizeof(char));
			strcpy(R, Room);
		}
		char * D;
		if(strcmp(Day, "*") == 0){
			D = (char*) malloc(sizeof(char));
			strcpy(D, "");
		} 
		else {
			D = (char*) malloc(strlen(Day) * sizeof(char));
			strcpy(D, Day);
		}
		char * H;
		if(strcmp(Hour, "*") == 0){
			H = (char*) malloc(sizeof(char));
			strcpy(H, "");
		} 
		else {
			H = (char*) malloc(strlen(Hour) * sizeof(char));
			strcpy(H, Hour);
		}

	TUPLELIST_CRDH crdh;
	crdh = (struct TUPLE_CRDH *) malloc(sizeof(struct TUPLE_CRDH));
	crdh->Course = (char*) malloc(strlen(C)* sizeof(char));
	crdh->Room = (char*) malloc(strlen(R)* sizeof(char));
	crdh->Day = (char*) malloc(strlen(D)* sizeof(char));
	crdh->Hour = (char*) malloc((strlen(H))* sizeof(char));
	strcpy(crdh->Course, C);
	strcpy(crdh->Room, R);
	strcpy(crdh->Day, D);
	strcpy(crdh->Hour, H);
	crdh->next = NULL;
	return crdh;
}

TUPLELIST_DH newDH(char * Day, char * Hour){ //Create new CSG tuple
	char * D;
		if(strcmp(Day, "*") == 0){
			D = (char*) malloc(sizeof(char));
			strcpy(D, "");
		} 
		else {
			D = (char*) malloc(strlen(Day) * sizeof(char));
			strcpy(D, Day);
		}
		char * H;
		if(strcmp(Hour, "*") == 0){
			H = (char*) malloc(sizeof(char));
			strcpy(H, "");
		} 
		else {
			H = (char*) malloc(strlen(Hour) * sizeof(char));
			strcpy(H, Hour);
		}

	TUPLELIST_DH dh;
	dh = (struct TUPLE_DH *) malloc(sizeof(struct TUPLE_DH));
	dh->Day = (char*) malloc(strlen(D)* sizeof(char));
	dh->Hour = (char*) malloc(strlen(H)* sizeof(char));
	strcpy(dh->Day, D);
	strcpy(dh->Hour, H);
	dh->next = NULL;
	return dh;
}


void printS(){
	printf("StudentId\n");
		for(int i=0; i<197; i++){
		TUPLELIST_S s = TABLE_S[i];
		if(s == NULL) continue;
		else{
			while(s != NULL){
				toString_S(s);
				s = s->next;
			}
		}
	}
	printf("\n");
}

void printCRDH(){
		printf("Course     Room            Day  Hour\n");
		for(int i=0; i<197; i++){
		TUPLELIST_CRDH crdh = TABLE_CRDH[i];
		if(crdh == NULL) continue;
		else{
			while(crdh != NULL){
				toString_CRDH(crdh);
				crdh = crdh->next;
			}
		}
	}
	printf("\n");

}

void toString_S(TUPLELIST_S s){
	printf("%s\n",s->StudentId);
}


void toString_CRDH(TUPLELIST_CRDH crdh){ //print CSG tuple
	printf("%-10s %-15s %-4s %-2s\n", crdh->Course, crdh->Room, crdh->Day, crdh->Hour);
}

void toString_DH(TUPLELIST_DH dh){ //print CSG tuple
	printf("%s       %s\n", dh->Day, dh->Hour);
}