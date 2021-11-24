#include "../../include/schedulers/srt.h"

auto SRTScheduler::run() -> void
{
	using namespace std;
	auto arrivalComp = [&](const Process &a, const Process &b) -> bool
	{
		return a.arrivalTime < b.arrivalTime;
	};
	auto remComp = [&](const Process &a, const Process &b) -> bool
	{
		int remA = abs(a.processingTime - a.timeRunning);
		int remB = abs(b.processingTime - b.timeRunning);
		if (remA == remB)
		{
			if (a.arrivalTime == b.arrivalTime)
			{
				return a.arrivalOrder < b.arrivalOrder;
			}
			return a.arrivalTime < b.arrivalTime;
		}
		return remA < remB;
	};
	auto first = *min_element(processes.begin(), processes.end(), arrivalComp);

	processesQueue.push_back(first);
	while (!processesQueue.empty())
	{
		auto top = processesQueue.front();
		processesQueue.pop_back();
		auto afterRunning = top.run(currentTime);

		if (!afterRunning.finished)
		{
			currentTime++;
			*find(processes.begin(), processes.end(), top) = afterRunning;
		}
		else
		{
			processes.erase(find(processes.begin(), processes.end(), top));

			finishedProcesses.push_back(top);
		}
		auto potenialProcesses = Processes();
		copy_if(
			processes.begin(), processes.end(),
			back_inserter(potenialProcesses),
			[&](const Process &process) -> bool
			{
				return currentTime >= process.arrivalTime;
			});

		if (!potenialProcesses.empty())
		{
			auto next = *min_element(potenialProcesses.begin(), potenialProcesses.end(), remComp);
			processesQueue.push_back(next);
		}

		//cin.get();
	}
}