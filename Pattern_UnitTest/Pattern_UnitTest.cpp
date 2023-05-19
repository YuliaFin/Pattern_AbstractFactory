#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pattern_lab6\Pattern_lab6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPattern
{
    TEST_CLASS(DietFactoryTests)
    {
    public:
        // Тест для проверки создания вегетарианской диеты
        TEST_METHOD(TestVegetarianDiet)
        {
            AbstractDietFactory* vegetarianDietFactory = new VegetarianDietFactory();

            Soup* vegetarianSoup = vegetarianDietFactory->createSoup();
            MainCourse* vegetarianMainCourse = vegetarianDietFactory->createMainCourse();
            Dessert* vegetarianDessert = vegetarianDietFactory->createDessert();

            Assert::IsNotNull(vegetarianSoup);
            Assert::IsNotNull(vegetarianMainCourse);
            Assert::IsNotNull(vegetarianDessert);
            //Проверка, что объекты, которые созданы с помощью фабрик, успешно инициализированы и не равны nullptr

            delete vegetarianDietFactory;
            delete vegetarianSoup;
            delete vegetarianMainCourse;
            delete vegetarianDessert;
        }


        // Тест для проверки создания мясной диеты
        TEST_METHOD(TestMeatDiet)
        {
            AbstractDietFactory* meatDietFactory = new MeatDietFactory();

            Soup* meatSoup = meatDietFactory->createSoup();
            MainCourse* meatMainCourse = meatDietFactory->createMainCourse();
            Dessert* meatDessert = meatDietFactory->createDessert();

            Assert::IsNotNull(meatSoup);
            Assert::IsNotNull(meatMainCourse);
            Assert::IsNotNull(meatDessert);

            delete meatDietFactory;
            delete meatSoup;
            delete meatMainCourse;
            delete meatDessert;
        }

        // Тест для проверки создания кефирной диеты
        TEST_METHOD(TestKefirDiet)
        {
            AbstractDietFactory* kefirDietFactory = new KefirDietFactory();

            Soup* kefirSoup = kefirDietFactory->createSoup();
            MainCourse* kefirMainCourse = kefirDietFactory->createMainCourse();
            Dessert* kefirDessert = kefirDietFactory->createDessert();

            Assert::IsNotNull(kefirSoup);
            Assert::IsNotNull(kefirMainCourse);
            Assert::IsNotNull(kefirDessert);

            delete kefirDietFactory;
            delete kefirSoup;
            delete kefirMainCourse;
            delete kefirDessert;
        }
    };
}
