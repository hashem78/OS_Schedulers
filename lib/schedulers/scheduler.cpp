#include "../../include/schedulers/scheduler.h"
Scheduler::Scheduler()
{
	readJobs();
}
auto Scheduler::readJobs() -> void
{

	std::ifstream ifile("in.txt");

	if (ifile.is_open())
	{
		int n;
		ifile >> n;

		int counter = 1;
		while (n--)
		{

			if (ifile.good())
			{
				std::string name;
				int arrival, process;
				ifile >> name >> arrival >> process;
				processes.emplace_back(name, arrival, process, counter++);
			}
			else
			{
				std::cout << "An error occured while reading from in.txt\n";
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		std::cout << "in.txt doesn\'t exist\n";
		exit(EXIT_FAILURE);
	}
}
auto Scheduler::printOutputs() const -> void
{
	for (const auto& process : finishedProcesses)
	{
		std::cout << process.name;
	}
	std::cout << "\n\n";
	for (const auto& process : finishedProcesses)
	{
		std::cout << process;
	}
}
auto Scheduler::writeOutputs() const -> void
{

	std::ofstream ofile("out.txt");

	if (ofile.is_open() && ofile.good())
	{
		for (const auto& process : finishedProcesses)
		{
			ofile << process.name;
		}
		ofile << "\n\n";
		for (const auto& process : finishedProcesses)
		{
			ofile << process;
		}
	}
	else
	{
		std::cout << "An error occured while writing to out.txt\n";
		exit(EXIT_FAILURE);
	}
}