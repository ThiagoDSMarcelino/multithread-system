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
    catch (const SimulatorConfigurationErrors e)
    {
        switch (e)
        {
        case SimulatorConfigurationErrors::FILE_NOT_FOUND:
            std::cerr << "Arquivo de configuração não encontrado" << std::endl;
            break;

        case SimulatorConfigurationErrors::INCORRECT_FILE_FORMAT:
            std::cerr << "Formatação do arquivo de configuração está incorreta" << std::endl;
            break;

        case SimulatorConfigurationErrors::INVALID_QUANTUM_VALUE:
            std::cerr << "Valor do quantum é inválido" << std::endl;
            break;

        case SimulatorConfigurationErrors::QUANTUM_LESS_THAN_1:
            std::cerr << "Valor do quantum é menor que 1" << std::endl;
            break;

        default:
            std::cerr << "Error ao carregar configuração" << std::endl;
            break;
        }
    }

    config = SimulatorConfiguration::get_instance();

    std::cout << "é nulo: " << (config == NULL) << "\n";

    return 0;
}