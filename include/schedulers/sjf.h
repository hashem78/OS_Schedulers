#include "scheduler.h"
#include "../process.h"
#include <algorithm>
class SJFScheduler : public Scheduler
{

public:
	SJFScheduler();
	auto run() -> void override;
};