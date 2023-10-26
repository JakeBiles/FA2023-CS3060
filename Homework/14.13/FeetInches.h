#pragma once

class FeetInches
{
private:
	int feet;
	int inches;


public: // Constructors //
	FeetInches(int f = 0, int i = 0);
	FeetInches(FeetInches& copy);

public: // Mutator functions //
	void setFeet(int f);
	void setInches(int i);

public: // Accessor functions //
	int getFeet() const;
	int getInches() const;

private: // Member Functions
	void simplify();

public: // Overloaded operator functions //
	FeetInches operator+ (const FeetInches&);
	void operator+= (FeetInches&);
	FeetInches operator- (const FeetInches&);
	void operator-= (FeetInches&);
	FeetInches operator* (const FeetInches&);

};

