#pragma once
#include"Libraries.h"
#include"CardioExerciseBase.h"
#include"StrengthExerciseBase.h"


class Actions
{
private:

	int option;
	bool createPlan = false;
	int choice;
	vector<StrengthExercise>strengthExerciceToPlan;
	vector<CardioExercise>cardioExerciceToPlan;
	vector<CardioExercise> cardioEx;
	vector<StrengthExercise>strengthEx;
	vector<Exercise*>exercises;

public:

	Actions();
	~Actions();


	void display_menu();
	void add_exercise();
	void create_trainingPlan();
	void trainingForDay(string day);
	void save_trainingPlan(string day);
	void show_exercise();
	void show_strenghtExercises();
	void show_cardioExercises();
	void show_Exercises();
	void show_trainingPlan();
	void delete_exercise();


};

