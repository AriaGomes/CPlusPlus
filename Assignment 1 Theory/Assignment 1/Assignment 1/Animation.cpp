/************************************************
Filename:				Animation.cpp
Version:				2.0
Author:					Aria Gomes
Assignment Number:		1
Assignment Name:		Theory Assignment 1
Course Name:			C++
Course Code:			CST219
Lab Section Number:		303
Professor's Name:		Surbhi Bahri
Due Date:				2020/02/11
Submission Date:		2020/02/11
List of source files:	Animation.cpp, Frame.cpp, ass1.cpp, frame.h, animation.h
Purpose: You are to write the code in Visual Studio 2019 wherever it is asked for.
**************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "frame.h"
#include "animation.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*********************************************************************
Filename:			   Animation.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   1
Assignment name :	   Animation Project in C++
Date :			       February 11 2020
Submission Date :	   February 11 2020
Professor :			   Surbhi Bahri
Purpose :			   Initialize the Animation frames to nullptr and 
prompts the user for the name of the animation
***********************************************************************/
Animation::Animation()
{
	char name[999]; // Creates a static array of 999 as a placeholder for animationName
	name[0] = '\0'; // Sets the beggining char to 0

	cout << "Please enter the Animaiton name: "; // Prompts the user for the Animation name
	cin >> name;

	animationName = new char[strlen(name) + 1]; // Copys and sets animationName to a dynamic charater size of 1000
	strcpy(animationName, name);

	frames = nullptr; // Initializes the frames of the animation to nullptr
}

/*********************************************************************
Filename:			   Animation.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   1
Assignment name :	   Animation Project in C++
Date :			       February 11 2020
Submission Date :	   February 11 2020
Professor :			   Surbhi Bahri
Purpose :			   Deletes and frees the memory of the entire linked list
without leaving any memory leaks
***********************************************************************/
Animation::~Animation() // Destructor
{
	delete[] animationName; // Deletes animationName (Frees memory)
	Frame* currentFrame; // Create head frame to itterate through all frames

	while (frames != nullptr) // Loop through all the frames and delete the frame
	{
		currentFrame = frames;
		frames = currentFrame->GetpNext();
		delete currentFrame; // Deletion point
	}
}

/*********************************************************************
Filename:			   Animation.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   1
Assignment name :	   Animation Project in C++
Date :			       February 11 2020
Submission Date :	   February 11 2020
Professor :			   Surbhi Bahri
Purpose :			   Prompts the user for the name of the frame and creates 
a placeholder frame with that name and adds it to the begining of the linkedlist
***********************************************************************/
void Animation::InsertFrame()
{
	char c = getchar(); // limits user option to first value entered

	Frame* head = new Frame;
	char name[999]; // Declaration of placeholder variable and Frame object name head 

	// Get name of Frame
	cout << "Please enter the frame name: ";
	cin >> name;

	// assign the name from placeholder to linked list to the frame
	head->GetFrameName() = new char[strlen(name) + 1];
	strcpy(head->GetFrameName(), name);

	// assign Framename and pNext
	head->GetpNext() = this->frames;
	this->frames = head;
}

/*********************************************************************
Filename:			   Animation.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   1
Assignment name :	   Animation Project in C++
Date :			       February 11 2020
Submission Date :	   February 11 2020
Professor :			   Surbhi Bahri
Purpose :			   Checks the linkedlist to see if frames exist in the list,
If they do itterate through the list and delete the last node. If not return to the menu
***********************************************************************/
void Animation::DeleteFrame()
{
	char c = getchar(); // limits user option to first value entered

	Frame* tail = this->frames;
	Frame* temp;

	// There are no Frames so return to menu
	if (tail == NULL) {
		cout << "Invalid! No Frames to delete.\n" << endl;
		return;
	}

	// the next frame is null so delete current frame
	if (tail->GetpNext() != NULL)
		temp = tail->GetpNext();
	else 
	{ // clear only last frame
		delete(tail->GetFrameName());
		free(tail);
		tail = NULL;
		this->frames = NULL;
		return;
	}

	// move to last frame
	while (temp->GetpNext() != NULL) 
	{
		tail = temp;
		temp = temp->GetpNext();
	}

	// clear last frame
	if (tail != NULL)
		tail->GetpNext() = NULL;

	delete temp; //Deletion point
}

/*********************************************************************
Filename:			   Animation.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   1
Assignment name :	   Animation Project in C++
Date :			       February 11 2020
Submission Date :	   February 11 2020
Professor :			   Surbhi Bahri
Purpose :			   Checks to see if frames exist in the list, if they do
prompt the user which frame in the list they wish to edit, check to see if the index
enterd is valid(loop until a valid index is enterd). Prompt the user with what they wish to
edit the content of the frame with and do so. If no frames exist, Return to the main menu.
***********************************************************************/

void Animation::EditFrame()
{
	char c = getchar(); // limits user option to first value entered

	int i = 1, index = 1;
	char name[999];
	Frame* temp = this->frames;

	// traverse linked list to make sure there are frmaes to edit
	if (temp == NULL) 
	{
		cout << "No Frames to edit!\n";
		return; // go back to menu
	}

	// traverse to last frame
	while (temp->GetpNext() != NULL) 
	{
		temp = temp->GetpNext();
		i++;
	}

	// prompt the user for the frame they wish to edit 
	cout << "There are " << i << " Frame(s) in the list. Please specify the index (<=" << i-1 << ") to edit at: " << endl;
	cin >> index;

	// check for valid range
	if ((index < 0) || (index >= i))
	{
		printf("Invalid! Returning to menu!\n");
		return;
	}

	// move to indexed frame
	temp = this->frames;
	for (i = 0; i < index; i++) 
		temp = temp->GetpNext();

	// get frame name 
	cout << "The name of this Frame is " << temp->GetFrameName() << ". What do you wish to replace it with? " << endl;
	cin >> name;

	delete temp->GetFrameName();

	temp->GetFrameName() = new char[strlen(name) + 1];
	// move new name over frin place holder
	strcpy(temp->GetFrameName(), name);
}

/*********************************************************************
Filename:			   Animation.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   1
Assignment name :	   Animation Project in C++
Date :			       February 11 2020
Submission Date :	   February 11 2020
Professor :			   Surbhi Bahri
Purpose :			   Check if list is empty, if its not Itterate through all the frames
and display them in a nice human readable list. If there are none return to the main menu
***********************************************************************/

void Animation::ReportAnimation()
{
	char c = getchar(); // limits user option to first value entered

	Frame* tail = this->frames; // New node declared and assigned to the value of the current frames
	int i = 0;

	if (tail == NULL)// Check if list is empty
	{
		cout << "No Frames to report!\n";
		return; // go back to menu
	}

	// print out the animation name
	cout << "Animation name is " << this->animationName << " \nReport the animation\n" << endl;

	// print out the frames
	while (tail != NULL) //Itterate through the linkedlist until a null node is reached
	{
		cout << "Frame " << i << " file name = " << tail->GetFrameName() << endl;
		tail = tail->GetpNext();
		++i;
	}
}


void Animation::ReportLength()
{
	Frame* head = frames;
	int i = Length(head); //Using the "Length" function passing the head pointer
	cout << "The List has " << i << " Elements Inside."  << endl;
}

int Animation::Length(Frame* head)
{

	int i = 0;
	while (head != NULL) //Itterate through the linkedlist until a null node is reached
	{
		head = head->GetpNext();
		i++;
	}
	return i;
}

void copyList(struct node* q, struct node** s)
{
	if (q != NULL)
	{
		*s = new node;

		(*s)->data = q->data;
		(*s)->link = NULL;

		copyList(q->link, &((*s)->link));
	}
}
