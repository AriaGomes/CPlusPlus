/************************************************
Filename:				AnimationManager.cpp
Version:				1.0
Author:					Aria Gomes
Assignment Number:		2
Assignment Name:		Assignment 3
Course Name:			C++
Course Code:			CST8219
Lab Section Number:		303
Professor's Name:		Surbhi Bahri
Due Date:				2020/05/06
Submission Date:		2020/05/06
List of source files:	AnimationManager.cpp, Animation.cpp, Frame.cpp, Assignment3.cpp, VideoFrame.cpp, AudioFrame.cpp
Purpose:				Manager for all frames
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
Function name:	EditAnimation
Purpose:		Edit an Animation
In parameters:	void
Out Parameters: void
Version:		1.0
Author:			Aria Gomes
************************************************/

void AnimationManager::EditAnimation() {

	unsigned int index;
	char response;
	bool cont = true;

	char c = getchar(); // limits user option to first value entered

	// return to menu if no animations
	if (this->animations.size() == 0) {
		cout << "There are no Animations" << endl;
		return;
	}

	// get the user to input an animation
	cout << "Which animation do you wish to edit? Please give the index (from 0 to " << this->animations.size() - 1 << "): ";
	cin >> index;

	// if the user input is too much tell the user that and return
	if (index >= this->animations.size()) {
		cout << "No Animation at that point" << endl;
		return;
	}

	cout << "Editing Animation #" << index << endl;

	// print out a menu until the user selects to exit
	while (cont) {

		cout << "\nMENU\n1. Insert a Frame at Front\n2. Delete first Frame\n3. Edit a Frame\n4. Quit" << endl;
		cin >> response;

		switch (response) {
		case '1':cin >> this->animations.at(index); break; // input a frame
		case '2':this->animations.at(index).DeleteFrame(); break; // delete a frame
		case '3':this->animations.at(index).EditFrame(); break; // edit a frame
		case '4': // return to main menus
			cont = false;
			cout << "Animation #" << index << " edit complete" << endl;
			break;
		default:cout << "Please enter a valid option" << endl;
		}
	}
}

/***********************************************
Function name:  DeleteAnimation
Purpose:		Delete the animation at the end of the list
In parameters:	void
Out Parameters: void
Version:		1.0
Author:			Aria Gomes
************************************************/

void AnimationManager::DeleteAnimation() {

	char c = getchar(); // limits user option to first value entered

	// there are no animations to delete
	if (this->animations.size() == 0) {
		cout << "No Animations to Delete" << endl;
		return;
	}

	// delete the last animation
	cout << "Animation at end has been deleted" << endl;
	this->animations.erase(this->animations.end() - 1);
}

/***********************************************
Function name:	operator>>
Purpose:		Input an animation
In parameters:	istream&, AnimationManager&
Out Parameters: istream&
Version:		1.0
Author:			Aria Gomes
************************************************/

istream& operator>>(istream& is, AnimationManager& am) {

	// string for the animation name
	string name;

	char c = getchar(); // limits user option to first value entered

	// get the name 
	cout << "Add an Animation to the Animation Manager\nPlease Enter the Animation Name: ";
	cin >> name;

	// create the animation with the name
	Animation animation(name);

	// check if animations is empty
	if (am.animations.empty())
		am.animations.reserve(32);

	// add the animation to the back of the animations
	am.animations.push_back(animation);

	cout << "Animation " << name << " added at the back of animation" << endl;

	return is;
}

/***********************************************
Function name:	operator<<
Purpose:		Output for the animation manager
In parameters:	ostream&, AnimationManager&
Out Parameters: ostream&
Version:		1.0
Author:			Aria Gomes
************************************************/

ostream& operator<<(ostream& os, AnimationManager& am) {

	cout << "Animation Manager: " << am.managerName << endl;

	// tell the user there is no animations to show
	if (am.animations.empty()) {
		return os << "There are no Animations" << endl;
	}

	// print out all the animations
	for (unsigned int i = 0; i < am.animations.size(); i++) {
		os << "Animation: " << i << endl << am.animations.at(i) << endl;
	}
	return os;
}