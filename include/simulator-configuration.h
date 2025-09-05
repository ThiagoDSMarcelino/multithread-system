#ifndef SIMULATOR_CONFIGURATION_H
#define SIMULATOR_CONFIGURATION_H

#include "scheduler.h"
#include <vector>

enum SimulatorConfigurationErrors
{
    FILE_NOT_FOUND,
    INCORRECT_FILE_FORMAT,
    INVALID_QUANTUM_VALUE,
    QUANTUM_LESS_THAN_1,
};

class SimulatorConfiguration
{
private:
    SimulatorConfiguration(Scheduler *scheduler, int quantum, std::vector<TaskControlBlock *> tasks);
    ~SimulatorConfiguration();
    Scheduler *scheduler;
    int quantum;
    std::vector<TaskControlBlock *> tasks;
    static SimulatorConfiguration *instance;

public:
    static void load(const char *path);
    static SimulatorConfiguration *get_instance();
};

#endif