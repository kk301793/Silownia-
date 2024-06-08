#pragma once
#include"Libraries.h"
class Filter
{
private:
	string minDifficultyLevel;
	string maxDifficultyLevel;
	string intensity;
	string bodyPart;
	string typeOfExercise;

public:
	Filter();
	Filter& operator=(const Filter& f);
	string get_minDifficultyLevel();
	string get_maxDifficultyLevel();
	string get_intensity();
	string get_bodyPart();
	string get_typeOfExercise();
	void set_minDifficultyLevel(string minDifficultyLevel);
	void set_maxDifficultyLevel(string maxDifficultyLevel);
	void set_intensity(string intensity);
	void set_bodyPart(string bodyPart);
	void set_typeOfExercise(string typeOfExercise);
};

