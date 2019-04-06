/*
 * part_1.c
 *
 *  Created on: Apr 6, 2019
 *      Author: Thabani Dube
 */
//(Course-StudentId-Grade)
typedef struct TUPLE_CSG *TUPLELIST_CSG;
struct TUPLE_CSG {
char Course[6];
char StudentId[8];
char Grade[2];
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

//Hashing function
int hash(char * string);
int string_int(char s[30]); //Function that returns sum of char values of string
//insert functions
void insert_CSG(char Course[6], char StudentId[8], char Grade[2]);
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
int lookup_CSG(char Course[6], char StudentId[8], char Grade[2]);
int lookup_SNAP(char StudentId[8], char Name[30], char Address[50], char Phone[8]);
int lookup_CP(char Course[6], char Prerequisite[6]);
int lookup_CDH(char Course[6], char Day[2], char Hour[4]);
int lookup_CR(char Course[6], char Room[20]);

void insert_CSG(char Course[6], char StudentId[8], char Grade[2]){
	TUPLELIST_CSG csg;
	if(strcmp(Course, "*") == 0)
		strcpy(csg->Course,"");
	else strcpy(csg->Course, Course);
	if(strcmp(StudentId, "*") == 0)
		strcpy(csg->StudentId,"");
	else strcpy(csg->Grade, Grade);
	if(strcmp(Grade, "*") == 0)
		strcpy(csg->Grade,"");
	else strcpy(csg->Grade, Grade);
	//lookup csg. If not found then insert. Otherwise return
}

int lookup_CSG(char Course[6], char StudentId[8], char Grade[2]){ //Key is Course-Student
	//No stars in key comps - get key and search that bucket.
	if(strcmp("*", Course == 0) && )
	//If one of the comps is *, then search all the buckets
	char * key = strcat(Course, StudentId);
	int index = hash(key);

}

int hash(char * string){
	int key = string_int(string);
	return key % 197;
}

int string_int(char * string){
	int len = strlen(string);
	int sum;
	for(int i=0; i<len; i++)
		sum += string[i];
	return sum;
}

