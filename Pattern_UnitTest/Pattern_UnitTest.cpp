#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pattern_lab6\Pattern_lab6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPattern
{
    TEST_CLASS(DietFactoryTests)
    {
    public:
        // ���� ��� �������� �������� �������������� �����
        TEST_METHOD(TestVegetarianDiet)
        {
            AbstractDietFactory* vegetarianDietFactory = new VegetarianDietFactory();

            Soup* vegetarianSoup = vegetarianDietFactory->createSoup();
            MainCourse* vegetarianMainCourse = vegetarianDietFactory->createMainCourse();
            Dessert* vegetarianDessert = vegetarianDietFactory->createDessert();

            Assert::IsNotNull(vegetarianSoup);
            Assert::IsNotNull(vegetarianMainCourse);
            Assert::IsNotNull(vegetarianDessert);
            //��������, ��� �������, ������� ������� � ������� ������, ������� ���������������� � �� ����� nullptr

            delete vegetarianDietFactory;
            delete vegetarianSoup;
            delete vegetarianMainCourse;
            delete vegetarianDessert;
        }


        // ���� ��� �������� �������� ������ �����
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

        // ���� ��� �������� �������� �������� �����
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
