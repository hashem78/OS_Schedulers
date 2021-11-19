#include "../include/process.h"
#include <fstream>
#include <format>
Process::Process(std::string name, int arrivalTime, int processingTime, int arrivalOrder)
{
	this->name = name;
	this->arrivalTime = arrivalTime;
	this->processingTime = processingTime;
	this->arrivalOrder = arrivalOrder;
}
auto Process::remains() const -> int
{
	return processingTime - timeRunning;
}
auto Process::run(const int& currentTime) -> Process
{
	turnAroundTime = currentTime - arrivalTime;
	delay = turnAroundTime - processingTime;
	if (timeRunning == processingTime)
	{
		finished = true;
	}
	else if (timeRunning < processingTime)
	{
		if (responseTime == -1)
		{
			responseTime = currentTime - arrivalTime;
		}
		timeRunning++;
	}
	return *this;
};

auto Process::operator==(const Process& other) const -> bool
{
	return name == other.name;
}
 auto operator<<(std::ofstream& f, const Process& process) -> std::ofstream&
{
	f << std::format("{}: (response={}, turnaround={}, delay={})\n", process.name, process.responseTime, process.turnAroundTime, process.delay);

	return f;
}
 auto operator<<(std::ostream& f, const Process& process) -> std::ostream&
{
	f << std::format("{}: (response={}, turnaround={}, delay={})\n", process.name, process.responseTime, process.turnAroundTime, process.delay);

	return f;
}