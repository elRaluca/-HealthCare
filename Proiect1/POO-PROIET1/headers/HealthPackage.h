#ifndef UNTITLED6_HEALTHPACKAGE_H
#define UNTITLED6_HEALTHPACKAGE_H
#include <iostream>
class HealthPackage{
private:
    int varsta;
    bool servicii;
    int valabilitate;
    bool pensionar;
    float pret;public:
    HealthPackage()=default;
    HealthPackage(int _varsta, bool _servicii, int _valabilitate, bool _pensionar);
    ~HealthPackage()=default;
    HealthPackage(const HealthPackage& HealthPackage);
    friend std::istream& operator>>(std::istream& in, HealthPackage& empty);
    friend std::ostream& operator<<(std::ostream& out, HealthPackage& client);
    int getVarsta() const;
    bool isServicii() const;
    int getValabilitate() const;
    bool isPensionar() const;
    float getPret() const;
    void setPret(float pret);
    float pret_calculat();
};
#endif //UNTITLED6_HEALTHPACKAGE_H
