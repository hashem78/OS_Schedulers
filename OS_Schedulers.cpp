#include "OS_Schedulers.h"
using namespace std;

int main()
{

	vector<unique_ptr<Scheduler>> schedulers;
	schedulers.push_back(make_unique<FiFoScheduler>(FiFoScheduler()));
	schedulers.push_back(make_unique<SJFScheduler>(SJFScheduler()));
	schedulers.push_back(make_unique<SRTScheduler>(SRTScheduler()));
	schedulers.push_back(make_unique<RoundRobinScheuler>(RoundRobinScheuler(4)));
	for (const auto& sch : schedulers)
	{
		sch->run();
		sch->printOutputs();
	}
}
