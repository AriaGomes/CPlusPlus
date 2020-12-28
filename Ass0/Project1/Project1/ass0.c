/************************************************
Filename:				ass0.c
Version:				1.0
Author:					Aria Gomes
Assignment Number:		0
Assignment Name:		Animation Project in C
Course Name:			C++
Course Code:			CST219
Lab Section Number:		303
Professor's Name:		Surbhi Bahri
Due Date:				2020/01/28
Submission Date:		2020/01/28
List of source files:	ass0.c
Purpose: To review C concepts such as structs, macros, pointers etc.
The Program adds "Frames"(nodes) to the begining to a singly linked list
using two structures with the ability to Edit, Report(Print) the animation,
Delete the last "frame"(tail/node) and also quit without any memory leaks.
**************************************************/
//Untouched code//
// ass0.c
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>
#include <stdio.h>
#include <string.h>

typedef enum { FALSE = 0, TRUE } BOOL;

struct Frame 
{
	char* frameName;
	struct Frame* pNext;
};

typedef struct {
	char* animationName;
	struct Frame* frames;
}Animation;

// Forward declarations
void InitAnimation(Animation*);
void InsertFrame(Animation*);
void DeleteFrame(Animation*);
void EditFrame(Animation*);
void ReportAnimation(Animation*);
void CleanUp(Animation*);
/*********************************************************************
Filename:			   ass0.c
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   0
Assignment name :	   Animation Project in C
Date :			       January 28 2020
Submission Date :	   January 28 2020
Professor :			   Surbhi Bahri
Purpose :			   Initialize the Animation and Frames structs dynamically and get the
					   name of the animation from the user
***********************************************************************/
/*********************************************************************
Filename:			   ass0.c
Author :			   Aria Gomes No : 040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   0
Assignment name :	   Animation Project in C
Date :			       January 28 2020
Submission Date :	   January 28 2020
Professor :			   Surbhi Bahri
Purpose :			   Main menu of the animation, detailing the functions of the program
***********************************************************************/
int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	Animation RG;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	InitAnimation(&RG);

	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit\n"); scanf("%c", &response);
		switch (response)
		{
		case '1':InsertFrame(&RG); break;
		case '2':DeleteFrame(&RG); break;
		case '3':EditFrame(&RG); break;
		case '4':ReportAnimation(&RG); break;
		case '5':RUNNING = FALSE; CleanUp(&RG); break;
		default:printf("Please enter a valid option\n");
		}
	}
	return 0;
}
//Untouched code//
//MY ADDED CODE STARTS HERE

/*********************************************************************
Filename:			   ass0.c    
Author :			   Aria Gomes No : 040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   0
Assignment name :	   Animation Project in C
Date :			       January 28 2020
Submission Date :	   January 28 2020
Professor :			   Surbhi Bahri
Purpose :			   Initialize the Animation and Frames structs dynamically and get the 
					   name of the animation from the user
***********************************************************************/
void InitAnimation(Animation* anm)
{
	char n;
	char* name = malloc(100 * sizeof(char));

	// get animation name from user
	printf("Please Enter the Animation Name: ");
	int p = scanf("%s", name);
	n = getchar();

	//allocate size for the name
	anm->animationName = malloc(strlen(name) * sizeof(char) + 1);
	strcpy(anm->animationName, name);// assign animation name for the structure

	anm->frames = NULL; // Initialize the frames to NULL for further use
	free(name);
	fseek(stdin,0, SEEK_END);
}

/*********************************************************************
Filename:			   ass0.c
Author :			   Aria Gomes No : 040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   0
Assignment name :	   Animation Project in C
Date :			       January 28 2020
Submission Date :	   January 28 2020
Professor :			   Surbhi Bahri
Purpose :			   Insert a "Frame"(node) to the front of the Linked List
data structure by itterating through it using  loops and temporary struct variables
***********************************************************************/
void InsertFrame(Animation* anm)
{
	struct Frame* head = malloc(sizeof(struct Frame));
	char n;
	char* frameName = malloc(100 * sizeof(char)); // Declaration of temporary varaibles allocated to sizes needed for further use

	printf("Please enter the Frame frameName: "); // Getting the new frame name from the user
	int p = scanf("%s", frameName);
	n = getchar();

	head->frameName = malloc(strlen(frameName) * sizeof(char) + 1);
	strcpy(head->frameName, frameName); // Copying the name from the temporary variable to the structure variable
	
	head->pNext = anm->frames; //Sets the current state of the animation after the node of temporary struct
	anm->frames = head; // replaces the animation frames with the temporary struct varaible(adding the node to the head)
	free(frameName);
	fseek(stdin, 0, SEEK_END);
}

/*********************************************************************
Filename:			   ass0.c
Author :			   Aria Gomes No : 040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   0
Assignment name :	   Animation Project in C
Date :			       January 28 2020
Submission Date :	   January 28 2020
Professor :			   Surbhi Bahri
Purpose :			   Deletes the last "Frame"(node/tail) by itterating through the
Linked list data structure and finding the last node and NULLing its data
***********************************************************************/
void DeleteFrame(Animation* anm)
{
	char n = getchar();
	struct Frame* head = anm->frames;
	struct Frame* temp;

	// If there are no Frames, return
	if (head == NULL)
	{
		printf("No Frames to delete!\n");
		fseek(stdin, 0, SEEK_END);
		return;
	}

	// the next frame is null so delete current frame
	if (head->pNext != NULL)
		temp = head->pNext;
	else { // clear only the last frame frame
		free(head->frameName);
		free(head);
		head = NULL;// clears the data in the tail
		anm->frames = NULL;
		return;
	}

	// itterate through the linked list in a loop to the last frame
	while (temp->pNext != NULL) {
		head = temp;
		temp = temp->pNext;
	}

	//Reassigns the temporary head pointer to avoid crashing
	if (head != NULL)
		head->pNext = NULL;

	free(temp->frameName);
	free(temp);
	fseek(stdin, 0, SEEK_END);
}

/*********************************************************************
Filename:			   ass0.c
Author :			   Aria Gomes No : 040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   0
Assignment name :	   Animation Project in C
Date :			       January 28 2020
Submission Date :	   January 28 2020
Professor :			   Surbhi Bahri
Purpose :			   Edit a "Frame"(node) at any given index of the Linked List
data structure by getting user input itterating through it using a for loop and 
temporary struct variables until that index is reached and editing the data at the
given node. This function also reports the data at the node before the user edits the
node.
***********************************************************************/
void EditFrame(Animation* anm)
{
	char n = getchar();
	int i = 1, index = 1;
	char* frameName = malloc(100 * sizeof(char));
	struct Frame* temp = anm->frames;

	// make sure there are frmaes to edit (Error detection)
	if (temp == NULL) {
		printf("No Frames to edit!\n");
		fseek(stdin, 0, SEEK_END);
		return;
	}

	// move to last frame
	while (temp->pNext != NULL) {
		temp = temp->pNext;
		i++;
	}

	// ask the user which frame to edit according to index
	printf("There are %d Frame(s) in the list. Please specify the index (<=0) to edit at: ", i);
	while (scanf(" %d", &index) != 1) {
		printf("Enter a valid number: ");
		n = getchar();
	}
	n = getchar();

	// check for valid range
	if ((index < 0) || (index >= i)) {
		printf("Invalid Range! Returning to menu!\n");
		return;
	}

	// move to indexed frame
	temp = anm->frames;
	for (i = 0; i < index; i++) {
		temp = temp->pNext;
	}

	// get frame name 
	printf("The name of this Frame is %s. What do you wish to replace it with? ", temp->frameName);
	int p = scanf("%s", frameName);
	n = getchar();

	// reallocate frameName
	free(temp->frameName);
	temp->frameName = malloc(strlen(frameName) * sizeof(char) + 1);

	// move new name over from the temporary variable
	strcpy(temp->frameName, frameName);
	free(frameName);
	fseek(stdin, 0, SEEK_END); 
}

/*********************************************************************
Filename:			   ass0.c
Author :			   Aria Gomes No : 040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   0
Assignment name :	   Animation Project in C
Date :			       January 28 2020
Submission Date :	   January 28 2020
Professor :			   Surbhi Bahri
Purpose :			   Prints(Reports) all "Frames"(nodes) to the of the Linked List
data structure by itterating through it using a loop and temporary struct variables in
a human readable format Eg.(#1, frame name = a).
***********************************************************************/
void ReportAnimation(Animation* anm)
{
	struct Frame* current;
	int count; // Declaration needed to manioulate and Itterate through the Linked List Data Structure

	if (!anm)
		return;

	printf("Animation name is %s\n", anm->animationName);
	printf("Report the animation\n"); // Reports the name of the animation with the description of this menu

	current = anm->frames;
	count = 0;
	if (!current) // Iterates through the Linked list and checks if the data structure does not contains any frames
	{
		printf("There are no frame(s) inside the Animation\n");
		fseek(stdin, 0, SEEK_END);
		return;
	}

	while (current != NULL) //Iterates throught the Linked list and checks if the data structure contains any frames
	{
		printf("Frame #%d, frame name = %s\n", count, current->frameName); // Prints the frames in human readable format with the numeber of frames first and then the frame names after Eg.(#1, frame name = a)
		count++; //increments the counter variable
		current = current->pNext; //sets the current node to be looked at to the next node in the data structure
	}
	fseek(stdin, 0, SEEK_END);
}

/*********************************************************************
Filename:			   ass0.c
Author :			   Aria Gomes No : 040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   0
Assignment name :	   Animation Project in C
Date :			       January 28 2020
Submission Date :	   January 28 2020
Professor :			   Surbhi Bahri
Purpose :			   Frees the memory for all dynamically allocated memory
used by the program to avoid memory leaks using the free command before program exits.
***********************************************************************/
void CleanUp(Animation* anm)
{
	struct Frame* head = anm->frames;
	struct Frame* temp = head; // Declaration of temporary structs to allow the itteration of the Linked list

	//clear the frames as well as the memory allocated that is associated with the frames to prevent memory leaks
	while (head != NULL) {
		head = head->pNext;
		free(temp->frameName);
		free(temp);
		temp = head;
	}
	// clear the memory of animation name
	free(anm->animationName);
	free(head);
	free(temp);
}