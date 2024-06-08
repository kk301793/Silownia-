#include "CardioExerciseBase.h"

vector<CardioExercise> CardioExerciseBase::get_CardioExercises()
{
	FileReader f;
	vector<vector<string>>cardioExerciseData = f.readFile("cardio_exercises.txt");
	vector<CardioExercise> cardioExercises;

	for (vector<string>ce : cardioExerciseData) {
		CardioExercise c(ce[0], stoi(ce[1]), ce[2]);
		cardioExercises.push_back(c);
	}

	return cardioExercises;
}

vector<CardioExercise> CardioExerciseBase::get_CardioExercises(Filter f)
{
	vector<CardioExercise>cardioExercises = get_CardioExercises();
	vector<CardioExercise>filteredExercises;

	for (CardioExercise ce : cardioExercises) {
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
		if (f.get_intensity() != "" && ce.get_intensity() != f.get_intensity()) {
			continue;
		}
		filteredExercises.push_back(ce);
	}
	return filteredExercises;
}

void CardioExerciseBase::add_CardioExercise(CardioExercise ce)
{
	ofstream file;
	file.open("cardio_exercises.txt", ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		//exit(0);
	}
	else {
		file << ce;
		file.close();
	}
}

void CardioExerciseBase::delete_Exercise(int number)
{
	
		vector<CardioExercise> exercise = get_CardioExercises();
		exercise.erase(exercise.begin() + number);

		ofstream file;
		file.open("cardio_exercises.txt");
		if (!file.is_open()) {
			cout << "Nie udalo sie otworzyc pliku" << endl;
			//exit(0);
		}
		else {
			for (CardioExercise se : exercise) {
				file << se;
			}
			file.close();
		}

	}


