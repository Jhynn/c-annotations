/*
#include <stdio.h>

#define name(s) #s

int
main(int argc, char const *argv[]) {
    char* p      = "String";
    char str[10] = "String";

    printf("The size is %lu Bytes.\n", sizeof(str));
    printf("The size is %lu Bytes.\n", sizeof(p));

    const char *geek = "Geek";
    printf("Size of %s is %lu Bytes.\n", name(geek), sizeof(geek));

    return 0;
}
*/

// C program for variable length members in structures in GCC before C99.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A structure of type student.
struct student {
    int stud_id;
    int name_len;
    int struct_size;
    char stud_name[0]; // Variable length array must be last.
};

// Memory allocation and initialisation of structure.
struct student*
createStudent(struct student *s, int id, char a[]) {
	s = malloc(sizeof(*s) + sizeof(char) * strlen(a));

	s->stud_id = id;
	s->name_len = strlen(a);
	strcpy(s->stud_name, a);

	s->struct_size = (sizeof(*s) + sizeof(char) * strlen(s->stud_name));

	return s;
}

void
printStudent(struct student *s) {
    printf("Student_id...........: %d\n"
    	    "Stud_Name............: %s\n"
    	    "Name_Length..........: %d\n"
    	    "Allocated_Struct_size: %d\n\n",
    	    s->stud_id, s->stud_name, s->name_len, s->struct_size);

    		// Value of Allocated_Struct_size here is in bytes.
}

int
main() {
	struct student *s1, *s2;

	s1 = createStudent(s1, 523, "Sanjayulsha");
	s2 = createStudent(s2, 535, "Cherry");

	printStudent(s1);
	printStudent(s2);

	// Size in bytes.
	printf("Size of Struct student: %lu\n", sizeof(struct student));
	// Size in bytes.
	printf("Size of Struct pointer: %lu\n", sizeof(s1));

	return 0;
}
