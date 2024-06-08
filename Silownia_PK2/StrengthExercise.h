#pragma once
#include"Exercise.h"

class StrengthExercise:public Exercise
{
private:
	string bodyPart;
	string typeOfExercise;
public:
	StrengthExercise();
	StrengthExercise(string name, int difficultyLevel, string bodyPart, string typeOfExercise);
	StrengthExercise(const StrengthExercise& c);
	StrengthExercise& operator =(const StrengthExercise& c);
	friend ostream& operator << (ostream& ekran, const StrengthExercise& obj);
	friend istream& operator >> (istream& in, StrengthExercise& c);

	string getDetails();
	StrengthExercise setExercise(StrengthExercise& ce);
	void set_bodyPart(string bodyPart);
	void set_typeOfExercise(string typeOfExercise);
	string get_bodyPart();
	string get_typeOfExercise();

	virtual void show_Exercise();
};

