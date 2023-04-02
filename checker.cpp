/// Task checker

#include <bits/stdc++.h>
using namespace std;
//#define WINDOWS

const int tests = 10;
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

void print(vector <string> &a) {
	if (a.empty()) cout << "*empty output*";
	else for (string &s: a) cout << s << ' ';
	cout << endl;
}

int main() {
	
	cout << "Task checker (";
	#ifdef WINDOWS
	cout << "Windows";
	#else
	cout << "Linux";
	#endif
	cout << " version)" << endl;
	cout << "Press Ctrl+C to skip test" << endl;
	
	int score = 0;
	for (int t = 1; t <= tests; t++) {
		cout << "#" << t << ": " << flush;
		
		string command = solution + " <" + input(t) + " >.checker";
		#ifndef WINDOWS
		command = "./" + command;
		#endif
		
		// Запуск решения
		system(command.c_str());
		
		// Ввод ответов
		fstream fin;
		vector <string> a, b; string c;
		
		fin.open(".checker");
		while (fin >> c) a.push_back(c);
		fin.close();
		
		fin.open(output(t));
		while (fin >> c) b.push_back(c);
		fin.close();
		
		// Проверка
		if (a == b) {
			cout << "Accepted" << endl;
			score++;
		} else {
			cout << "Wrong answer" << endl;
			
			cout << "Participant:" << endl;
			print(a);
			
			cout << "Jury:" << endl;
			print(b);
		}
	}
	cout << "Score: " << score << endl;
	
	#ifdef WINDOWS
	system("pause");
	#endif
	
	return 0;
}
