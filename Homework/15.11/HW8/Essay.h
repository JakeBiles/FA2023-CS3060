#pragma once
#include "GradedActivity.h"
class Essay : public GradedActivity {

public: // Constructors
	Essay(double score = 0) {

		GradedActivity::setScore(score);

	};

public: // Setters
	void setScore(double score) {

		GradedActivity::setScore(score);

	}

};