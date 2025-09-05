#include "simulator-configuration.h"
#include "utils.cpp"

#include <fstream>
#include <iostream>

SimulatorConfiguration *SimulatorConfiguration::instance = nullptr;

SimulatorConfiguration::SimulatorConfiguration(Scheduler *scheduler, int quantum, std::vector<TaskControlBlock *> tasks)
{
    this->tasks = tasks;
    this->scheduler = scheduler;
    this->quantum = quantum;
    this->instance = this;
}

SimulatorConfiguration::~SimulatorConfiguration()
{
    delete this->scheduler;
}

void SimulatorConfiguration::load(const char *path)
{
    std::ifstream configuration_file;
    configuration_file.open(path, std::ios::in);

    if (!configuration_file.is_open())
    {
        throw SimulatorConfigurationErrors::FILE_NOT_FOUND;
    }

    std::string line;

    if (!std::getline(configuration_file, line))
    {
        throw SimulatorConfigurationErrors::INCORRECT_FILE_FORMAT;
    }

    std::vector<std::string> values = split(line, ";");

    if (values.size() != 2)
    {
        throw SimulatorConfigurationErrors::INCORRECT_FILE_FORMAT;
    }

    std::string scheduler_name = values[0];
    int quantum;

    if (!try_parse_int(values[1], quantum))
    {
        throw SimulatorConfigurationErrors::INVALID_QUANTUM_VALUE;
    }

    if (quantum < 1)
    {
        throw SimulatorConfigurationErrors::QUANTUM_LESS_THAN_1;
    }

    // std::cout << "scheduler name: " << scheduler_name << " | quantum: " << quantum << std::endl;

    std::vector<TaskControlBlock *> tasks;
    while (std::getline(configuration_file, line))
    {
        std::cout << line << std::endl;
    }

    configuration_file.close();

    SimulatorConfiguration *configuration = new SimulatorConfiguration(nullptr, 200, tasks);
}

SimulatorConfiguration *SimulatorConfiguration::get_instance()
{
    return instance;
}