#pragma once

class GradedActivity {

private: // Data Members
	double score;
	bool isPassingGrade;

public: // Constructors
	GradedActivity(double score = 0, bool isPassingGrade = false) {

		this->score = score;
		this->isPassingGrade = isPassingGrade;

	}

public: // Getters
	double getScore() const;
	bool isPassing() const;

public: // Setters
	void setScore(double);
	void setIsPassingGrade(bool);

protected: // Methods
	virtual void determineIsPassing();


};
