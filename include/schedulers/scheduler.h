#pragma once
#include <deque>
#include <iostream>
#include <fstream>
#include "../process.h"
using Processes = std::deque<Process>;
class Scheduler
{
public:
	int currentTime = 0;
	Processes finishedProcesses;
	Processes processesQueue;
	Processes processes;
	Scheduler();
	auto readJobs() -> void;
	auto printOutputs() const -> void;
	auto writeOutputs() const -> void;
	

	virtual auto run() -> void = 0;
};