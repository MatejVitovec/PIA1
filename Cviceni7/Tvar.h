#ifndef TVAR_H
#define TVAR_H

class Tvar
{
    public:
        virtual double obsah() const;

        virtual bool leziUvnitr(double xx, double yy) const = 0; 

    protected:
        virtual double x_min() const = 0;
        virtual double x_max() const = 0;
        virtual double y_min() const = 0;
        virtual double y_max() const = 0;
};

#endif // TVAR_H