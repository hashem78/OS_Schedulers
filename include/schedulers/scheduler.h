#pragma once

#include <deque>
#include <string>
#include <iostream>
#include <fstream>
#include "../process.h"
using Processes = std::deque<Process>;
using std::string;
class Scheduler
{
	static bool writtenToFiles;
public:
	Scheduler(string n);
	const string name;
	int currentTime = 0;
	Processes finishedProcesses;
	Processes processesQueue;
	Processes processes;
	auto readJobs() -> void;
	auto printOutputs() const -> void;
	auto writeOutputs() const -> void;

	virtual auto run() -> void = 0;
};