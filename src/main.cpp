#include <iostream>
#include "tcb-queue.h"
#include "simulator-configuration.h"

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Arquivo de configuração não informado" << std::endl;
        return 1;
    }

    SimulatorConfiguration *config = SimulatorConfiguration::get_instance();

    const char *configuration_file_path = argv[1];

    try
    {
        SimulatorConfiguration::load(configuration_file_path);
    }
    catch (std::exception const &ex)
    {
        std::cout << ex.what() << '\n';
    }

    config = SimulatorConfiguration::get_instance();

    std::cout << "é nulo: " << (config == NULL) << "\n";

    return 0;
}