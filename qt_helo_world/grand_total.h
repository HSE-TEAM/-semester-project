
#ifndef BALCONIES_GRAND_TOTAL_H
#define BALCONIES_GRAND_TOTAL_H
namespace Calculator {
    class GrandTotal {
    public:
        GrandTotal();

        ~GrandTotal();

        void setGrandTotal(double grandTotal);

        double getGrandTotal();

    private:
        double grandTotal;
    };
}
#endif //BALCONIES_GRAND_TOTAL_H
