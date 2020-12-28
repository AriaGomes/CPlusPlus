/************************************************
Filename:				Frame.cpp
Version:				1.0
Author:					Aria Gomes
Assignment Number:		1
Assignment Name:		Animation Project in C++
Course Name:			C++
Course Code:			CST219
Lab Section Number:		303
Professor's Name:		Surbhi Bahri
Due Date:				2020/02/11
Submission Date:		2020/02/11
List of source files:	Frame.cpp, Animation.cpp, ass1.cpp, frame.h, animation.h
Purpose: To get started practicing C++ concepts such as Objects, classes, destructors etc.
The Program adds "Frames"(nodes) to the begining to a singly linked list
using two structures with the ability to Edit, Report(Print) the animation,
Delete the last "frame"(tail/node) and also quit without any memory leaks.
**************************************************/
#include "frame.h"
/*********************************************************************
Filename:			   Frame.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   1
Assignment name :	   Animation Project in C
Date :			       February 11 2020
Submission Date :	   February 11 2020
Professor :			   Surbhi Bahri
Purpose :			   Initialize the Frame data members to nullptr when new
contructor keyword is used
***********************************************************************/
Frame::Frame()
{
	frameName = nullptr;
	pNext = nullptr; // initialises all Frame data members to nullptr
}

/*********************************************************************
Filename:			   Frame.cpp
Author :			   Aria Gomes No :   040 878 659
Course Name / Number : C++ Programming   CST8219
Lab Sect :			   303
Assignment # :		   1
Assignment name :	   Animation Project in C
Date :			       February 11 2020
Submission Date :	   February 11 2020
Professor :			   Surbhi Bahri
Purpose :			   Delete the content of the framename when the destructor is called
***********************************************************************/
Frame::~Frame()
{
	delete[] frameName; // Deletes the content of frameName
}