#include "../process.h"
#include "scheduler.h"
#include <algorithm>

class RoundRobinScheuler : public Scheduler
{
public:
	const int quantum;
	RoundRobinScheuler(int q);
	auto run() -> void override;
};