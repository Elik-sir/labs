#include "Goose.h"
#include "Ostrich.h"
#include "Penguin.h"
#include "Farm.h"
int main()
{
    // Goose a("goose1", "Eldar", 20), b;
    Penguin p("num1", "p1", 2);
    Farm f;
    f.addAnimal(new Penguin("num1", "p1", 2));
    f.addAnimal(new Goose("num1123", "ewewe1", 2));
    // cout << b.getBodyColor() << " " << b.getPawsColor() << "  " << b.getWingsColor() << endl;
    cout << p.getBodyColor() << " " << p.getName() << "  " << p.getNumber() << endl;
    f.showAllAnimal();
    f.paintAll();
    f.showAllAnimal();
    return 0;
}