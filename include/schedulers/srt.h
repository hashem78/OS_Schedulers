#include "scheduler.h"
#include "../process.h"
#include <algorithm>	
class SRTScheduler : public Scheduler
{

public:
	auto run() -> void override;
};