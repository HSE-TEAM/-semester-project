#include "window_system.h"

namespace Calculator {

    double WindowSystem::getWindowSystemCost() {
        return windowSystemCost;
    }

    double WindowSystem::getWindowSystemSquare() {
        return windowSystemSquare;
    }

    double WindowSystem::getWindowSizesServiceCost() {
        return windowSizes.getServiceCost();
    }

    double WindowSystem::getProfileServiceCost() {
        return profile.getServiceCost();
    }

    double WindowSystem::getNumberOfOpeningsServiceCost() {
        return numberOfOpenings.getServiceCost();
    }

    double WindowSystem::getLaminationServiceCost() {
        return lamination.getServiceCost();
    }

    double WindowSystem::getDoubleGlazingServiceCost() {
        return doubleGlazing.getServiceCost();
    }

    double WindowSystem::getToningServiceCost() {
        return toning.getServiceCost();
    }

    double WindowSystem::getBulkToningServiceCost() {
        return bulkToning.getServiceCost();
    }

    double WindowSystem::getMosquitoNetServiceCost() {
        return mosquitoNet.getServiceCost();
    }

    double WindowSystem::getTriplexServiceCost() {
        return triplex.getServiceCost();
    }

    double WindowSystem::getHandlesServiceCost() {
        return handles.getServiceCost();
    }

    void WindowSystem::updateSizes() {
        profile.updateServiceCost();
        lamination.updateServiceCost();
        doubleGlazing.updateServiceCost();
        toning.updateUsableSquare();
        toning.updateServiceCost();
        bulkToning.updateUsableSquare();
        bulkToning.updateServiceCost();
        triplex.updateUsableSquare();
        triplex.updateServiceCost();
    }

    void WindowSystem::setWindowSizesWidth(double newWidth) {
        double oldWindowSystemCost = windowSystemCost;
        windowSizes.setWidth(newWidth);
        updateSizes();
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setWindowSizesLowerRowHeight(double newLowerRowHeight) {
        double oldWindowSystemCost = windowSystemCost;
        windowSizes.setLowerRowHeight(newLowerRowHeight);
        updateSizes();
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setWindowSizesUpperRowHeight(double newUpperRowHeight) {
        double oldWindowSystemCost = windowSystemCost;
        windowSizes.setUpperRowHeight(newUpperRowHeight);
        updateSizes();
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setProfileAndPrice(std::string newProfile, double newPrice) {
        double oldWindowSystemCost = windowSystemCost;
        profile.setProfileAndPrice(newProfile, newPrice);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setNumberOfOpenings(int newNumberOfOpenings) {
        double oldWindowSystemCost = windowSystemCost;
        numberOfOpenings.setNumberOfOpenings(newNumberOfOpenings);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setLaminationAndPrice(std::string newLamination, double newPrice) {
        double oldWindowSystemCost = windowSystemCost;
        lamination.setLaminationAndPrice(newLamination, newPrice);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }


    void WindowSystem::setDoubleGlazingAndPrice(std::string newDoubleGlazing, double newPrice) {
        double oldWindowSystemCost = windowSystemCost;
        doubleGlazing.setDoubleGlazingAndPrice(newDoubleGlazing, newPrice);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setToning(std::string newToning) {
        double oldWindowSystemCost = windowSystemCost;
        toning.setToning(newToning);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setBulkToning(std::string newBulkToning) {
        double oldWindowSystemCost = windowSystemCost;
        bulkToning.setBulkToning(newBulkToning);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setBulkToningMaterialAndPrice(std::string newBulkToningMaterial, double newPrice) {
        double oldWindowSystemCost = windowSystemCost;
        bulkToning.setMaterialAndPrice(newBulkToningMaterial, newPrice);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setMosquitoNet(int newMosquitoNet) {
        double oldWindowSystemCost = windowSystemCost;
        mosquitoNet.setMosquitoNet(newMosquitoNet);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setTriplex(std::string newTriplex) {
        double oldWindowSystemCost = windowSystemCost;
        triplex.setTriplex(newTriplex);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setTriplexMaterialAndPrice(std::string newTriplexMaterial, double newPrice) {
        double oldWindowSystemCost = windowSystemCost;
        triplex.setMaterialAndPrice(newTriplexMaterial, newPrice);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

    void WindowSystem::setHandlesAndPrice(std::string newHandles, double newPrice) {
        double oldWindowSystemCost = windowSystemCost;
        handles.setHandlesAndPrice(newHandles, newPrice);
        *grandTotal += windowSystemCost - oldWindowSystemCost;
    }

}
