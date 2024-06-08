#include "Filter.h"

Filter::Filter()
{
}

Filter& Filter::operator=(const Filter& f)
{
	minDifficultyLevel = f.minDifficultyLevel;
	maxDifficultyLevel = f.maxDifficultyLevel;
	intensity = f.intensity;
	bodyPart = f.bodyPart;
	typeOfExercise = f.typeOfExercise;

	return *this;
}

string Filter::get_minDifficultyLevel()
{
	return this->minDifficultyLevel;
}

string Filter::get_maxDifficultyLevel()
{
	return this->maxDifficultyLevel;
}

string Filter::get_intensity()
{
	return this->intensity;
}

string Filter::get_bodyPart()
{
	return this->bodyPart;
}

string Filter::get_typeOfExercise()
{
	return this->typeOfExercise;
}

void Filter::set_minDifficultyLevel(string minDifficultyLevel)
{
	this->minDifficultyLevel = minDifficultyLevel;
}

void Filter::set_maxDifficultyLevel(string maxDifficultyLevel)
{
	this->maxDifficultyLevel = maxDifficultyLevel;
}

void Filter::set_intensity(string intensity)
{
	this->intensity = intensity;
}

void Filter::set_bodyPart(string bodyPart)
{
	this->bodyPart = bodyPart;
}

void Filter::set_typeOfExercise(string typeOfExercise)
{
	this->typeOfExercise = typeOfExercise;
}
