#include "OS_Schedulers.h"
using namespace std;

int main()
{
	vector<unique_ptr<Scheduler>> schedulers;
	schedulers.push_back(make_unique<FiFoScheduler>(FiFoScheduler()));
	schedulers.push_back(make_unique<SJFScheduler>(SJFScheduler()));
	schedulers.push_back(make_unique<SRTScheduler>(SRTScheduler()));
	cout << "Enter quantum length for Round Robin(-1 to not use): ";
	int rr;
	cin >> rr;
	if (rr != -1)
		schedulers.push_back(make_unique<RoundRobinScheuler>(RoundRobinScheuler(-1)));
	for (const auto &sch : schedulers)
	{
		sch->run();
		sch->writeOutputs();
		sch->printOutputs();
	}
	cin.get();
}
