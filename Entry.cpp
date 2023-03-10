#include "Entry.h"

Entry::Entry(string _value, int _timestamp, ReplicaType _replica){
	this->delimiter = ":";
	value = _value;
	timestamp = _timestamp;
	replica = _replica;
}

Entry::Entry(string entry){
	vector<string> tuple;
	this->delimiter = ":";
	size_t pos = entry.find(delimiter);
	size_t start = 0;
	while (pos != string::npos) {
		string field = entry.substr(start, pos-start);
		tuple.push_back(field);
		start = pos + delimiter.size();
		pos = entry.find(delimiter, start);
	}
	tuple.push_back(entry.substr(start));

	value = tuple.at(0);
	timestamp = stoi(tuple.at(1));
	replica = static_cast<ReplicaType>(stoi(tuple.at(2)));
}

string Entry::convertToString() {
	return value + delimiter + to_string(timestamp) + delimiter + to_string(replica);
}
