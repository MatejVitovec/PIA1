#ifndef KRUH_H
#define KRUH_H

class Kruh
{
    public: 
        double x; double y; double r;
        Kruh();
        Kruh(double xx, double yy, double rr);

        virtual ~Kruh();

        void posun(double xx, double yy);
        double obvod() const;
        double obsah() const;
        bool jeBodvnitr(double xx, double yy) const;
        void vypis() const;
};

#endif // KRUH_H