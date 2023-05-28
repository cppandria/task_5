#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string get_string_from_file(string file_name) {
	ofstream myfile;
	std::ifstream file(file_name);

	std::stringstream buffer;
	if (file)
	{
		buffer << file.rdbuf();
		file.close();
	}
	return buffer.str();
}

int get_count_from_file(string file_name, string key) {

	string file_content = get_string_from_file(file_name);

	int count = 0;
	for (int i = 0; i < key.length(); i++) {
		for (int j = 0; j < file_content.length(); j++) {
			if (file_content[j] == key[i])
			{
				count++;
			}
		}
	}
	return count;
}
int main() {

	string key_word = "BASIC";
	string file_name = "example.txt";

	cout << "File is:\n" << get_string_from_file(file_name) << endl << endl;
	cout << "Count =" << get_count_from_file(file_name, key_word) << endl;

	return 0;
}