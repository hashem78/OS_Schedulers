#include "../../include/schedulers/scheduler.h"
Scheduler::Scheduler(string n) : name(n)
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
	std::cout << name << "\n";
	for (const auto &process : finishedProcesses)
	{
		std::cout << process.name;
	}
	std::cout << "\n\n";
	for (const auto &process : finishedProcesses)
	{
		std::cout << process;
	}
	std::cout << "=======================\n";
}
auto Scheduler::writeOutputs() const -> void
{
	std::ofstream ofile;
	if (!writtenToFiles)
	{
		ofile.open("out.txt");
		writtenToFiles = true;
	}
	else
	{
		ofile.open("out.txt", std::ios_base::app);
	}

	if (ofile.is_open() && ofile.good())
	{
		ofile << name << "\n";
		for (const auto &process : finishedProcesses)
		{
			ofile << process.name;
		}
		ofile << "\n\n";
		for (const auto &process : finishedProcesses)
		{
			ofile << process;
		}
		ofile << "=======================\n";
	}
	else
	{
		std::cout << "An error occured while writing to out.txt\n";
		exit(EXIT_FAILURE);
	}
}
bool Scheduler::writtenToFiles = false;