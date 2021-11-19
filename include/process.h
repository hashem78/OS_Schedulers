#pragma once
#include <string>
class Process
{

public:
	int delay = 0;
	int turnAroundTime = 0;
	int timeRunning = 0;
	std::string name;
	int arrivalTime;
	int arrivalOrder;
	int processingTime;
	int responseTime = -1;
	bool finished = false;

	Process(std::string name, int arrivalTime, int processingTime, int arrivalOrder);
	auto remains() const -> int;
	auto run(const int& currentTime)->Process;

	auto operator==(const Process& other) const -> bool;
	friend auto operator<<(std::ofstream& f, const Process& process)->std::ofstream&;
	friend auto operator<<(std::ostream& f, const Process& process)->std::ostream&;
};