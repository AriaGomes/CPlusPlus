/************************************************
Filename:Animation.cpp
Version: 1.0
Author: Patrick Bobyn
Assignment Number:1
Assignment Name: Animation Project in C++
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Surbhi Bahri
Due Date: 2019/10/12
Submission Date:2019/10/02
List of source files: Animation.cpp, Frame.cpp
Purpose: Until the User quits the program. It will read a valid response from the keyboard
in order to go through the process of either creating a frame of animation,editing a frame
,displaying all frames or even delete a frame.
**********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#include "Animation.h"
#include "frame.h"

using namespace std;

/***********************************************
Function name: Animation
Purpose: Constructor

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/

Animation::Animation() {
	
	char name[100] = "";

	// get animation name and assign it
	cout << "Please Enter the Animation Name: " << endl;
	cin >> name;
	
	this->animationName = new char[strlen(name) + 1];
	strcpy(this->animationName, name);

	// assign frames to NULL
	this->frames = NULL;
}

/***********************************************
Function name: ~Animation
Purpose: Deconstructor

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/

Animation::~Animation() {
	
	Frame* temp = this->frames;
	
	// clear the frames
	delete temp;

	// clear the animation name
	delete this->animationName;
}

/***********************************************
Function name: InsertFrame
Purpose: inserts a frame into the Animation

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/

void Animation::InsertFrame() {
	
	Frame *head = new Frame;
	char name[100];

	// Get name of Frame
	cout << "Please enter the Frame frameName: " << endl;
	cin >> name;
	
	// assign the name to the frame
	head->GetFrameName() = new char[strlen(name) + 1];
	strcpy(head->GetFrameName(), name);

	// assign Framename and pNext
	head->GetpNext() = this->frames;
	this->frames = head;
}

/***********************************************
Function name: EditFrame
Purpose: Edit a Frame in the Animation

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/

void Animation::EditFrame() {
	
	int i = 1, index = 1;
	char name[100];
	Frame* temp = this->frames;

	// make sure there are frmaes to edit
	if (temp == NULL) {
		cout << "No Frames to edit!\n" << endl;
		return;
	}

	// move to last frame
	while (temp->GetpNext() != NULL) {
		temp = temp->GetpNext();
		i++;
	}

	// ask which frame 
	cout << "There are " << i << " Frame(s) in the list. Please specify the index (<=0) to edit at: " << endl;
	cin >> index;

	// check for valid range
	if ((index < 0) || (index >= i)) {
		printf("Invalid! Returning to menu!\n");
		return;
	}

	// move to indexed frame
	temp = this->frames;
	for (i = 0; i < index; i++) {
		temp = temp->GetpNext();
	}

	// get frame name 
	cout << "The name of this Frame is " << temp->GetFrameName() << ". What do you wish to replace it with? " << endl;
	cin >> name;
	
	delete temp->GetFrameName();

	temp->GetFrameName() = new char[strlen(name) + 1];
	// move new name over
	strcpy(temp->GetFrameName(), name);
}

/***********************************************
Function name: DeleteFrame
Purpose: Delete the last Frame

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/

void Animation::DeleteFrame() {
	
	Frame* tail = this->frames;
	Frame* temp;

	// There are no Frames so return
	if (tail == NULL) {
		cout << "Invalid! No Frames to delete.\n" << endl;
		return;
	}

	// the next frame is null so delete current frame
	if (tail->GetpNext() != NULL)
		temp = tail->GetpNext();
	else { // clear only frame
		free(tail->GetFrameName());
		free(tail);
		tail = NULL;
		this->frames = NULL;
		return;
	}

	// move to last frame
	while (temp->GetpNext() != NULL) {
		tail = temp;
		temp = temp->GetpNext();
	}

	// clear last frame
	if (tail != NULL)
		tail->GetpNext() = NULL;

	delete temp;
}

/***********************************************
Function name: ReportAnimation
Purpose: Prints out the contents of the animation

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/

void Animation::ReportAnimation() {

	Frame* tail = this->frames;
	int i = 0;

	// print out the animation name
	cout << "Animation name is " << this->animationName << " \nReport the animation\n" << endl;

	// print out the frames
	while (tail != NULL) {
		cout << "Image " << i << " file name = " << tail->GetFrameName() << endl;
		tail = tail->GetpNext();
		++i;
	}
}