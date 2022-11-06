#ifndef KRUH_H
#define KRUH_H

class Kruh : public Tvar
{
    public:
        Kruh();
        Kruh(double xx, double yy , double rr);
        //virtual double obsah() const;

        virtual bool leziUvnitr(double xx, double yy) const; 

    private:
        virtual double x_min() const;
        virtual double x_max() const;
        virtual double y_min() const;
        virtual double y_max() const;

        double x;
        double y;
        double r;
};

#endif // KRUH_H