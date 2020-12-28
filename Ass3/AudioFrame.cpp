/************************************************
Filename:				AudioFrame.cpp
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
Purpose:				Child class of Frame, runs the audio frame implementation
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
Purpose:		Calculate the frames resources
In parameters:	void
Out Parameters: void
Version:		1.0
Author:			Aria Gomes
************************************************/

void AudioFrame::CalculateFrameResource() {

	// output the frame resource
	cout << "MP3 Lossy Compression" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "bitrate (kbits/s):" << "\t|" << this->BITRATE[0] << "\t|" << this->BITRATE[1] << "\t|" << this->BITRATE[2] << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "file size (MB):\t";
	for (int i = 0; i < 3; i++) {
		cout << "\t|" << fixed << setprecision(2) << this->size / this->COMPRESSION_RATIO[i];
	}
	cout << endl << "-----------------------------------------------------" << endl;
}

/***********************************************
Function name:	operator<<
Purpose:		Output for AudioFrame
In parameters:	ostream&, AudioFrame&
Out Parameters: ostream&
Version:		1.0
Author:			Aria Gomes
************************************************/

ostream& operator<<(ostream& os, AudioFrame& af) {

	os << "Audio Frame: ";

	return os;
}