#ifndef BALCONIES_VALUES_H
#define BALCONIES_VALUES_H

#include <iostream>
#include <memory>

namespace Calculator {
    class WindowSizes {
    public:
        WindowSizes() = default;

        ~WindowSizes() = default;

        WindowSizes(double &square, double price, double &summaryCost) : square(&square), price(price), summaryCost(&summaryCost) {};

        void updateServiceCost();

        void setPrice(double newPrice);

        void setWidth(double newWidth);

        void setLowerRowHeight(double newLowerRowHeight);

        void setUpperRowHeight(double newUpperRowHeight);

        void setSquare(double newSquare);

        double getWidth();

        double getLowerRowHeight();

        double getUpperRowHeight();

        double getSquare();

    private:
        double windowWidth = 0;
        double lowerRowHeight = 0;
        double upperRowHeight = 0;
        double price;
        double serviceCost = 0;
        double *square;
        double *summaryCost;

    };

    class Profile {
    public:
        Profile() = default;

        ~Profile() = default;

        Profile(double &square, double &summaryCost) : square(&square), summaryCost(&summaryCost) {};

        void updateServiceCost();

        void setProfileAndPrice(std::string newProfile, double newPrice);


    private:
        double *square;
        double *summaryCost;
        std::string profile = "Blitz";
        double price = 100;
        double serviceCost = 0;
    };

    class NumberOfOpenings {
    public:
        NumberOfOpenings() = default;

        ~NumberOfOpenings() = default;

        NumberOfOpenings(double &summaryCost) : summaryCost(&summaryCost) {};

        void updateServiceCost();

        void setNumberOfOpenings(int newNumberOfOpenings);

        int getNumberOfOpenings();

    private:
        double *summaryCost;
        int numberOfOpenings = 0;
        double price = 100;
        double serviceCost = 0;
    };

    class Lamination {
    public:
        Lamination() = default;

        ~Lamination() = default;

        Lamination(double &square, double &summaryCost) : square(&square), summaryCost(&summaryCost) {};

        void updateServiceCost();

        void setLaminationAndPrice(std::string newLamination, double newPrice);

    private:
        double *summaryCost;
        double* square;
        std::string lamination = "Bel/Bel";
        double price = 0;
        double serviceCost = 0;
    };

    class DoubleGlazing {
    public:
        DoubleGlazing() = default;

        ~DoubleGlazing() = default;

        DoubleGlazing(double &square, double &summaryCost) : square(&square), summaryCost(&summaryCost) {};

        void updateServiceCost();

        void setDoubleGlazingAndPrice(std::string newDoubleGlazing, double newPrice);

    private:
        double* square;
        double* summaryCost;
        std::string doubleGlazing = "12";
        double price = 0;
        double serviceCost = 0;
    };


    class Toning {
    public:
        Toning() = default;

        ~Toning() = default;

        Toning(WindowSizes &windowSizes, double &summaryCost, double price) : windowSizes(&windowSizes), summaryCost(&summaryCost), price(price) {};

        void updateUsableSquare();

        void updateServiceCost();

        void setToning(std::string newToning);

    private:
        WindowSizes* windowSizes;
        double* summaryCost;
        std::string toning = "Нет";
        double usableSquare = 0;
        double price;
        double serviceCost = 0;
    };


    class BulkToning {
    public:
        BulkToning() = default;

        ~BulkToning() = default;

        BulkToning(WindowSizes &windowSizes, double &summaryCost) : windowSizes(&windowSizes), summaryCost(&summaryCost) {};

        void updateUsableSquare();

        void updateServiceCost();

        void setBulkToning(std::string newBulkToning);

        void setMaterialAndPrice(std::string newMaterial, double newPrice);

    private:
        WindowSizes* windowSizes;
        double* summaryCost;
        std::string bulkToning = "Нет";
        std::string material = "Нет";
        double usableSquare = 0;
        double price = 0;
        double serviceCost = 0;
    };


    class MosquitoNet {
    public:
        MosquitoNet() = default;

        ~MosquitoNet() = default;

        MosquitoNet(double &summaryCost, double price) : summaryCost(&summaryCost), price(price) {};

        void updateServiceCost();

        void setMosquitoNet(int newMosquitoNet);


    private:
        double* summaryCost;
        int mosquitoNet = 0;
        double price;
        double serviceCost = 0;
    };

    class Triplex {
    public:
        Triplex() = default;

        ~Triplex() = default;

        Triplex(WindowSizes &windowSizes, double &summaryCost) : windowSizes(&windowSizes), summaryCost(&summaryCost) {};

        void updateUsableSquare();

        void updateServiceCost();

        void setTriplex(std::string newTriplex);

        void setMaterialAndPrice(std::string newMaterial, double newPrice);

    private:
        WindowSizes* windowSizes;
        double* summaryCost;
        std::string triplex = "Нет";
        std::string material = "Нет";
        double usableSquare = 0;
        double price = 0;
        double serviceCost = 0;
    };

    class Handles {
    public:
        Handles() = default;

        ~Handles() = default;

        Handles(double &summaryCost) : summaryCost(&summaryCost) {};

        void updateServiceCost();

        void setHandlesAndPrice(std::string newHandles, double newPrice);

    private:
        double* summaryCost;
        std::string handles = "Interika";
        double price = 0;
        double serviceCost = 0;
    };
}
#endif //BALCONIES_VALUES_H
