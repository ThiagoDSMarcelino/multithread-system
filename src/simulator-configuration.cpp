#include "simulator-configuration.h"

#include "utils.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <format>
#include <algorithm>

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

Scheduler *get_scheduler(std::string name)
{
    if (name != "round_robin")
    {
        throw std::runtime_error("Nome do escalonador é inválido");
    }

    return NULL;
}

int get_quantum(std::string value)
{
    int quantum;
    if (!try_parse_int(value, quantum))
    {
        throw std::runtime_error("Valor do quantum é inválido");
    }

    if (quantum < 1)
    {
        throw std::runtime_error("Valor do quantum é menor que 1");
    }

    return quantum;
}

int get_id(std::string value, std::vector<int> *used_ids)
{
    int id;
    if (!try_parse_int(value, id))
    {
        throw std::runtime_error(std::format("Valor {} não é valido como ID, apenas números são aceitos", value));
    }

    if (id < 1)
    {
        throw std::runtime_error("Somente valores positivos são aceitos como ID de uma tarefa");
    }

    if (std::find(used_ids->begin(), used_ids->end(), id) != used_ids->end())
    {
        throw std::runtime_error(std::format("ID {} está duplicado", id));
    }

    used_ids->push_back(id);

    return id;
}

std::string get_color(std::string value)
{
    if (!is_color(value))
    {
        throw std::runtime_error(std::format("A cor {} é inválida", value));
    }

    return value;
}

void SimulatorConfiguration::load(const char *path)
{
    std::ifstream configuration_file;
    configuration_file.open(path, std::ios::in);

    if (!configuration_file.is_open())
    {
        throw std::invalid_argument("Arquivo não encontrado");
    }

    std::string line;

    if (!std::getline(configuration_file, line))
    {
        throw std::runtime_error("Formatação do arquivo de configuração está incorreta");
    }

    std::vector<std::string> values = split(line, ";");

    if (values.size() != 2)
    {
        throw std::runtime_error("Formatação de uma tarefa está incorreto");
    }

    Scheduler *scheduler = get_scheduler(values[0]);
    int quantum = get_quantum(values[1]);

    int id;
    std::vector<int> used_ids;

    std::string color;

    TaskControlBlock *task;
    std::vector<TaskControlBlock *> tasks;

    while (std::getline(configuration_file, line))
    {
        values = split(line, ";");

        if (values.size() < 5 || values.size() > 6)
        {
            throw std::runtime_error("Formatação de uma tarefa está incorreto");
        }

        id = get_id(values[0], &used_ids);
        color = get_color(values[1]);

        task = new TaskControlBlock(id, color, 0, 5, 2, NULL);
        tasks.push_back(task);
    }

    for (auto task : tasks)
    {
        std::cout << task->get_id() << " " << task->get_priority() << std::endl;
    }

    configuration_file.close();

    SimulatorConfiguration *configuration = new SimulatorConfiguration(nullptr, quantum, tasks);
}

SimulatorConfiguration *SimulatorConfiguration::get_instance()
{
    return instance;
}