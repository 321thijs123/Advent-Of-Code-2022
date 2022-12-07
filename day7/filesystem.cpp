#include "filesystem.h"

using namespace std;

File::File(string name_, int size_) {
	name = name_;
	size = size_;
}

string File::getName() {
	return name;
}

int File::getSize() {
	return size;
}

Directory::Directory(string name_) {
	name = name_;
}

void Directory::addDirectory(Directory d) {
	directories.push_back(d);
};

void Directory::addFile(string path, File file) {
	if (path.substr(0, path.length() - 1) == name) {
		for (File f : files) {
			if (f.getName() == file.getName()) {
				return;
			}
		}

		files.push_back(file);
	}
	else {
		const int childPos = path.find('/') + 1;
		path = path.substr(childPos, path.size() - childPos);

		for (Directory& d : directories) {
			if (d.getName() == path.substr(0, path.find('/'))) {
				d.addFile(path, file);
				return;
			}
		}

		directories.push_back(path.substr(0, path.find('/')));
		directories.back().addFile(path, file);
	}
};

string Directory::getName() {
	return name;
}

int Directory::getSize(int maxSize, int& sizeSum) {
	int size = 0;

	for (File& f : files) {
		size += f.getSize();
	}

	for (Directory& d : directories) {
		size += d.getSize(maxSize, sizeSum);
	}

	if (size < maxSize) sizeSum += size;

	return size;
}

int Directory::getSizes(vector<int>& sizes) {
	int size = 0;

	for (File& f : files) {
		size += f.getSize();
	}

	for (Directory& d : directories) {
		size += d.getSizes(sizes);
	}

	sizes.push_back(size);

	return size;
}