#include "Goose.h"
#include "Ostrich.h"
#include "Penguin.h"
#include "Farm.h"
#include "FarmLoop.h"

/*
Номер - уникален для каждого животного, каждый номер существует в единственном экземляре на территории всей фермы
ДОП:
добавить всем животным(через класс Animal) свойства "продукция(максимум)", "продукция(на данный момент)"  и "скорость производства"
ВАЖНО: если продукция у животного достигла максимума, то дальнейшая продукция, произведенная им, не сохраняется
добавить систему времени на ферме(можно через отдельный класс, можно с привязкой к текущему времени)
добавить методы сбора продукции(со всех/с конкретного), суммирующие для каждого типа животных количество собранного
в ферму добавить общее число собранного(с возможностью обнулить значения самостоятельно или по прошествии определенного времени)
добавить выдачу сообщений от животных, если максимум продукции был произведен(можно в форме проверки животного, которая вернет сообщение вида
"максимальное значение продукции достигнуто"/"хранилище продукции заполнено на н процентов, максимум будет достигнут через м часов").
*/
int main()
{
    Penguin p("num1", "p1", 2);
    Farm f;

    Penguin *a = new Penguin("num1", "p1", 2);
    Penguin *b = new Penguin("num1123", "p1", 2);
    Goose *c = new Goose("goose", "ne_goose", 2);
    Ostrich *d = new Ostrich("num1", "ewewe1", 2, 45, 320);
    //  d->getInfo();
    // f.addAnimal(a);
    // f.addAnimal(b);
    // f.addAnimal(c);
    // f.addAnimal(d);
    // f.showAllAnimals();
    // f.paintAll();
    // f.showAllAnimals();
    a->collectProducts();
    a->collectProducts();
    a->printProductionInfo();
    a->collectProducts();
    a->collectProducts();
    a->printProductionInfo();
    a->collectProducts();
    a->collectProducts();
    a->printProductionInfo();
    a->collectProducts();
    a->printProductionInfo();
    //  f.showAllAnimals();
    // f.removeAnimal("num1123");
    //  f.showAllAnimals();
    // FarmLoop loop(&f);
    // loop.run();
    return 0;
}