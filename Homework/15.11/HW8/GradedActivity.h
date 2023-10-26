#pragma once

class GradedActivity {

private: // Data Members
	double score;
	bool isPassingGrade;

public: // Constructors
	GradedActivity(double score = 0) {

		isPassingGrade = false;
		this->score = score;
	}

public: // Getters
	double getScore() const;
	bool isPassing() const;

protected: // Setters
	virtual void setScore(double);

protected: // Protected Setter
	void setIsPassingGrade(bool);

protected: // Methods
	virtual void determineIsPassing();


};
