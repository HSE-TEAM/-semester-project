#include "grand_total.h"
#include <iostream>


namespace Calculator {
    void GrandTotal::setGrandTotal(double grandTotal) {
        GrandTotal::grandTotal = grandTotal;
    }

    double GrandTotal::getGrandTotal() {
        return grandTotal;
    }
}