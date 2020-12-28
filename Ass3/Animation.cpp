/************************************************
Filename: Animation.cpp
Version: 1.0
Author: Aria Gomes
Assignment Number:2
Assignment Name: Assignment 3
Course Name: C++
Course Code:CST8219
Lab Section Number: 303
Professor's Name: Surbhi Bahri
Due Date: 2020/05/06
Submission Date:2020/05/06
List of source files: AnimationManager.cpp, Animation.cpp, Frame.cpp, Assignment3.cpp, VideoFrame.cpp, AudioFrame.cpp
Purpose: Creates the animations
**********************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"

/***********************************************
Function name: ~Animation
Purpose: Destructor for Animation
In parameters: void
Out Parameters: void
Version: 1.0
Author: Aria Gomes
************************************************/

Animation::~Animation() {

	// delete all the frames
	for (Frame* frame : this->frames) {
		delete frame;
	}
}

/***********************************************
Function name: EditFrame
Purpose: Edits a Frame in the Forward_List
In parameters: void
Out Parameters: void
Version: 1.0
Author: Aria Gomes
************************************************/

void Animation::EditFrame() {

	// create local variables along with calculate the distance from the beginning of the list to the end
	int index, counter = 0;
	string name;
	double size;
	int length = distance(this->frames.begin(), this->frames.end());

	char c = getchar(); // limits user option to first value entered

	// if the list is empty return 
	if (this->frames.empty()) {
		cout << "There are no Frames" << endl;
		return;
	}

	// printout and get user input for what frame to edit
	cout << "Edit Frame in the Animation" << endl;
	cout << "There are " << length << " Frame(s) in the list. Please specify the index (<=0) to edit at: ";
	cin >> index;

	// check to make sure frame is editable
	if (index >= length) {
		cout << "Not a Frame" << endl;
		return;
	}

	// go through the frames and edit the correct frame, break the loop when the frame is found
	for (Frame* frame : this->frames) {
		if (index == counter) {
			cout << "The is " << (*frame) << ". What do you wish to replace them with?" << endl;
			cin >> name;
			cin >> size;

			// figure out which frame type it is and replace it
			if (dynamic_cast<AudioFrame*>(frame) == nullptr) {
				*frame = AudioFrame(name, size);
			}
			else {
				*frame = VideoFrame(name, size);
			}
			break;
		}
		counter++;
	}
	cout << "Frame #" << index << " edit complete" << endl;
}

/***********************************************
Function name: DeleteFrame
Purpose: Delete a frame
In parameters: void
Out Parameters: void
Version: 1.0
Author: Aria Gomes
************************************************/

void Animation::DeleteFrame() {

	char c = getchar(); // limits user option to first value entered

	// return if there are no frames
	if (this->frames.empty()) {
		cout << "There are no Frames in the Animation" << endl;
		return;
	}

	// delete the frame from the front
	delete* this->frames.begin();
	this->frames.pop_front();
	cout << "First Frame Deleted" << endl;
}

/***********************************************
Function name: operator>>
Purpose: Input a frame into the animation
In parameters: istream&, Animation&
Out Parameters: istream&
Version: 1.0
Author: Aria Gomes
************************************************/

istream& operator>>(istream& is, Animation& a) {

	// local variables
	string name;
	double size;
	char type;
	Frame* frame(NULL);

	char c = getchar(); // limits user option to first value entered

	// get info to insert a frame
	cout << "Insert a Frame in the Animation\nPlease enter the frameName: ";
	cin >> name;

	// get the size of the frame
	cout << "Please enter the Frame size(MB): ";
	cin >> size;

	// get the type of the frame
	cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): ";
	cin >> type;

	// add the frame to the front of the list depending on type
	switch (type) {
	case 'A': // AudioFrame option
	case 'a':
		frame = new AudioFrame(name, size);
		a.frames.push_front(frame);
		break;
	case 'V':	// VideoFrame option
	case 'v':
		frame = new VideoFrame(name, size);
		a.frames.push_front(frame);
		break;
	default: // default option
		cout << "Not a valid Option " << endl;
		return is;
	}

	cout << "Frame " << name << " added at the front of frames" << endl;

	return is;
}

/***********************************************
Function name: operator<<
Purpose: Output for the Animation
In parameters: ostream&, Animation&
Out Parameters: ostream&
Version: 1.0
Author: Aria Gomes
************************************************/

ostream& operator<<(ostream& os, Animation& a) {

	int counter = 0;

	// output the animation
	cout << "\tAnimation Name is " << a.animationName << endl;
	cout << "\tReport the Animaiton" << endl;

	// frames is empty
	if (a.frames.empty()) {
		cout << "No frames in the Animation" << endl;
		return os;
	}

	// output all the frames
	for (Frame* frame : a.frames) {
		os << "Frame # " << counter << endl;
		os << (*frame) << endl;
		(*frame).CalculateFrameResource();
		counter++;
	}
	return os;
}