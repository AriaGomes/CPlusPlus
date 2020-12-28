/************************************************
Filename:				VideoFrame.cpp
Version:				1.0
Author:					Aria Gomes
Assignment				Number: 2
Assignment Name:		Assignment 3
Course Name:			C++
Course Code:			CST8219
Lab Section Number:		303
Professor's Name:		Surbhi Bahri
Due Date:				2020/05/06
Submission Date:		2020/05/06
List of source files:	AnimationManager.cpp, Animation.cpp, Frame.cpp, Assignment3.cpp, VideoFrame.cpp, AudioFrame.cpp
Purpose:				Child class of frames, runs the video frame implementation
**********************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
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
Function name:	CalculateFrameResource
Purpose:		Calculates the Resources for the frame
In parameters:	void
Out Parameters: void
Version:		1.0
Author:			Aria Gomes
************************************************/

void VideoFrame::CalculateFrameResource() {

	// output the Frame resources
	cout << "LEMPEL-Ziv-Welch Lossless Compression" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "colours:" << "\t | " << "2" << "\t | " << "4" << "\t | " << "8" << "\t | " << "16"
	<< "\t | " << "32" << "\t | " << "64" << "\t | " << "128" << "\t | " << "256" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "file size (MB):\t";
	for (int i = 0; i < BITS; i++) {
		cout << " | " << fixed << setprecision(2) << this->size / (this->COMPRESSION_RATIO * this->BITDEPTH_FACTOR[i]) << " ";
	}
	cout << endl << "-----------------------------------------------------------------------------------------" << endl;
}

/***********************************************
Function name:	 operator<<
Purpose:		 Output for videoframe
In parameters:	 ostream&, VideoFrame&
Out Parameters:  ostream&
Version:	     1.0
Author:			 Aria Gomes
************************************************/

ostream& operator<<(ostream& os, VideoFrame& vf) {
	os << "Video Frame: ";

	return os;
}