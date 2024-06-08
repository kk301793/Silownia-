#include "FileReader.h"


vector<vector<string>> FileReader::readFile(string pathname) {
    ifstream file(pathname);
    vector<vector<string>> data;

    if (file.is_open()) {
        string tp;


        while (getline(file, tp)) {
            std::stringstream streamData(tp);
            string entry;
            vector<string> line;
            while (getline(streamData, entry, ',')) {
                line.push_back(entry);
            }
            data.push_back(line);
        }
        file.close();

        return data;
    }
}