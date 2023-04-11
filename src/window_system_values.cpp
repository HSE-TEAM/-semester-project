#include "window_system_values.h"

namespace Calculator {

    void WindowSizes::setPrice(double newPrice) {
        WindowSizes::price = newPrice;
        updateServiceCost();
    }

    void WindowSizes::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = *square * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void WindowSizes::setWidth(double newWidth) {
        WindowSizes::windowWidth = newWidth;
        setSquare(newWidth * (getLowerRowHeight() + getUpperRowHeight()));
    }

    void WindowSizes::setLowerRowHeight(double newLowerRowHeight) {
        WindowSizes::lowerRowHeight = newLowerRowHeight;
        setSquare(getWidth() * (newLowerRowHeight + getUpperRowHeight()));
    }

    void WindowSizes::setUpperRowHeight(double newUpperRowHeight) {
        WindowSizes::upperRowHeight = newUpperRowHeight;
        setSquare(getWidth() * (getLowerRowHeight() + newUpperRowHeight));
    }

    void WindowSizes::setSquare(double newSquare) {
        *WindowSizes::square = newSquare;
        updateServiceCost();
    }

    double WindowSizes::getWidth() {
        return windowWidth;
    }

    double WindowSizes::getLowerRowHeight() {
        return lowerRowHeight;
    }

    double WindowSizes::getUpperRowHeight() {
        return upperRowHeight;
    }

    double WindowSizes::getSquare() {
        return *square;
    }

    void Profile::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = *square * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void Profile::setProfileAndPrice(std::string newProfile, double newPrice) {
        profile = newProfile;
        price = newPrice;
        updateServiceCost();
    }

    void NumberOfOpenings::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = numberOfOpenings * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void NumberOfOpenings::setNumberOfOpenings(int newNumberOfOpenings) {
        numberOfOpenings = newNumberOfOpenings;
        updateServiceCost();
    }

    void Lamination::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = *square * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void Lamination::setLaminationAndPrice(std::string newLamination, double newPrice) {
        lamination = newLamination;
        price = newPrice;
        updateServiceCost();
    }

    void DoubleGlazing::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = *square * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void DoubleGlazing::setDoubleGlazingAndPrice(std::string newDoubleGlazing, double newPrice) {
        doubleGlazing = newDoubleGlazing;
        price = newPrice;
        updateServiceCost();
    }

    void Toning::updateUsableSquare() {
        if (toning == "Верх") {
            usableSquare = windowSizes->getUpperRowHeight() * windowSizes->getWidth();
        } else if (toning == "Низ") {
            usableSquare = windowSizes->getLowerRowHeight() * windowSizes->getWidth();
        } else if (toning == "Всё") {
            usableSquare =
                    (windowSizes->getUpperRowHeight() + windowSizes->getLowerRowHeight()) * windowSizes->getWidth();
        } else {
            usableSquare = 0;
        }
    }

    void Toning::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = usableSquare * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void Toning::setToning(std::string newToning) {
        toning = newToning;
        updateUsableSquare();
        updateServiceCost();
    }

    void BulkToning::updateUsableSquare() {
        if (bulkToning == "Верх") {
            usableSquare = windowSizes->getUpperRowHeight() * windowSizes->getWidth();
        } else if (bulkToning == "Низ") {
            usableSquare = windowSizes->getLowerRowHeight() * windowSizes->getWidth();
        } else if (bulkToning == "Всё") {
            usableSquare =
                    (windowSizes->getUpperRowHeight() + windowSizes->getLowerRowHeight()) * windowSizes->getWidth();
        } else {
            usableSquare = 0;
        }
    }

    void BulkToning::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = usableSquare * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void BulkToning::setBulkToning(std::string newBulkToning) {
        bulkToning = newBulkToning;
        updateUsableSquare();
        updateServiceCost();
    }

    void BulkToning::setMaterialAndPrice(std::string newMaterial, double newPrice) {
        material = newMaterial;
        price = newPrice;
        updateServiceCost();
    }

    void MosquitoNet::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = mosquitoNet * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void MosquitoNet::setMosquitoNet(int newMosquitoNet) {
        mosquitoNet = newMosquitoNet;
        updateServiceCost();
    }

    void Triplex::updateUsableSquare() {
        if (triplex == "Верх") {
            usableSquare = windowSizes->getUpperRowHeight() * windowSizes->getWidth();
        } else if (triplex == "Низ") {
            usableSquare = windowSizes->getLowerRowHeight() * windowSizes->getWidth();
        } else if (triplex == "Всё") {
            usableSquare =
                    (windowSizes->getUpperRowHeight() + windowSizes->getLowerRowHeight()) * windowSizes->getWidth();
        } else {
            usableSquare = 0;
        }
    }

    void Triplex::updateServiceCost() {
        double oldServiceCost = serviceCost;
        serviceCost = usableSquare * price;
        *summaryCost += serviceCost - oldServiceCost;
    }

    void Triplex::setTriplex(std::string newTriplex) {
        triplex = newTriplex;
        updateUsableSquare();
        updateServiceCost();
    }

    void Triplex::setMaterialAndPrice(std::string newMaterial, double newPrice) {
        material = newMaterial;
        price = newPrice;
        updateServiceCost();
    }


    void Handles::updateServiceCost() {
        *summaryCost += price - serviceCost;
        serviceCost = price;
    }

    void Handles::setHandlesAndPrice(std::string newHandles, double newPrice) {
        handles = newHandles;
        price = newPrice;
        updateServiceCost();
    }
}