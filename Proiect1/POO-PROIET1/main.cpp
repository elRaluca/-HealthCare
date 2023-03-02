#include <iostream>
#include "headers/HealthPackage.h"
int main() {
    HealthPackage empty;
    std::cin >> empty;
    std::cout << "\n" << empty.getVarsta() << "\n" << empty.isServicii() << "\n" << empty.getValabilitate() << "\n"
              << empty.isPensionar() << "\n";
    HealthPackage client(23, true, 3, false);
    HealthPackage happyClient(47, false, 3, false);
    HealthPackage curiousClient(77, false, 12, true);
    std::cout << client << happyClient << curiousClient;
    empty.setPret(empty.pret_calculat());
    std::cout << "\n" << empty.getPret() << "\n";
    HealthPackage clienti[] = {client, happyClient, curiousClient};
    for (HealthPackage pachet: clienti) {
        std::cout << pachet.getPret() << "\n";
    }
}