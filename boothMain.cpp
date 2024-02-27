
#include "fileInputOutput.h"
/**
 * @brief
 *
 * @return int
 */
int main()
{
    std::cout << "Choose an option:\n";
    std::cout << "1. Read input from file, perform Booth's Algorithm, and write output files\n";
    std::cout << "2. Take input from User and perform Booth's Algorithm \n";
    std::cout << "3. Set multiplicand and multiplier using setters \n";
    int option;
    int mcand = 0;
    int mplier = 0;
    int mcandBinary[10], mplierBinary[10] = {0};
    int length = 8;

    std::cin >> option;

    Multiplication m(0, 0, 0);

    if (option == 1)
    {
        std::vector<Multiplication> multiplications;
        getData(multiplications, "input.txt");
        std::ofstream outputFile("output.txt", std::ios::trunc); // Open the output file in overwrite mode

        if (outputFile.is_open())
        {
            for (const Multiplication &m : multiplications)
            {
                m.writeOutputToFile(outputFile);
            }

            outputFile.close();
        }
        else
        {
            std::cerr << "Failed to open output file." << std::endl;
        }
    }
    else if (option == 2)
    {
        std::cout << "You selected Option 2.\n";
        m.performBoothAlgorithmUserInput();
    }
    else if(option == 3)
    {
        std::cout << "You selected Option 3.\n";
       // This option is valid for positive numbers only
        std::cout << "Mutator functions to set multiplicand and multiplier\n";

        m.setMultiplicand(mcand);
        m.setMultiplier(mplier);
        
        std::cout << "Accessor functions to get multiplicand and multiplier\n";
        std::cout << "Muliplicand=" << m.getMultiplicand();
        
        std::cout << "\nMultiplicand in binary: ";
        m.decimalToBinary(m.getMultiplicand(), mcandBinary, length);
        for (int i = 0; i < length; i++)
        {
            std::cout << mcandBinary[i];
        }
        std::cout << endl;

        cout << "Muliplier=" << m.getMultiplier();
        cout << "\nMultiplier in binary: ";
        m.decimalToBinary(m.getMultiplier(), mplierBinary, length);

        for (int j = 0; j < length; j++)
        {
            std::cout << mplierBinary[j];
        }
        std::cout << endl;
    }
    else
    {
        std::cout << "Invalid option selected " << std::endl;
    }

    return 0;
}
