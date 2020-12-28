/************************************************
Filename:ass0.c
Version: 1.0
Author: Patrick Bobyn
Assignment Number:0
Assignment Name:Animation Project in C
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Surbhi Bahri
Due Date: 2019/09/21
Submission Date:2019/09/18
List of source files: ass0.c
Purpose: Until the User quits the program. It will read a valid response from the keyboard
in order to go through the process of either creating a frame of animation,editing a frame
,displaying all frames or even delete a frame.
**********************************/

// ass0.c
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC // need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <stdio.h>
#include <string.h>

typedef enum { FALSE = 0, TRUE } BOOL;

struct Frame {
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

/***********************************************
Function name: main
Purpose: main function

In parameters: None
Out Parameters: 0 for Success
Version: 1.0
Author: Andrew Tyler
************************************************/

int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	Animation RG;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	InitAnimation(&RG);
	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit\n");
		scanf("%c", &response);
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

// MY ADDED CODE 

/***********************************************
Function name: initAnimation
Purpose: Create the Animation structure

In parameters: Animation*
Out Parameters: nothing
Version: 1.0
Author: Patrick Bobyn
************************************************/

void InitAnimation(Animation* ani) {

	char n;
	char* name = malloc(100*sizeof(char));
	
	// get animation name
	printf("Please Enter the Animation Name: ");
	scanf("%s", name);
	n = getchar();

	// assign animation name
	ani->animationName = malloc(strlen(name)*sizeof(char)+1);
	strcpy(ani->animationName, name);

	ani->frames = NULL;
	free(name);
}

/***********************************************
Function name: InsertFrame
Purpose: Insert a frame into a linked list

In parameters: Animation*
Out Parameters: nothing
Version: 1.0
Author: Patrick Bobyn
************************************************/

void InsertFrame(Animation* ani) {
	
	struct Frame *head = malloc(sizeof(struct Frame));
	char n;
	char* name = malloc(100 * sizeof(char));

	// Get name of Frame
	printf("Please enter the Frame frameName: ");
	scanf("%s", name);
	n = getchar();

	head->frameName = malloc(strlen(name) * sizeof(char)+1);
	strcpy(head->frameName, name);

	// assign Framename and pNext
	head->pNext = ani->frames;
	ani->frames = head;
	free(name);
}

/***********************************************
Function name: DeleteFrame
Purpose: Delete the frame at the end of the Linked List

In parameters: Animation*
Out Parameters: Nothing
Version: 1.0
Author: Patrick Bobyn
************************************************/

void DeleteFrame(Animation* ani) {

	char n = getchar();
	struct Frame* tail = ani->frames;
	struct Frame* temp;

	// There are no Frames so return
	if (tail == NULL) {
		printf("Invalid! No Frames to delete.\n");
		return;
	}

	// the next frame is null so delete current frame
	if (tail->pNext != NULL)
		temp = tail->pNext;
	else { // clear only frame
		free(tail->frameName);
		free(tail);
		tail = NULL;
		ani->frames = NULL;
		return;
	}

	// move to last frame
	while (temp->pNext != NULL) {
		tail = temp;
		temp = temp->pNext;
	}

	// clear last frame
	if (tail != NULL)
		tail->pNext = NULL;

	free(temp->frameName);
	free(temp);
}

/***********************************************
Function name: EditFrame
Purpose: Edit a frame at a selected index

In parameters: Animation*
Out Parameters: Nothing
Version: 1.0
Author: Patrick Bobyn
************************************************/

void EditFrame(Animation* ani) {

	char n = getchar();
	int i = 1, index = 1;
	char* name = malloc(100 * sizeof(char));
	struct Frame* temp = ani->frames;

	// make sure there are frmaes to edit
	if (temp == NULL) {
		printf("No Frames to edit!\n");
		return;
	}

	// move to last frame
	while (temp->pNext != NULL) {
		temp = temp->pNext;
		i++;
	}

	// ask which frame 
	printf("There are %d Frame(s) in the list. Please specify the index (<=0) to edit at: ", i);
	while (scanf(" %d", &index) != 1) {
		printf("Enter a valid number: ");
		n = getchar();
	}
	n = getchar();

	// check for valid range
	if ( (index < 0) || (index >= i) ) {
		printf("Invalid! Returning to menu!\n");
		return;
	}

	// move to indexed frame
	temp = ani->frames;
	for (i = 0; i < index; i++) {
		temp = temp->pNext;
	}

	// get frame name 
	printf("The name of this Frame is %s. What do you wish to replace it with? ", temp->frameName);
	scanf("%s", name);
	n = getchar();

	// reallocate frameName
	free(temp->frameName);
	temp->frameName = malloc(strlen(name) * sizeof(char) + 1);

	// move new name over
	strcpy(temp->frameName, name);
	free(name);
}

/***********************************************
Function name: ReportAnimation
Purpose: Print out the contents of the Linked List

In parameters: Animation*
Out Parameters: nothing
Version: 1.0
Author: Patrick Bobyn
************************************************/

void ReportAnimation(Animation* ani) {

	char n = getchar();
	struct Frame* tail = ani->frames;
	int i = 0;
	
	// print out the animation name
	printf("Animation name is %s\nReport the animation\n", ani->animationName);

	// print out the frames
	while (tail != NULL) {
		printf("Image %d, file name = %s\n", i, tail->frameName);
		tail = tail->pNext;
		++i;
	}
}

/***********************************************
Function name: Cleanup
Purpose: Final method meant to free all of the memory that was allocated

In parameters: Animation*
Out Parameters: Nothing
Version: 1.0
Author: Patrick Bobyn
************************************************/

void CleanUp(Animation* ani) {
	
	struct Frame* head = ani->frames;
	struct Frame* temp = head;
	
	// clear the frames
	while (head != NULL) {
		head = head->pNext;
		free(temp->frameName);
		free(temp);
		temp = head;
	}

	// clear the animation name
	free(ani->animationName);
}