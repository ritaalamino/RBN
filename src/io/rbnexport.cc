// Copyright 2019 COPT

#include <fstream>
#include <iostream>

#include "network/rbn.h"
#include "io/rbnexport.h"

namespace rbn {
namespace io {
void rbnexport(network::RBN net) {
    std::ofstream outfile("output.txt");
    outfile << "State transition: " << std::endl;
    for (int i = 0; i < net.getSize(); i++) {
        for (int j = 0; j < net.getSize(); j++) {
            outfile << net.getTransitions()[i][j].getState();
        }
        outfile << std::endl;
    }

    outfile << "Network conections: " << std::endl;
    for (int i = 0; i < net.getSize(); i++) {
        for (int j = 0; j < net.getSize(); j++) {
            outfile << net.getConnections()[i][j];
        }
        outfile << std::endl;
    }

    outfile << "Logic pattern: " << std::endl;
    int i = 0;
    for (std::vector<int> row : net.getLogicFunctions()) {
        outfile << i << " - ";
        i++;
        for (int cel : row) {
            outfile << cel;
        }
        outfile << std::endl;
    }
    outfile << "Dictionary: " << std::endl;
    outfile << "0 - AND " << std::endl;
    outfile << "1 - OR " << std::endl;
    outfile << "2 - XOR " << std::endl;
    outfile << "3 - NOT A " << std::endl;
    outfile << "4 - XNOR " << std::endl;
    outfile << "5 - NAND " << std::endl;
    outfile << "6 - NOR " << std::endl;
    outfile.close();
}
}  // namespace io
}  // namespace rbn
