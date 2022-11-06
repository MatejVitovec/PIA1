#ifndef KYTICKA_H
#define KYTICKA_H

class Kyticka : public Tvar
{
    public:
        Kyticka();
        Kyticka(double xx, double yy , double ff);

        virtual bool leziUvnitr(double xx, double yy) const; 

    private:
        virtual double x_min() const;
        virtual double x_max() const;
        virtual double y_min() const;
        virtual double y_max() const;

        double x;
        double y;
        double f;
};

#endif // KYTICKA_H