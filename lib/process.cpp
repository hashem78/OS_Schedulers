#include "../include/process.h"
#include <fstream>
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
auto Process::run(const int &currentTime) -> Process
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

auto Process::operator==(const Process &other) const -> bool
{
	return name == other.name;
}
auto operator<<(std::ofstream &f, const Process &process) -> std::ofstream &
{
	f << process.name << ": (response=" << process.responseTime << ", turnaround=" << process.turnAroundTime << ", delay=" << process.delay << ")" << std::endl;

	return f;
}
auto operator<<(std::ostream &f, const Process &process) -> std::ostream &
{
	f << process.name << ": (response=" << process.responseTime << ", turnaround=" << process.turnAroundTime << ", delay=" << process.delay << ")" << std::endl;

	return f;
}