/*
 * part_1.c
 *
 *  Created on: Apr 6, 2019
 *      Author: Thabani Dube
 */
//(Course-StudentId-Grade)
typedef struct TUPLE_CSG *TUPLELIST_CSG; //Primary index on Course-StudentId
struct TUPLE_CSG {
char * Course;
char * StudentId;
char * Grade;
TUPLELIST_CSG next;
};
typedef TUPLELIST_CSG HASHTABLE_CSG[197];

//(StudentId-Name-Address-Phone)
typedef struct TUPLE_SNAP *TUPLELIST_SNAP; //Primary index on StudentId
struct TUPLE_SNAP {
char * StudentId;
char * Name;
char * Address;
char * Phone;
TUPLELIST_SNAP next;
};
typedef TUPLELIST_SNAP HASHTABLE_SNAP[197];

//(Course-Prerequisite)
typedef struct TUPLE_CP *TUPLELIST_CP; //Primary index on Course-Prerequisite
struct TUPLE_CP {
char * Course;
char * Prerequisite;
TUPLELIST_CP next;
};
typedef TUPLELIST_CP HASHTABLE_CP[197];

//(Course-Day-Hour)
typedef struct TUPLE_CDH *TUPLELIST_CDH; //Primary index on Course-Day
struct TUPLE_CDH {
char * Course;
char * Day;
char * Hour;
TUPLELIST_CDH next;
};
typedef TUPLELIST_CDH HASHTABLE_CDH[197];

//(Course-Room)
typedef struct TUPLE_CR *TUPLELIST_CR;
struct TUPLE_CR {
char * Course;
char * Room;
TUPLELIST_CR next;
};
typedef TUPLELIST_CR HASHTABLE_CR[197];

//DATABASE
HASHTABLE_CSG TABLE_CSG;
HASHTABLE_SNAP TABLE_SNAP;
HASHTABLE_CP TABLE_CP;
HASHTABLE_CDH TABLE_CDH;
HASHTABLE_CR TABLE_CR;


int hash(char * key); //function that returns the index of the key
int string_int(char s[30]); //Function that returns sum of char values of string
int lastLookupIndex = 0; //Used in delete fuctions. Reinitialized at beginning of delete by calling lookup
//insert functions
void insert_CSG(char * Course, char * StudentId, char * Grade);
void insert_SNAP(char * StudentId, char * Name, char * Address, char * Phone);
void insert_CP(char * Course, char * Prerequisite);
void insert_CDH(char * Course, char * Day, char * Hour);
void insert_CR(char * Course, char * Room);

//lookup functions
int lookup_CSG(char * Course, char * StudentId, char * Grade);
int lookup_SNAP(char * StudentId, char * Name, char * Address, char * Phone);
int lookup_CP(char * Course, char * Prerequisite);
int lookup_CDH(char * Course, char * Day, char * Hour);
int lookup_CR(char * Course, char * Room);

//delete functions
void delete_CSG(char * Course, char * StudentId, char * Grade);
void delete_SNAP(char * StudentId, char * Name, char * Address, char * Phone);
void delete_CP(char * Course, char * Prerequisite);
void delete_CDH(char * Course, char * Day, char * Hour);
void delete_CR(char * Course, char * Room);



TUPLELIST_CSG newCSG(char * Course, char * StudentId, char * Grade);
TUPLELIST_SNAP newSNAP(char * StudentId, char * Name, char * Address, char * Phone);
TUPLELIST_CP newCP(char * Course, char * Prerequisite);
TUPLELIST_CDH newCDH(char * Course, char * Day, char * Hour);
TUPLELIST_CR newCR(char * Course, char * Room);

//to string of a tuple
void toString_CSG(TUPLELIST_CSG csg);
void toString_SNAP(TUPLELIST_SNAP snap);
void toString_CP(TUPLELIST_CP cp);
void toString_CDH(TUPLELIST_CDH cdh);
void toString_CR(TUPLELIST_CR cr);

void insertALL(); //insert all as for question 3
void printDatabase(); //print all tables in database

//print relation table
void printCSG();
void printSNAP();
void printCP();
void printCDH();
void printCR();

void insert_CSG(char * Course, char * StudentId, char * Grade){
	//Make csg struct and insert if not already there
	int present = lookup_CSG(Course, StudentId, Grade);
	if(!present){
		//insert into hashtable
		TUPLELIST_CSG csg = newCSG(Course,StudentId,Grade);

			char key[strlen(csg->Course)];
			strcpy(key, csg->Course);
			strcat(key, csg->StudentId);
			int index = hash(key);
			TUPLELIST_CSG current = TABLE_CSG[index];
			if(current == NULL) {
				TABLE_CSG[index] = csg;}
			else {
				while(current->next != NULL)
					current = current->next;
				current->next = csg;
			}
	}
	else return;
}

void insert_SNAP(char * StudentId, char * Name, char * Address, char * Phone){
		//Make csg struct and insert if not already there
	int present = lookup_SNAP(StudentId, Name, Address, Phone);
	if(!present){
		//insert into hashtable
		TUPLELIST_SNAP snap = newSNAP(StudentId, Name, Address, Phone);

			char key[strlen(snap->StudentId)];
			strcpy(key, snap->StudentId);
			int index = hash(key);
			TUPLELIST_SNAP current = TABLE_SNAP[index];
			if(current == NULL) {
				TABLE_SNAP[index] = snap;}
			else {
				while(current->next != NULL)
					current = current->next;
				current->next = snap;
			}
	}
	else return;
}

void insert_CP(char * Course, char * Prerequisite){
		//Make csg struct and insert if not already there
	int present = lookup_CP(Course, Prerequisite);
	if(!present){
		//insert into hashtable
		TUPLELIST_CP cp = newCP(Course, Prerequisite);
			char key[strlen(cp->Course)];
			strcpy(key, cp->Course);
			strcat(key, cp->Prerequisite);
			int index = hash(key);
			TUPLELIST_CP current = TABLE_CP[index];
			if(current == NULL) {
				TABLE_CP[index] = cp;}
			else {
				while(current->next != NULL)
					current = current->next;
				current->next = cp;
			}
	}
	else return;
}

void insert_CDH(char * Course, char * Day, char * Hour){
	//Make cdh struct and insert if not already there
	int present = lookup_CDH(Course, Day, Hour);
	if(!present){
		//insert into hashtable
		TUPLELIST_CDH cdh = newCDH(Course,Day,Hour);

			char key[strlen(cdh->Course)];
			strcpy(key, cdh->Course);
			strcat(key, cdh->Day);
			int index = hash(key);
			TUPLELIST_CDH current = TABLE_CDH[index];
			if(current == NULL) {
				TABLE_CDH[index] = cdh;}
			else {
				while(current->next != NULL)
					current = current->next;
				current->next = cdh;
			}
	}
	else return;
}

void insert_CR(char * Course, char * Room){
		//Make csg struct and insert if not already there
	int present = lookup_CP(Course, Room);
	if(!present){
		//insert into hashtable
		TUPLELIST_CR cr = newCR(Course, Room);
			char key[strlen(cr->Course)];
			strcpy(key, cr->Course);
			strcat(key, cr->Room);
			int index = hash(key);
			TUPLELIST_CR current = TABLE_CR[index];
			if(current == NULL) {
				TABLE_CR[index] = cr;}
			else {
				while(current->next != NULL)
					current = current->next;
				current->next = cr;
			}
	}
	else return;
}

int lookup_CSG(char * Course, char * StudentId, char * Grade){ //Key is Course-Student
	//If possible, get key and search that bucket for the tuple quickly
	if(strcmp("*", Course) != 0 && strcmp("*", StudentId) != 0){
	char key[strlen(Course)];
	strcpy(key, Course);
	strcat(key, StudentId);
	int index = hash(key);
	TUPLELIST_CSG csg = TABLE_CSG[index];
	if(csg == NULL) return 0;
	else {
		while(csg != NULL){
			if(strcmp(csg->Grade, Grade) == 0 || strcmp(Grade, "*") == 0) {
				lastLookupIndex = index;
				return 1;}
			else csg = csg->next;
		}
		return 0;
	}
	}
	else { //Search all buckets if key cannot be used. Could use secondary indexing???
		for(int i=0; i<197; i++){
			TUPLELIST_CSG csg = TABLE_CSG[i];
			if(csg == NULL) continue;
			else{
				while(csg != NULL){
					if((strcmp(csg->Course, Course) == 0 || strcmp(Course, "*") == 0)&&
					(strcmp(csg->StudentId, StudentId) == 0 || strcmp(StudentId, "*") == 0) &&
					(strcmp(csg->Grade, Grade) == 0 || strcmp(Grade, "*") == 0)){
						lastLookupIndex = i;
					return 1;
			}
				else csg = csg->next;
				}
				return 0;
			}
		}
	}  

}

int lookup_CDH(char * Course, char * Day, char * Hour){ 
	//If possible, get key and search that bucket for the tuple quickly
	if(strcmp("*", Course) != 0 && strcmp("*", Day) != 0){
	char key[strlen(Course)];
	strcpy(key, Course);
	strcat(key, Day);
	int index = hash(key);
	TUPLELIST_CDH cdh = TABLE_CDH[index];
	if(cdh == NULL) return 0;
	else {
		while(cdh != NULL){
			if(strcmp(cdh->Hour, Hour) == 0 || strcmp(Hour, "*") == 0) {
				lastLookupIndex = index;
				return 1;}
			else cdh = cdh->next;
		}
		return 0;
	}
	}
	else { //Search all buckets if key cannot be used. Could use secondary indexing???
		for(int i=0; i<197; i++){
			TUPLELIST_CDH cdh = TABLE_CDH[i];
			if(cdh == NULL) continue;
			else{
				while(cdh != NULL){
					if((strcmp(cdh->Course, Course) == 0 || strcmp(Course, "*") == 0)&&
					(strcmp(cdh->Day, Day) == 0 || strcmp(Day, "*") == 0) &&
					(strcmp(cdh->Hour, Hour) == 0 || strcmp(Hour, "*") == 0)){
						lastLookupIndex = i;
					return 1;
			}
				else cdh = cdh->next;
				}
				return 0;
			}
		}
	}  

}

int lookup_SNAP(char * StudentId, char * Name, char * Address, char * Phone){
		//If possible, get key and search that bucket for the tuple quickly
	if(strcmp("*", StudentId) != 0){
	char key[strlen(StudentId)];
	strcpy(key, StudentId);
	int index = hash(key);
	TUPLELIST_SNAP snap = TABLE_SNAP[index];
	if(snap == NULL) return 0;
	else {
		while(snap != NULL){
			if((strcmp(snap->Name, Name) == 0 || strcmp(Name, "*") == 0) &&
				(strcmp(snap->Address, Address) == 0 || strcmp(Address, "*") == 0) &&
				(strcmp(snap->Phone, Phone) == 0 || strcmp(Phone, "*") == 0)
				) {
				lastLookupIndex = index;
				return 1;}
			else snap = snap->next;
		}
		return 0;
	}
	}
	else { //Search all buckets if key cannot be used. Could use secondary indexing???
		for(int i=0; i<197; i++){
			TUPLELIST_SNAP snap = TABLE_SNAP[i];
			if(snap == NULL) continue;
			else{
				while(snap != NULL){
					if((strcmp(snap->StudentId, StudentId) == 0 || strcmp(StudentId, "*") == 0)&&
					(strcmp(snap->Name, Name) == 0 || strcmp(Name, "*") == 0) &&
					(strcmp(snap->Address, Address) == 0 || strcmp(Address, "*") == 0) &&
					(strcmp(snap->Phone, Phone) == 0 || strcmp(Phone, "*") == 0)){
						lastLookupIndex = i;
					return 1;
			}
				else snap = snap->next;
				}
				return 0;
			}
		}
	}
}

int lookup_CP(char * Course, char * Prerequisite){
		//If possible, get key and search that bucket for the tuple quickly
	if(strcmp("*", Course) != 0 && strcmp("*", Prerequisite) != 0){
	char key[strlen(Course)];
	strcpy(key, Course);
	strcat(key, Prerequisite);
	int index = hash(key);
	TUPLELIST_CP cp = TABLE_CP[index];
	if(cp == NULL) return 0;
	else {
		while(cp != NULL){
			if((strcmp(cp->Course, Course) == 0 || strcmp(Course, "*") == 0) &&
				(strcmp(cp->Prerequisite, Prerequisite) == 0 || strcmp(Prerequisite, "*") == 0)
				) {
				lastLookupIndex = index;
				return 1;}
			else cp = cp->next;
		}
		return 0;
	}
	}
	else { //Search all buckets if key cannot be used. Could use secondary indexing???
		for(int i=0; i<197; i++){
			TUPLELIST_CP cp = TABLE_CP[i];
			if(cp == NULL) continue;
			else{
				while(cp != NULL){
					if((strcmp(cp->Course, Course) == 0 || strcmp(Course, "*") == 0) &&
					(strcmp(cp->Prerequisite, Prerequisite) == 0 || strcmp(Prerequisite, "*") == 0)){
						lastLookupIndex = i;
					return 1;
			}
				else cp = cp->next;
				}
				return 0;
			}
		}
	}
}

int lookup_CR(char * Course, char * Room){
	//If possible, get key and search that bucket for the tuple quickly
	if(strcmp("*", Course) != 0 && strcmp("*", Room) != 0){
	char key[strlen(Course)];
	strcpy(key, Course);
	strcat(key, Room);
	int index = hash(key);
	TUPLELIST_CR cr = TABLE_CR[index];
	if(cr == NULL) return 0;
	else {
		while(cr != NULL){
			if((strcmp(cr->Course, Course) == 0 || strcmp(Course, "*") == 0) &&
				(strcmp(cr->Room, Room) == 0 || strcmp(Room, "*") == 0)
				) {
				lastLookupIndex = index;
				return 1;}
			else cr = cr->next;
		}
		return 0;
	}
	}
	else { //Search all buckets if key cannot be used. Could use secondary indexing???
		for(int i=0; i<197; i++){
			TUPLELIST_CR cr = TABLE_CR[i];
			if(cr == NULL) continue;
			else{
				while(cr != NULL){
					if((strcmp(cr->Course, Course) == 0 || strcmp(Course, "*") == 0) &&
					(strcmp(cr->Room, Room) == 0 || strcmp(Room, "*") == 0)){
						lastLookupIndex = i;
					return 1;
			}
				else cr = cr->next;
				}
				return 0;
			}
		}
	}
}

void delete_CSG(char * Course, char * StudentId, char * Grade){
	int present = lookup_CSG(Course,StudentId,Grade);
	if(!present) return;
	else{
		TUPLELIST_CSG * csgPtr = &(TABLE_CSG[lastLookupIndex]);
		while((*csgPtr) != NULL){
			printf("HERE\n");
			if((strcmp((*csgPtr)->Course, Course) == 0 || strcmp(Course, "*") == 0)&&
					(strcmp((*csgPtr)->StudentId, StudentId) == 0 || strcmp(StudentId, "*") == 0) &&
					(strcmp((*csgPtr)->Grade, Grade) == 0 || strcmp(Grade, "*") == 0)){
					(*csgPtr) = NULL; //Potential memory fee needed??
					return;
		}
		csgPtr = &((*csgPtr)->next);

	}
}
}

void delete_SNAP(char * StudentId, char * Name, char * Address, char * Phone){
	int present = lookup_SNAP(StudentId,Name,Address,Phone);
	if(!present) return;
	else{
		TUPLELIST_SNAP * snapPtr = &(TABLE_SNAP[lastLookupIndex]);
		while((*snapPtr) != NULL){
			if((strcmp((*snapPtr)->StudentId, StudentId) == 0 || strcmp(StudentId, "*") == 0)&&
					(strcmp((*snapPtr)->Name, Name) == 0 || strcmp(Name, "*") == 0) &&
					(strcmp((*snapPtr)->Address, Address) == 0 || strcmp(Address, "*") == 0)){
					(*snapPtr) = NULL; //Potential memory fee needed??
					return;
		}
		snapPtr = &((*snapPtr)->next);

	}
}
}

void delete_CP(char * Course, char * Prerequisite){
	int present = lookup_CP(Course, Prerequisite);
	if(!present) return;
	else{
		TUPLELIST_CP * cpPtr = &(TABLE_CP[lastLookupIndex]);
		while((*cpPtr) != NULL){
			if((strcmp((*cpPtr)->Course, Course) == 0 || strcmp(Course, "*") == 0)&&
					(strcmp((*cpPtr)->Prerequisite, Prerequisite) == 0 || strcmp(Prerequisite, "*") == 0)){
					(*cpPtr) = NULL; //Potential memory fee needed??
					return;
		}
		cpPtr = &((*cpPtr)->next);

	}
}
}

void delete_CDH(char * Course, char * Day, char * Hour){
	int present = lookup_CDH(Course,Day,Hour);
	if(!present) return;
	else{
		TUPLELIST_CDH * cdhPtr = &(TABLE_CDH[lastLookupIndex]);
		while((*cdhPtr) != NULL){
			if((strcmp((*cdhPtr)->Course, Course) == 0 || strcmp(Course, "*") == 0)&&
					(strcmp((*cdhPtr)->Day, Day) == 0 || strcmp(Day, "*") == 0) &&
					(strcmp((*cdhPtr)->Hour, Hour) == 0 || strcmp(Hour, "*") == 0)){
					(*cdhPtr) = NULL; //Potential memory fee needed??
					return;
		}
		cdhPtr = &((*cdhPtr)->next);

	}
}
}

void delete_CR(char * Course, char * Room){
	int present = lookup_CR(Course, Room);
	if(!present) return;
	else{
		TUPLELIST_CR * crPtr = &(TABLE_CR[lastLookupIndex]);
		while((*crPtr) != NULL){
			if((strcmp((*crPtr)->Course, Course) == 0 || strcmp(Course, "*") == 0)&&
					(strcmp((*crPtr)->Room, Room) == 0 || strcmp(Room, "*") == 0)){
					(*crPtr) = NULL; //Potential memory fee needed??
					return;
		}
		crPtr = &((*crPtr)->next);

	}
}
}

TUPLELIST_CSG newCSG(char * Course, char * StudentId, char * Grade){ //Create new CSG tuple
	char * C;
		if(strcmp(Course, "*") == 0){
			C = (char*) malloc(sizeof(char));
			strcpy(C, "");
		} 
		else {
			C = (char*) malloc(strlen(Course) * sizeof(char));
			strcpy(C, Course);
		}
		char * S;
		if(strcmp(StudentId, "*") == 0){
			S = (char*) malloc(sizeof(char));
			strcpy(S, "");
		} 
		else {
			S = (char*) malloc(strlen(StudentId) * sizeof(char));
			strcpy(S, StudentId);
		}
		char * G;
		if(strcmp(Grade, "*") == 0){
			G = (char*) malloc(sizeof(char));
			strcpy(G, "");
		} 
		else {
			G = (char*) malloc(strlen(Grade) * sizeof(char));
			strcpy(G, Grade);
		}

	TUPLELIST_CSG csg;
	csg = (struct TUPLE_CSG *) malloc(sizeof(struct TUPLE_CSG));
	csg->Course = (char*) malloc(strlen(C)* sizeof(char));
	csg->StudentId = (char*) malloc(strlen(S)* sizeof(char));
	csg->Grade = (char*) malloc((strlen(G))* sizeof(char));
	strcpy(csg->Course, C);
	strcpy(csg->StudentId, S);
	strcpy(csg->Grade, G);
	csg->next = NULL;
	return csg;
}

TUPLELIST_SNAP newSNAP(char * StudentId, char * Name, char * Address, char * Phone){
		char * S;
		if(strcmp(StudentId, "*") == 0){
			S = (char*) malloc(sizeof(char));
			strcpy(S, "");
		} 
		else {
			S = (char*) malloc(strlen(StudentId) * sizeof(char));
			strcpy(S, StudentId);
		}
		char * N;
		if(strcmp(Name, "*") == 0){
			N = (char*) malloc(sizeof(char));
			strcpy(N, "");
		} 
		else {
			N = (char*) malloc(strlen(Name) * sizeof(char));
			strcpy(N, Name);
		}
		char * A;
		if(strcmp(Address, "*") == 0){
			A = (char*) malloc(sizeof(char));
			strcpy(A, "");
		} 
		else {
			A = (char*) malloc(strlen(Address) * sizeof(char));
			strcpy(A, Address);
		}
		char * P;
		if(strcmp(Phone, "*") == 0){
			P = (char*) malloc(sizeof(char));
			strcpy(P, "");
		} 
		else {
			P = (char*) malloc(strlen(Phone) * sizeof(char));
			strcpy(P, Phone);
		}

	TUPLELIST_SNAP snap;
	snap = (struct TUPLE_SNAP *) malloc(sizeof(struct TUPLE_SNAP));
	snap->StudentId = (char*) malloc(strlen(S)* sizeof(char));
	snap->Name = (char*) malloc(strlen(N)* sizeof(char));
	snap->Address = (char*) malloc((strlen(A))* sizeof(char));
	snap->Phone = (char*) malloc((strlen(P))* sizeof(char));
	strcpy(snap->StudentId, S);
	strcpy(snap->Name, N);
	strcpy(snap->Address, A);
	strcpy(snap->Phone, P);
	snap->next = NULL;
	return snap;
}

TUPLELIST_CP newCP(char * Course, char * Prerequisite){ //Create new CSG tuple
	char * C;
		if(strcmp(Course, "*") == 0){
			C = (char*) malloc(sizeof(char));
			strcpy(C, "");
		} 
		else {
			C = (char*) malloc(strlen(Course) * sizeof(char));
			strcpy(C, Course);
		}
		char * P;
		if(strcmp(Prerequisite, "*") == 0){
			P = (char*) malloc(sizeof(char));
			strcpy(P, "");
		} 
		else {
			P = (char*) malloc(strlen(Prerequisite) * sizeof(char));
			strcpy(P, Prerequisite);
		}

	TUPLELIST_CP cp;
	cp = (struct TUPLE_CP *) malloc(sizeof(struct TUPLE_CP));
	cp->Course = (char*) malloc(strlen(C)* sizeof(char));
	cp->Prerequisite = (char*) malloc(strlen(P)* sizeof(char));
	strcpy(cp->Course, C);
	strcpy(cp->Prerequisite, P);
	cp->next = NULL;
	return cp;
}

TUPLELIST_CDH newCDH(char * Course, char * Day, char * Hour){ //Create new CSG tuple
	char * C;
		if(strcmp(Course, "*") == 0){
			C = (char*) malloc(sizeof(char));
			strcpy(C, "");
		} 
		else {
			C = (char*) malloc(strlen(Course) * sizeof(char));
			strcpy(C, Course);
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

	TUPLELIST_CDH cdh;
	cdh = (struct TUPLE_CDH *) malloc(sizeof(struct TUPLE_CDH));
	cdh->Course = (char*) malloc(strlen(C)* sizeof(char));
	cdh->Day = (char*) malloc(strlen(D)* sizeof(char));
	cdh->Hour = (char*) malloc((strlen(H))* sizeof(char));
	strcpy(cdh->Course, C);
	strcpy(cdh->Day, D);
	strcpy(cdh->Hour, H);
	cdh->next = NULL;
	return cdh;
}

TUPLELIST_CR newCR(char * Course, char * Room){ //Create new CSG tuple
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

	TUPLELIST_CR cr;
	cr = (struct TUPLE_CR *) malloc(sizeof(struct TUPLE_CR));
	cr->Course = (char*) malloc(strlen(C)* sizeof(char));
	cr->Room = (char*) malloc(strlen(R)* sizeof(char));
	strcpy(cr->Course, C);
	strcpy(cr->Room, R);
	cr->next = NULL;
	return cr;
}

void toString_CSG(TUPLELIST_CSG csg){ //print CSG tuple
	printf("%s      %s          %s  \n", csg->Course, csg->StudentId, csg->Grade);
}

void toString_SNAP(TUPLELIST_SNAP snap){ //print CSG tuple
	printf("%-20s %-20s %-20s %-20s  \n", snap->StudentId, snap->Name, snap->Address, snap->Phone);
}

void toString_CP(TUPLELIST_CP cp){ //print CSG tuple
	printf("%s       %s\n", cp->Course, cp->Prerequisite);
}

void toString_CDH(TUPLELIST_CDH cdh){ //print CSG tuple
	printf("%-8s %-4s %-4s\n", cdh->Course, cdh->Day, cdh->Hour);
}

void toString_CR(TUPLELIST_CR cr){ //print CSG tuple
	printf("%s       %s\n", cr->Course, cr->Room);
}

int hash(char * key){ //function that returns the index of the key
	int index = string_int(key);
	return index % 197;
}

int string_int(char * string){ //Function that returns sum of chars in string
	int len = strlen(string);
	int sum = 0;
	for(int i=0; i<len; i++)
		sum += string[i];
	return sum;
}

void insertALL(){
	//CSG
	insert_CSG("CS101", "12345", "A");
	insert_CSG("CS101", "67890", "B");
	insert_CSG("EE200", "12345", "C");
	insert_CSG("EE200", "22222", "B+");
	insert_CSG("CS101", "33333", "A-");
	insert_CSG("PH100", "67890", "C+");

	//SNAP
	insert_SNAP("12345", "C. Brown", "12 Apple St.", "555-1234");
	insert_SNAP("67890", "L. Van Pelt", "34 Pear Ave.", "555-5678");
	insert_SNAP("22222", "P. Patty", "56 Grape Blvd.", "555-9999");

	//CP
	insert_CP("CS101", "CS100");
	insert_CP("EE200", "EE005");
	insert_CP("EE200", "CS100");
	insert_CP("CS120", "CS101");
	insert_CP("CS121", "CS120");
	insert_CP("CS205", "CS101");
	insert_CP("CS206", "CS121");
	insert_CP("CS206", "CS205");

	//CDH
	insert_CDH("CS101", "M", "9AM");
	insert_CDH("CS101", "W", "9AM");
	insert_CDH("CS101", "F", "9AM");
	insert_CDH("EE200", "Tu", "10AM");
	insert_CDH("EE200", "W", "1PM");
	insert_CDH("EE200", "Th", "10AM");

	//CR
	insert_CR("CS101", "Turing Aud.");
	insert_CR("EE200", "25 Ohm Hall");
	insert_CR("PH100", "Newton Lab.");

}

void printDatabase(){
	printCSG();
	printSNAP();
	printCP();
	printCDH();
	printCR();
}

void printCSG(){
	printf("Course     StudentId      Grade\n");
		for(int i=0; i<197; i++){
		TUPLELIST_CSG csg = TABLE_CSG[i];
		if(csg == NULL) continue;
		else{
			while(csg != NULL){
				toString_CSG(csg);
				csg = csg->next;
			}
		}
	}
	printf("\n");
}

void printSNAP(){
	printf("StudentId            Name                  Address              Phone\n");
		for(int i=0; i<197; i++){
		TUPLELIST_SNAP snap = TABLE_SNAP[i];
		if(snap == NULL) continue;
		else{
			while(snap != NULL){
				toString_SNAP(snap);
				snap = snap->next;
			}
		}
	}
	printf("\n");
}

void printCP(){
	printf("Course      Prerequisite\n");
		for(int i=0; i<197; i++){
		TUPLELIST_CP cp = TABLE_CP[i];
		if(cp == NULL) continue;
		else{
			while(cp != NULL){
				toString_CP(cp);
				cp = cp->next;
			}
		}
	}
	printf("\n");
}

void printCDH(){
		printf("Course   Day  Hour\n");
		for(int i=0; i<197; i++){
		TUPLELIST_CDH cdh = TABLE_CDH[i];
		if(cdh == NULL) continue;
		else{
			while(cdh != NULL){
				toString_CDH(cdh);
				cdh = cdh->next;
			}
		}
	}
	printf("\n");

}

void printCR(){
	printf("Course      Room\n");
		for(int i=0; i<197; i++){
		TUPLELIST_CR cr = TABLE_CR[i];
		if(cr == NULL) continue;
		else{
			while(cr != NULL){
				toString_CR(cr);
				cr = cr->next;
			}
		}
	}
	printf("\n");
}