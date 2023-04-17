#ifndef BALCONIES_WINDOW_SYSTEM_H
#define BALCONIES_WINDOW_SYSTEM_H

#include "window_system_values.h"

namespace Calculator {
    class WindowSystem {
    public:
        WindowSystem() = default;

        ~WindowSystem() = default;

        WindowSystem(double &grandTotal) : grandTotal(&grandTotal) {};

        double getWindowSystemCost();

        double getWindowSystemSquare();

        double getWindowSizesServiceCost();

        double getProfileServiceCost();

        double getNumberOfOpeningsServiceCost();

        double getLaminationServiceCost();

        double getDoubleGlazingServiceCost();

        double getToningServiceCost();

        double getBulkToningServiceCost();

        double getMosquitoNetServiceCost();

        double getTriplexServiceCost();

        double getHandlesServiceCost();

        void updateSizes();

        void setWindowSizesWidth(double newWidth);

        void setWindowSizesLowerRowHeight(double newLowerRowHeight);

        void setWindowSizesUpperRowHeight(double newUpperRowHeight);

        void setProfileAndPrice(std::string newProfile, double newPrice);

        void setNumberOfOpenings(int newNumberOfOpenings);

        void setLaminationAndPrice(std::string newLamination, double newPrice);

        void setDoubleGlazingAndPrice(std::string newDoubleGlazing, double newPrice);

        void setToning(std::string newToning);

        void setBulkToning(std::string newBulkToning);

        void setBulkToningMaterialAndPrice(std::string newBulkToningMaterial, double newPrice);

        void setMosquitoNet(int newMosquitoNet);

        void setTriplex(std::string newTriplex);

        void setTriplexMaterialAndPrice(std::string newTriplexMaterial, double newPrice);

        void setHandlesAndPrice(std::string newHandles, double newPrice);

    private:
        double *grandTotal;
        double windowSystemCost = 0;
        double windowSystemSquare = 0;
        WindowSizes windowSizes = WindowSizes(windowSystemSquare, 1961, windowSystemCost);
        Profile profile = Profile(windowSystemSquare, windowSystemCost);
        NumberOfOpenings numberOfOpenings = NumberOfOpenings(windowSystemCost);
        Lamination lamination = Lamination(windowSystemSquare, windowSystemCost);
        DoubleGlazing doubleGlazing = DoubleGlazing(windowSystemSquare, windowSystemCost);
        Toning toning = Toning(windowSizes, windowSystemCost, 4725);
        BulkToning bulkToning = BulkToning(windowSizes, windowSystemCost);
        MosquitoNet mosquitoNet = MosquitoNet(windowSystemCost, 2570);
        Triplex triplex = Triplex(windowSizes, windowSystemCost);
        Handles handles = Handles(windowSystemCost);
    };
}
#endif //BALCONIES_WINDOW_SYSTEM_H
