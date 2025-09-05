#ifndef SIMULATOR_CONFIGURATION_H
#define SIMULATOR_CONFIGURATION_H

#include "scheduler.h"
#include <vector>

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