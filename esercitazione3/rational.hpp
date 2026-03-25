#include <concepts>
#include <iostream>
#include <ostream>

template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;

    public:
        rational() : num_(0) , den_(1) {};
        rational(const I& num, const I& den){
            if(den == 0){
                if(num == 0){
                    num_ = 0;
                    den_ = 0;
                }

                else{
                    if(num > 0){
                        num_ = 1;
                    }
                    else{
                        num_ = -1;
                    }
                    den_ = 0;
                }
            }

            else if(num == 0){
                num_ = 0;
                den_ = 1;
            }

            else{
                    I a = num;
                    I b = den;
                    I res = 1;
                    while(res != 0){
                        res = a % b;
                        a = b;
                        b = res;
                    }
                    I mcd = a;
                    num_ = num/mcd;
                    den_ = den/mcd;
                }

            if(den < 0){
                num_ = -num;
                den_ = -den;
            }
        }

    I num() const { return num_; }
    I den() const { return den_; }

    rational& operator+=(const rational& other) {
        num_ = num_*other.den_ + other.num_*den_;
        den_ *= other.den_;
        return *this; 
    }

    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }
    
    rational& operator*=(const I& s) {
        num_ *= s;
        return *this;
    }

    rational operator*(const I& s) const {
        rational ret = *this;
        ret *= s;
        return ret;
    }

    rational& operator*=(const rational& other) {
        num_ *= other.num_;
        den_ *= other.den_;
        return *this;
    }

    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;   
    }

    rational& operator/=(const rational& other) {
        num_ *= other.den_;
        den_ *= other.num_;
        return *this;
    }

    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
    if(r.den() == 0){
        if(r.num() == 0){
            os << "NaN";
        }
        else{
            if(r.num() > 0){
                os << "Inf";
            }
            else{
                os << "-Inf";
            }
        }
    }
    else{
        os << r.num() << "/" << r.den();
    }
    return os;
};
