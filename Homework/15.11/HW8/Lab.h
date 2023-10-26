#pragma once
#include "GradedActivity.h"

class Lab : public GradedActivity
{

public: // Constructors
	Lab(double score = 0) {

		GradedActivity::setScore(score);

	}

public: // Setters
	void setScore(double score) {

		GradedActivity::setScore(score);

	}
};

