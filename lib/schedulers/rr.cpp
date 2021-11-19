#include "../../include/schedulers/rr.h"
RoundRobinScheuler::RoundRobinScheuler(int q) :quantum(q) {

}
auto RoundRobinScheuler::run() -> void
{
	using namespace std;
	auto arrivalComp = [&](const Process& a, const Process& b) -> bool
	{
		return a.arrivalTime < b.arrivalTime;
	};
	auto first = min_element(processes.begin(), processes.end(), arrivalComp);
	processesQueue.push_front(*first);
	processes.erase(first);
	while (!processesQueue.empty())
	{
		auto& front = processesQueue.front();
		// the response time has to be set here
		if (front.responseTime == -1)
		{
			front.responseTime = currentTime;
		}
		front = front.run(++currentTime);
		auto popped = false;
		if (front.remains() == 0)
		{
			finishedProcesses.push_back(front);
			processesQueue.pop_front();
			popped = true;
		}
		auto frtyCpy = front;
		if (!popped)
			processesQueue.pop_front();

		if (currentTime % quantum == 0)
		{

			for (auto it = processes.begin(); it != processes.end();)
			{
				if (currentTime >= it->arrivalTime)
				{
					auto cpy = *it;
					processesQueue.push_back(cpy);
					processes.erase(it);
					it = processes.begin();
				}
				else
				{
					it++;
				}
			}
			if (front.remains() != 0)
				processesQueue.push_back(frtyCpy);
		}
		else
		{
			if (!popped)
				processesQueue.push_front(frtyCpy);
		}

	}
}