#pragma once
#include <vector>
#include <string>

using namespace std;

class File {
public:
	File(string name_, int size_);

	string getName();
	int getSize();
private:
	string name;
	int size;
};

class Directory {
public:
	Directory(string name_);

	string getName();
	int getSize(int maxSize, int& sizeSum);
	int getSizes(vector<int>& sizes);

	void addDirectory(Directory d);
	void addFile(string path, File file);

private:
	string name;
	int size;

	vector<Directory> directories;
	vector<File> files;
};