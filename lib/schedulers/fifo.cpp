#include "../../include/schedulers/fifo.h"

FiFoScheduler::FiFoScheduler() : Scheduler("FiFo") {}
auto FiFoScheduler::run() -> void
{
	std::copy(begin(processes), end(processes), back_inserter(processesQueue));
	std::make_heap(begin(processesQueue), end(processesQueue), cmp);
	while (!processesQueue.empty())
	{
		std::pop_heap(begin(processesQueue), end(processesQueue), cmp);
		auto process = processesQueue.back();
		processesQueue.pop_back();
		if (currentTime < process.arrivalTime)
		{
			currentTime += abs(process.arrivalTime - currentTime);
		}

		auto afterRunning = process.run(currentTime);

		if (!afterRunning.finished)
		{
			processesQueue.push_back(process);
			std::push_heap(begin(processesQueue), end(processesQueue), cmp);
			currentTime++;
		}
		else
		{
			finishedProcesses.push_back(process);
		}
	}

	//writeOutputs();
}