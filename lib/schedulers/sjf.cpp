#include "../../include/schedulers/sjf.h"
auto SJFScheduler::run() -> void 
{
	auto arrivalComp = [&](const Process& a, const Process& b) -> bool
	{
		return a.arrivalTime < b.arrivalTime;
	};
	auto processingComp = [&](const Process& a, const Process& b) -> bool
	{
		return a.processingTime < b.processingTime;
	};
	using namespace std;
	auto first = *std::min_element(processes.begin(), processes.begin(), arrivalComp);

	processesQueue.push_back(first);
	while (!processesQueue.empty())
	{
		auto top = processesQueue.front();
		processesQueue.pop_back();
		auto afterRunning = top.run(currentTime);

		if (!afterRunning.finished)
		{
			currentTime++;
			processesQueue.push_back(top);
		}
		else
		{
			processes.erase(find(processes.begin(), processes.end(), top));
			finishedProcesses.push_back(top);
			auto potenialProcesses = Processes();
			copy_if(
				processes.begin(), processes.end(),
				back_inserter(potenialProcesses),
				[&](const Process& process) -> bool
				{
					return currentTime >= process.arrivalTime;
				});

			if (!potenialProcesses.empty())
			{
				auto next = *min_element(potenialProcesses.begin(), potenialProcesses.end(), processingComp);
				processesQueue.push_back(next);
			}
		}
	}

	//writeOutputs();
}