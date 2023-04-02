/// Task checker

#include <bits/stdc++.h>
using namespace std;
//#define WINDOWS

const int tests = 12;
const string solution = "main";

// Генерация названия теста по его номеру
// (Для каждой задачи по разному)
string input(int t) {
	string s = to_string(t);
	if (s.size() == 1) s = "0" + s;
	return s + ".in";
}
string output(int t) {
	string s = to_string(t);
	if (s.size() == 1) s = "0" + s;
	return s + ".out";
}

int main() {
	
	cout << "Task checker (";
	#ifdef WINDOWS
	cout << "Windows";
	#else
	cout << "Linux";
	#endif
	cout << " version)" << endl;
	
	int score = 0;
	for (int t = 1; t <= tests; t++) {
		string command = solution + " <" + input(t) + " >.checker";
		#ifndef WINDOWS
		command = "./" + command;
		#endif
		
		system(command.c_str());
		
		vector <string> a, b; string c;
		fstream fin;
		fin.open(".checker");
		while (fin >> c) a.push_back(c);
		fin.close();
		
		fin.open(output(t));
		while (fin >> c) b.push_back(c);
		fin.close();
		
		if (a == b) {
			cout << "#" << t << ": Accepted" << endl;
			score++;
		} else {
			cout << "#" << t << ": Wrong answer" << endl;
			
			cout << "Participant:" << endl;
			for (string f: a) cout << f << ' ';
			cout << endl;
			
			cout << "Jury:" << endl;
			for (string f: b) cout << f << ' ';
			cout << endl;
		}
	}
	cout << "Score: " << score << endl;
	
	#ifdef WINDOWS
	cin.get();
	#endif
	
	return 0;
}
