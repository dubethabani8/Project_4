/*
 * part_1.c
 *
 *  Created on: Apr 6, 2019
 *      Author: Thabani Dube
 */
//(Course-StudentId-Grade)
typedef struct TUPLE_CSG *TUPLELIST_CSG;
struct TUPLE_CSG {
char * Course;
char * StudentId;
char * Grade;
TUPLELIST_CSG next;
};
typedef TUPLELIST_CSG HASHTABLE_CSG[197];

//(StudentId-Name-Address-Phone)
typedef struct TUPLE_SNAP *TUPLELIST_SNAP;
struct TUPLE_SNAP {
char StudentId[8];
char Name[30];
char Address[50];
char Phone[8];
TUPLELIST_SNAP next;
};
typedef TUPLELIST_SNAP HASHTABLE_SNAP[197];

//(Course-Prerequisite)
typedef struct TUPLE_CP *TUPLELIST_CP;
struct TUPLE_CP {
char Course[6];
char Prerequisite[6];
TUPLELIST_CP next;
};
typedef TUPLELIST_CP HASHTABLE_CP[197];

//(Course-Day-Hour)
typedef struct TUPLE_CDH *TUPLELIST_CDH;
struct TUPLE_CDH {
char Course[6];
char Day[2];
char Hour[4];
TUPLELIST_CDH next;
};
typedef TUPLELIST_CDH HASHTABLE_CDH[197];

//(Course-Room)
typedef struct TUPLE_CR *TUPLELIST_CR;
struct TUPLE_CR {
char Course[6];
char Room[20];
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
//insert functions
void insert_CSG(char * Course, char * StudentId, char * Grade);
void insert_SNAP(char StudentId[8], char Name[30], char Address[50], char Phone[8]);
void insert_CP(char Course[6], char Prerequisite[6]);
void insert_CDH(char Course[6], char Day[2], char Hour[4]);
void insert_CR(char Course[6], char Room[20]);

//delete functions
void delete_CSG(char Course[6], char StudentId[8], char Grade[2]);
void delete_SNAP(char StudentId[8], char Name[30], char Address[50], char Phone[8]);
void delete_CP(char Course[6], char Prerequisite[6]);
void delete_CDH(char Course[6], char Day[2], char Hour[4]);
void delete_CR(char Course[6], char Room[20]);

//lookup functions
int lookup_CSG(char * Course, char * StudentId, char * Grade);
int lookup_SNAP(char StudentId[8], char Name[30], char Address[50], char Phone[8]);
int lookup_CP(char Course[6], char Prerequisite[6]);
int lookup_CDH(char Course[6], char Day[2], char Hour[4]);
int lookup_CR(char Course[6], char Room[20]);

void toString_CSG(TUPLELIST_CSG csg);


void insert_CSG(char * Course, char * StudentId, char * Grade){
	//Make csg struct and insert if not already there
	int present = lookup_CSG(Course, StudentId, Grade);
	if(!present){
		//insert into hashtable
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
			if(strcmp(csg->Grade, Grade) == 0) return 1;
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
					(strcmp(csg->Grade, Grade) == 0 || strcmp(Grade, "*") == 0))
					return 1;
				else csg = csg->next;
				}
				return 0;
			}
		}
	}  

}

int hash(char * key){ //function that returns the index of the key
	int index = string_int(key);
	return index % 197;
}

int string_int(char * string){ //Function that returns sum of chars in string
	int len = strlen(string);
	int sum;
	for(int i=0; i<len; i++)
		sum += string[i];
	return sum;
}

TUPLELIST_CSG newCSG(char * Course, char * StudentId, char * Grade){ //Create new CSG tuple
	TUPLELIST_CSG csg;
	csg = (struct TUPLE_CSG *) malloc(sizeof(struct TUPLE_CSG));
	csg->Course = (char*) malloc(strlen(Course)* sizeof(char));
	csg->StudentId = (char*) malloc(strlen(StudentId)* sizeof(char));
	csg->Grade = (char*) malloc((strlen(Grade))* sizeof(char));
	strcpy(csg->Course, Course);
	strcpy(csg->StudentId, StudentId);
	strcpy(csg->Grade, Grade);
	csg->next = NULL;
	return csg;
}

void toString_CSG(TUPLELIST_CSG csg){ //print CSG tuple
	printf("|Course: %s | StudentId: %s | Grade: %s|\n", csg->Course, csg->StudentId, csg->Grade);
}