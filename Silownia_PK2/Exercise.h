#pragma once
#include"Libraries.h"

class Exercise
{
protected:
	string name;
	int difficultyLevel;

public:
	Exercise(); //konstruktor domyslny
	Exercise(string name, int difficultyLevel); //konstruktor wieloargumentowy
	Exercise(const Exercise& e); // konstruktor kopiujacy
	~Exercise();
	Exercise& operator=(const Exercise& e);
	friend ostream& operator << (ostream& ekran, const Exercise& obj);
	friend istream& operator >> (istream& in, Exercise& c);
	void set_name(string name);
	void set_difficultyLevel(int difficultyLevel);
	string get_name();

	int get_difficultyLevel();
	virtual string getDetails();
	
	
	
};

