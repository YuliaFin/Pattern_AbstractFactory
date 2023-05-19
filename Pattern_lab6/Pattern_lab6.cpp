#include <iostream>
using namespace std;

// Абстрактная структура Суп
struct Soup {
    virtual void cook() = 0;
};

// Конкретные структуры супов
struct BorschSoup : Soup {
    void cook() {
        cout << "Cooking Borsch soup" << endl;
    }
};

struct PumpkinSoup : Soup {
    void cook() {
        cout << "Cooking Pumpkin soup" << endl;
    }
};

struct OkroshkaSoup : Soup {
    void cook() {
        cout << "Cooking Okroshka soup" << endl;
    }
};

// Абстрактная структура Второе блюдо
struct MainCourse {
    virtual void prepare() = 0;
};

// Конкретные структуры вторых блюд
struct FriedPotatoes : MainCourse {
    void prepare() {
        cout << "Cooking Fried Potatoes" << endl;
    }
};

struct Cutlet : MainCourse {
    void prepare() {
        cout << "Cooking Cutlet" << endl;
    }
};

struct Pudding : MainCourse {
    void prepare() {
        cout << "Cooking Pudding" << endl;
    }
};

// Абстрактная структура Десерт
struct Dessert {
    virtual void make() = 0;
};

// Конкретные структуры десертов
struct ChocolateCake : Dessert {
    void make() {
        cout << "Cooking Chocolate Cake" << endl;
    }
};

struct FruitSalad : Dessert {
    void make() {
        cout << "Cooking Fruit Salad" << endl;
    }
};

struct IceCream : Dessert {
    void make() {
        cout << "Cooking Ice Cream" << endl;
    }
};

// Абстрактная фабрика
struct AbstractDietFactory {
    virtual Soup* createSoup() = 0;
    virtual MainCourse* createMainCourse() = 0;
    virtual Dessert* createDessert() = 0;
};

// Конкретные фабрики диет
struct MeatDietFactory : AbstractDietFactory {
    Soup* createSoup() {
        return new BorschSoup();
    }

    MainCourse* createMainCourse() {
        return new Cutlet();
    }

    Dessert* createDessert() {
        return new ChocolateCake();
    }
};

struct VegetarianDietFactory : AbstractDietFactory {
    Soup* createSoup() {
        return new PumpkinSoup();
    }

    MainCourse* createMainCourse() {
        return new FriedPotatoes();
    }

    Dessert* createDessert() {
        return new FruitSalad();
    }
};

struct KefirDietFactory : AbstractDietFactory {
    Soup* createSoup() {
        return new OkroshkaSoup();
    }

    MainCourse* createMainCourse() {
        return new Pudding();
    }

    Dessert* createDessert() {
        return new IceCream();
    }
};

int main() {
    // Создаем диету по паттерну Abstract Factory
    AbstractDietFactory* vegetarianDietFactory = new VegetarianDietFactory();
    AbstractDietFactory* meatDietFactory = new MeatDietFactory();
    AbstractDietFactory* kefirDietFactory = new KefirDietFactory();

    // Создаем суп, второе блюдо и десерт с помощью фабрик
    Soup* vegetarianSoup = vegetarianDietFactory->createSoup();
    MainCourse* vegetarianMainCourse = vegetarianDietFactory->createMainCourse();
    Dessert* vegetarianDessert = vegetarianDietFactory->createDessert();

    Soup* meatSoup = meatDietFactory->createSoup();
    MainCourse* meatMainCourse = meatDietFactory->createMainCourse();
    Dessert* meatDessert = meatDietFactory->createDessert();

    Soup* kefirSoup = kefirDietFactory->createSoup();
    MainCourse* kefirMainCourse = kefirDietFactory->createMainCourse();
    Dessert* kefirDessert = kefirDietFactory->createDessert();

    // Cуп, второе блюдо и десерт для вегетарианской диеты
    cout << "Vegetarian Diet:" << endl;
    vegetarianSoup->cook();
    vegetarianMainCourse->prepare();
    vegetarianDessert->make();
    cout << endl;

    // Cуп, второе блюдо и десерт для мясной диеты
    cout << "Meat Diet:" << endl;
    meatSoup->cook();
    meatMainCourse->prepare();
    meatDessert->make();
    cout << endl;

    // Cуп, второе блюдо и десерт для кефирной диеты
    cout << "Kefir Diet:" << endl;
    kefirSoup->cook();
    kefirMainCourse->prepare();
    kefirDessert->make();
    cout << endl;

    // Освобождение ресурсов
    delete vegetarianDietFactory;
    delete meatDietFactory;
    delete kefirDietFactory;
    delete vegetarianSoup;
    delete vegetarianMainCourse;
    delete vegetarianDessert;
    delete meatSoup;
    delete meatMainCourse;
    delete meatDessert;
    delete kefirSoup;
    delete kefirMainCourse;
    delete kefirDessert;

    return 0;
}