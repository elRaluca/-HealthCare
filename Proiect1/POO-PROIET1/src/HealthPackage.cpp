#include "../headers/HealthPackage.h"
HealthPackage::HealthPackage(int _varsta, bool _servicii,int _valabilitate, bool _pensionar){
    this->varsta=_varsta;
    this->servicii=_servicii;
    this->valabilitate=_valabilitate;
    this->pensionar=_pensionar;
    this->pret=pret_calculat();
}
HealthPackage::HealthPackage(const HealthPackage& healthpackage) {
    this->varsta = healthpackage.varsta;
    this->servicii=healthpackage.servicii;
    this->valabilitate=healthpackage.valabilitate;
    this->pensionar=healthpackage.pensionar;
    this->pret=pret_calculat();
}
std::istream & operator>>(std::istream & in, HealthPackage & empty) {
    in>>empty.varsta>>empty.servicii>>empty.valabilitate>>empty.pensionar;
    return in;
}
int HealthPackage::getVarsta() const {
    return varsta;
}
bool HealthPackage::isServicii() const {
    return servicii;
}
int HealthPackage::getValabilitate() const {
    return valabilitate;
}
bool HealthPackage::isPensionar() const {
    return pensionar;
}
std::ostream& operator<<(std::ostream& out, HealthPackage& c){
    out<<"\n"<<c.varsta<<"\n"<<c.servicii<<"\n"<<c.valabilitate<<"\n"<<c.pensionar<<"\n"<<" "<<"\n";
    return out;
}
float HealthPackage::pret_calculat() {
    if (valabilitate == 1)
        pret = 300;
    if (valabilitate == 3)
        pret = 790.99;
    if (valabilitate == 12)
        pret = 2900;

    if (varsta<=16 && servicii == 0)
        pret = 0;
    if (varsta<=16 && servicii == 1)
        pret = pret -(pret/100)* 15;
    if (varsta<=25 && varsta>16 && servicii == 0)
        pret = pret - (pret/100)* 15;
    if (varsta<=25 && varsta>16 && servicii == 1)
        pret = pret - (pret/100)* 20;
    if (varsta<=50 && varsta>25 && servicii == 0)
        pret = pret - (pret/100) * 5;
    if (varsta<=50 && varsta>25 && servicii == 1)
        pret = pret -(pret/100)*15;
    if (pensionar == 1 && servicii == 0)
        pret = pret - (pret/100)* 35;
    if (pensionar==1 && servicii==1)
        pret = pret - (pret/100)* 45;

    return pret;
}
void HealthPackage::setPret(float pret) {
    HealthPackage::pret=pret;
}
float HealthPackage::getPret() const {
    return pret;

}