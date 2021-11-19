#include <algorithm>
#include "../process.h"
#include "scheduler.h"
class FiFoScheduler : public Scheduler
{
	static bool cmp(const Process& a, const Process& b)
	{
		if (b.arrivalTime == a.arrivalTime)
			return b.arrivalOrder < a.arrivalOrder;
		return b.arrivalTime < a.arrivalTime;
	}

public:
	auto run() -> void;
};