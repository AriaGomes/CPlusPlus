//Animation.h
#pragma once

class Animation
{
public:

	struct node
	{
		int data;
		struct node* link;
	};

	char* animationName;
	Frame* frames;
	Animation();
	~Animation();
	void InsertFrame();
	void EditFrame();
	void DeleteFrame();
	void ReportAnimation();
	void ReportLength();
	int Length(Frame* f);
	void copyList(struct node* q, struct node** s);
};
