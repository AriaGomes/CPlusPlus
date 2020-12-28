/************************************************
Filename:				AnimationManager.cpp
Version:				3.0
Author:					Aria Gomes
Assignment				Number: 2
Assignment Name:		Assignment 2
Course Name:			C++
Course Code:			CST219
Lab Section Number:		303
Professor's Name:		Surbhi Bahri
Due Date:				2020/03/11
Submission Date:		2020/03/11
List of source files:	AnimationManager.cpp, Animation.cpp, Frame.cpp
Purpose:				This cpp file will create an animation manager. What this does is it allows creation of multiple animations in a vector field.
						These animations all hold multiple frames.
**********************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
/*********************************************************************
Filename:			   AnimationManager.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:			   Edit an Animation in the list
***********************************************************************/
void AnimationManager::EditAnimation() 
{
	int index;
	char response;
	bool cont = true;


	char c = getchar(); // limits user option to first value entered
	// return to menu if no animations
	if (this->animations.size() == 0) 
	{
		cout << "There are no Animations" << endl;
		return;
	}

	// get the user to input an animation
	cout << "Which animation do you wish to edit? Please give the index (from 0 to " << this->animations.size() - 1 << "): ";
	cin >> index;

	// if the user input is too much tell the user that and return
	if (index >= this->animations.size()) 
	{
		cout << "No Animation at that point" << endl;
		return;
	}

	cout << "Editing Animation #" << index << endl;

	// print out a menu until the user selects to exit
	while (cont) 
	{

		cout << "\nMENU\n1. Insert a Frame\n2. Delete a Frame\n3. Edit a Frame\n4. Quit" << endl;
		cin >> response;

		switch (response) 
		{
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
/*********************************************************************
Filename:			   AnimationManager.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:			   Delete an Animation
***********************************************************************/
void AnimationManager::DeleteAnimation() 
{

	int index;
	char c = getchar(); // limits user option to first value entered

	// there are no animations to delete
	if (this->animations.size() == 0) 
	{
		cout << "No Animations to Delete" << endl;
		return;
	}

	// get user input on animation to delete
	cout << "Which Animation do you wish to delete? Please give the index range 0 to " << this->animations.size() - 1 << ": ";
	cin >> index;

	// delete the animation
	cout << "Animation #" << index << " has been deleted" << endl;
	this->animations.erase(this->animations.begin() + index);
}
/*********************************************************************
Filename:			   AnimationManager.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:			   Overwrite the input operator
***********************************************************************/
istream& operator>>(istream& stream, AnimationManager& temp) {

	// string for the animation name
	string name;
	char c = getchar(); // limits user option to first value entered

	// get the name 
	cout << "Add an Animation to the Animation Manager\nPlease Enter the Animation Name: ";
	cin >> name;



	// create the animation with the name
	Animation animation(name);

	// add the animation to the back of the animations
	temp.animations.push_back(animation);

	cout << "Animation " << name << " added at the back of animation" << endl;

	return stream;
}
/*********************************************************************
Filename:			   AnimationManager.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:			   Overwrite the output method AnimationManager
***********************************************************************/
ostream& operator<<(ostream& stream, AnimationManager& temp) 
{
	cout << "Animation Manager: " << temp.managerName << endl;

	// tell the user there is no animations to show
	if (temp.animations.empty())
		return stream << "There are no Animations" << endl;
	

	// print out all the animations
	for (int i = 0; i < temp.animations.size(); i++) 
		stream << "Animation: " << i << endl << temp.animations.at(i) << endl;
	
	return stream;
}