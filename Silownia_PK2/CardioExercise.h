#pragma once
#include "Exercise.h"

class CardioExercise :public Exercise
{
private:
	string intensity;

public:

	CardioExercise();
	CardioExercise(string name, int difficultyLevel, string intensity);
	CardioExercise(const CardioExercise & c);
	CardioExercise& operator =(const CardioExercise& c);
	friend ostream& operator << (ostream& ekran, const CardioExercise& obj);
	friend istream& operator >> (istream& in, CardioExercise& c);

	string getDetails();
	void set_intensity(string intensity);
	string get_intensity();
	CardioExercise setExercise(CardioExercise & ce);

	virtual void show_Exercise();
};

