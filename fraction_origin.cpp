#include<iostream>
using namespace std;
template <typename T> class Fraction
{
    private:
        T numerator;
        T denominator;
    public:
        // Default constructor
        Fraction();

        //Parameterized constructor
        Fraction(T numerator, T denominator);

        //Copy constuctor
        Fraction(const Fraction &frac);

        // Assignment overload operator
        void operator=(const Fraction &term);

        // Add Fraction
        Fraction add(const Fraction &term);

        // Sub Fraction
        Fraction sub(const Fraction &term)
        {
            Fraction temp;
            temp.numerator      = this->numerator * term.denominator - this->denominator * term.numerator;
            temp.denominator    = this->denominator * term.denominator;
            temp.simplify();
            return temp;
        }

        // Multiple Fraction
        Fraction multiple(const Fraction &term)
        {
            Fraction temp;
            temp.numerator      = this->numerator * term.numerator;
            temp.denominator    = this->denominator * term.denominator;
            temp.simplify();
            return temp;
        }

        // Divide Fraction
        Fraction divide(const Fraction &term)
        {
            Fraction temp;
            temp.numerator      = this->numerator * term.denominator;
            temp.denominator    = this->denominator * term.numerator;
            temp.simplify();
            return temp;
        }

        // Simplify Fraction
        void simplify(void)
        {
            int temp;
            auto GCD = [] (int numerator, int denominator)
            {
                while( 1 )
                {
                    numerator = numerator % denominator;
                    if( numerator == 0 )
                        return denominator;
                    denominator = denominator % numerator;
                    if( denominator == 0 )
                        return numerator;
                }
            };
            temp        = GCD(numerator, denominator);
            numerator   /= temp;
            denominator /= temp;  
        }

        // Compare Fraction
        int8_t compare(const Fraction &term)
        {
            if( ( this->numerator == term.numerator) && ( this->denominator == term.denominator ) )
            {
                return true;
            }
            else
            {
                return false;
            }    
        }

        //Overload Operator + 
        Fraction operator+(const Fraction &term)
        {
            Fraction temp;
            temp.numerator      = this->numerator * term.denominator + this->denominator * term.numerator;
            temp.denominator    = this->denominator * term.denominator;
            temp.simplify();
            return temp;
        }

        //Overload Operator - 
        Fraction operator-(const Fraction &term)
        {
            Fraction temp;
            temp.numerator      = this->numerator * term.denominator - this->denominator * term.numerator;
            temp.denominator    = this->denominator * term.denominator;
            temp.simplify();
            return temp;
        }

        //Overload Operator * 
        Fraction operator*(const Fraction &term)
        {
            Fraction temp;
            temp.numerator      = this->numerator * term.numerator;
            temp.denominator    = this->denominator * term.denominator;
            temp.simplify();
            return temp;
        }

        //Overload Operator /
        Fraction operator/(const Fraction &term)
        {
            Fraction temp;
            temp.numerator      = this->numerator * term.denominator;
            temp.denominator    = this->denominator * term.numerator;
            temp.simplify();
            return temp;
        }

        // Overload Operator +=
        Fraction operator+=(const Fraction &term)
        {
            this->numerator     = this->numerator * term.denominator + this->denominator * term.numerator;
            this->denominator   = this->denominator * term.denominator;
            return *this;
        }

        // Overload Operator -=
        Fraction operator-=(const Fraction &term)
        {
            this->numerator     = this->numerator * term.denominator - this->denominator * term.numerator;
            this->denominator   = this->denominator * term.denominator;
            return *this;
        }

        // Overload Operator *=
        Fraction operator*=(const Fraction &term)
        {
            this->numerator     = this->numerator * term.numerator;
            this->denominator   = this->denominator * term.denominator;
            return *this;
        }

        // Overload Operator /=
        Fraction operator/=(const Fraction &term)
        {
            this->numerator     = this->numerator * term.denominator;
            this->denominator   = this->denominator * term.numerator;
            return *this;
        }

        // Overload Operator >
        bool operator>(const Fraction &term)
        {
            if( ( this->numerator / this->denominator ) > ( term.numerator / term.denominator ) )
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Overload Operator >=
        bool operator>=(const Fraction &term)
        {
            if( ( (float) this->numerator / this->denominator ) >= ( (float) term.numerator / term.denominator ) )
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Overload Operator <
        bool operator<(const Fraction &term)
        {
            if( ( (float) this->numerator / this->denominator ) < ( (float) term.numerator / term.denominator ) )
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Overload Operator <=
        bool operator<=(const Fraction &term)
        {
            if( ( (float) this->numerator / this->denominator ) <= ( (float) term.numerator / term.denominator ) )
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Overload Operator ==
        bool operator==(const Fraction &term)
        {
            if( ( (float) this->numerator / this->denominator ) == ( (float) term.numerator / term.denominator ) )
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Overload Operator !=
        bool operator!=(const Fraction &term)
        {
            if( ( (float) this->numerator / this->denominator ) != ( (float) term.numerator / term.denominator ) )
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Overload Operator Pre ++
        Fraction& operator++()
        {
            this->numerator     = this->numerator + this->denominator;
            return *this;
        }

        // Overload Operator Post ++
        Fraction operator++(int)
        {
            Fraction temp       = *this;
            this->numerator     = this->numerator + this->denominator;
            return temp;
        }

        // Overload Operator Pre --
        Fraction& operator--()
        {
            this->numerator     = this->numerator - this->denominator;
            return *this;
        }

        // Overload Operator Post --
        Fraction operator--(int)
        {
            Fraction temp       = *this;
            this->numerator     = this->numerator - this->denominator;
            return temp;
        }

        // Overload Operator <<
        friend ostream& operator << (ostream& os, Fraction& dt)
        {
            os << dt.numerator << "/" << dt.denominator << endl;
            return os;
        }

        // Overload Operator >>
        friend istream& operator >> (istream& is, Fraction& dt)
        {
            cout << "Numerator = ";
            is >> dt.numerator;
            cout << "Denominator = ";
            is >> dt.denominator;
            return is;
        }
};

template <typename T> Fraction<T> :: Fraction()
{
    numerator     = 0;
    denominator   = 1;
}

template <typename T> Fraction<T> :: Fraction(T numerator, T denominator)
{
    this->numerator     = numerator;
    this->denominator   = denominator;
}

template <typename T> Fraction<T> :: Fraction(const Fraction &frac)
{
    this->numerator     = frac.numerator;
    this->denominator   = frac.denominator;
}

template <typename T> void Fraction<T> :: operator=(const Fraction &term)
{
    this->numerator     = term.numerator;
    this->denominator   = term.denominator;
}

template <typename T> Fraction<T> Fraction<T> :: add(const Fraction &term)
{
    Fraction temp;
    temp.numerator      = this->numerator * term.denominator + this->denominator * term.numerator;
    temp.denominator    = this->denominator * term.denominator;
    temp.simplify();
    return temp;
}

int main()
{
    Fraction<int> fracTwo(1, 4);
    Fraction<int> fracThree(1, 4);
    Fraction<int> fracFour;
    fracFour = ++fracTwo + fracThree;
    cout << fracFour;
    return 0;
}
