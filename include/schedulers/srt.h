#include "scheduler.h"
#include "../process.h"
#include <algorithm>
class SRTScheduler : public Scheduler
{

public:
	SRTScheduler();
	auto run() -> void override;
};