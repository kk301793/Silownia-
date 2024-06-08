#include "StrengthExerciseBase.h"

vector<StrengthExercise> StrengthExerciseBase::get_StrengthExercise()
{
	FileReader f;
	vector<vector<string>>strengthExerciseData = f.readFile("strength_exercises.txt");
	vector<StrengthExercise> strengthExercises;

	for (vector<string>ce : strengthExerciseData) {
		StrengthExercise c(ce[0],stoi(ce[1]),ce[2],ce[3]);
		strengthExercises.push_back(c);
	}

	return strengthExercises;
}

vector<StrengthExercise> StrengthExerciseBase::get_StrengthExercise(Filter f)
{
	vector<StrengthExercise>strengthExercises = get_StrengthExercise();
	vector<StrengthExercise>filteredExercises;

	for (StrengthExercise ce : strengthExercises) {
		if (f.get_minDifficultyLevel() != "") {
			int minDifficultyLevel = stoi(f.get_minDifficultyLevel());
			int current = ce.get_difficultyLevel();
			if (current < minDifficultyLevel) {
				continue;
			}

		}
		if (f.get_maxDifficultyLevel() != "") {
			int maxDifficultyLevel = stoi(f.get_maxDifficultyLevel());
			int current = ce.get_difficultyLevel();
			if (current > maxDifficultyLevel) {
				continue;
			}

		}
		if (f.get_bodyPart() != "" && ce.get_bodyPart() != f.get_bodyPart()) {
			continue;
		}
		if (f.get_typeOfExercise() != "" && ce.get_typeOfExercise() != f.get_typeOfExercise()) {
			continue;
		}
		
		filteredExercises.push_back(ce);
	}
	return filteredExercises;
}

void StrengthExerciseBase::add_StrengthExercise(StrengthExercise ce)
{
	ofstream file;
	file.open("strength_exercises.txt", ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		//exit(0);
	}
	else {
		file << ce;
		file.close();
	}
}

void StrengthExerciseBase::delete_Exercise( int number)
{
	vector<StrengthExercise> exercise = get_StrengthExercise();
	exercise.erase(exercise.begin()+number);

	ofstream file;
	file.open("strength_exercises.txt");
	if (!file.is_open()) {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		//exit(0);
	}
	else {
		for (StrengthExercise se : exercise) {
			file << se;
		}
		file.close();
	}

}
