/************************************************
Filename:				Frame.cpp
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
Purpose:				Parent class for all frames
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
Function name:	operator<<
Purpose:		Output for the frames
In parameters:	ostream&, Frame&
Out Parameters: ostream&
Version:		1.0
Author:			Aria Gomes
************************************************/

ostream& operator<<(ostream& os, Frame& frame) 
{

	// figure out which frame it is and output the correct type
	try {
		AudioFrame& af = dynamic_cast<AudioFrame&>(frame);
		os << af;
	}
	catch (const bad_cast & e) {}

	try {
		VideoFrame& vf = dynamic_cast<VideoFrame&>(frame);
		os << vf;
	}
	catch (const bad_cast & e) {}

	os << "frameName = " << frame.frameName;

	return os;
}