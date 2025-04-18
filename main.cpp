//#include <iostream>
#include "all_classes.h"

using namespace std;



int main()
{
    SourceOfTrouble SoT;

    ObserverForWarnings OfW;
    ObserverForErrors OfE;
    ObserverForFatal OfF;

    SoT.AddObserver(&OfW);
    SoT.AddObserver(&OfE);
    SoT.AddObserver(&OfF);

    SoT.warning("Deprecated software is used.");
    SoT.error("Wrong source file!");
    SoT.fatalError("Out of memory!");

    std::cout << "\nAFTER REMOVING OBSERVER FOR WARNINGS\n";
    SoT.RemoveObserver(&OfW);

    SoT.warning("Inefficient use of resources detected.");
    SoT.error("File not available!");
    SoT.fatalError("No disk space!");

    return 0;
}
