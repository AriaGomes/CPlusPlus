/************************************************
Filename:				Frame.cpp
Version:				3.0
Author:					Aria Gomes
Assignment Number:		2
Assignment Name:		Assignment 2
Course Name:			C++
Course Code:			CST219
Lab Section Number:		303
Professor's Name:		Surbhi Bahri
Due Date:				2020/03/11
Submission Date:		2020/03/11
List of source files:	AnimationManager.cpp, Animation.cpp, Frame.cpp
Purpose:				This is the cpp file responsible for the creation of the frames.
**********************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <iostream>
using namespace std;
#include "Frame.h"
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
Filename:			   Frame.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:			   Constructor
***********************************************************************/
Frame::Frame(char* name, double duration) 
{
	// give the frame a name and duration
	this->frameName = new char[strlen(name) + 1];
	strcpy(this->frameName, name);
	this->duration = duration;
}

/*********************************************************************
Filename:			   Frame.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:			   Constructor
***********************************************************************/
Frame::Frame(const Frame& temp) 
{
	// copy the temp Frame into another frame
	this->frameName = new char[strlen(temp.frameName) + 1];
	strcpy(this->frameName, temp.frameName);
	this->duration = temp.duration;
}

/*********************************************************************
Filename:			   Frame.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:			   Deconstructor
***********************************************************************/
Frame::~Frame() 
{
	delete this->frameName;
}
/*********************************************************************
Filename:			   Frame.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:			   Overrides the = operator for Frame
***********************************************************************/
Frame& Frame::operator=(const Frame& temp) 
{

	// delete the old frame name
	delete this->frameName;

	// cope the new information over
	this->frameName = new char[strlen(temp.frameName) + 1];
	strcpy(this->frameName, temp.frameName);
	this->duration = temp.duration;

	return *this;
}
/*********************************************************************
Filename:			   Frame.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   2
Assignment name :	   Animation Project in C++
Date :			       March 11 2020
Submission Date :	   March 11 2020
Professor :			   Surbhi Bahri
Purpose:               overrides the print out method for frame
***********************************************************************/
ostream& operator<<(ostream& stream, Frame& temp) 
{

	stream << "frameName: " << temp.frameName << "; Duration: " << temp.duration;

	return stream;
}