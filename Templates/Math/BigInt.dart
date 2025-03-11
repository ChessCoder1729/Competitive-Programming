class BigInt {
private:
    vector<int> digits;  // Digits are stored in reverse order
    bool isNegative;     // Indicates if the number is negative

    void removeLeadingZeros();
    static int compareAbs(const BigInt& a, const BigInt& b);

public:
    // Constructors
    BigInt();
    BigInt(const string& num);
    BigInt(long long num);

    // Arithmetic operators
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;
    BigInt operator%(const BigInt& other) const;

    // Comparison operators
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;

    // Input/Output operators
    friend ostream& operator<<(ostream& os, const BigInt& num);
    friend istream& operator>>(istream& is, BigInt& num);

    // Static utility function for sorting
    static void sortBigIntVector(vector<BigInt>& v);
};

// ----- Constructors -----
BigInt::BigInt() : isNegative(false) {}

BigInt::BigInt(const string& num) {
    isNegative = (num[0] == '-');
    for (int i = isNegative ? 1 : 0; i < num.size(); i++) {
        digits.push_back(num[i] - '0');
    }
    reverse(digits.begin(), digits.end());
    removeLeadingZeros();
}

BigInt::BigInt(long long num) {
    isNegative = (num < 0);
    num = abs(num);
    do {
        digits.push_back(num % 10);
        num /= 10;
    } while (num > 0);
    removeLeadingZeros();
}

void BigInt::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
    if (digits.size() == 1 && digits[0] == 0) {
        isNegative = false;
    }
}

int BigInt::compareAbs(const BigInt& a, const BigInt& b) {
    if (a.digits.size() != b.digits.size()) {
        return a.digits.size() < b.digits.size() ? -1 : 1;
    }
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        if (a.digits[i] != b.digits[i]) {
            return a.digits[i] < b.digits[i] ? -1 : 1;
        }
    }
    return 0;
}

// ----- Arithmetic Operators -----
BigInt BigInt::operator+(const BigInt& other) const {
    if (isNegative == other.isNegative) {
        BigInt result;
        result.isNegative = isNegative;

        int carry = 0, sum = 0;
        size_t maxSize = max(digits.size(), other.digits.size());
        for (size_t i = 0; i < maxSize || carry; i++) {
            sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }

        result.removeLeadingZeros();
        return result;
    } else {
        BigInt temp = other;
        temp.isNegative = !temp.isNegative;
        return *this - temp;
    }
}

BigInt BigInt::operator-(const BigInt& other) const {
    if (isNegative != other.isNegative) {
        BigInt temp = other;
        temp.isNegative = !temp.isNegative;
        return *this + temp;
    }

    if (compareAbs(*this, other) < 0) {
        BigInt result = other - *this;
        result.isNegative = !isNegative;
        return result;
    }

    BigInt result;
    result.isNegative = isNegative;

    int borrow = 0, diff = 0;
    for (size_t i = 0; i < digits.size() || borrow; i++) {
        diff = digits[i] - borrow;
        if (i < other.digits.size()) diff -= other.digits[i];
        borrow = (diff < 0);
        if (borrow) diff += 10;
        result.digits.push_back(diff);
    }

    result.removeLeadingZeros();
    return result;
}

BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result;
    result.digits.resize(digits.size() + other.digits.size(), 0);

    for (size_t i = 0; i < digits.size(); i++) {
        int carry = 0;
        for (size_t j = 0; j < other.digits.size() || carry; j++) {
            long long product = result.digits[i + j] +
                                digits[i] * (j < other.digits.size() ? other.digits[j] : 0) +
                                carry;
            result.digits[i + j] = product % 10;
            carry = product / 10;
        }
    }

    result.isNegative = isNegative != other.isNegative;
    result.removeLeadingZeros();
    return result;
}

BigInt BigInt::operator/(const BigInt& other) const {
    if (other.digits.size() == 1 && other.digits[0] == 0) {
        throw runtime_error("Division by zero");
    }

    BigInt dividend = *this;
    dividend.isNegative = false;
    BigInt divisor = other;
    divisor.isNegative = false;

    BigInt quotient, remainder;
    for (int i = dividend.digits.size() - 1; i >= 0; i--) {
        remainder.digits.insert(remainder.digits.begin(), dividend.digits[i]);
        remainder.removeLeadingZeros();

        int qDigit = 0;
        while (compareAbs(remainder, divisor) >= 0) {
            remainder = remainder - divisor;
            qDigit++;
        }
        quotient.digits.push_back(qDigit);
    }

    reverse(quotient.digits.begin(), quotient.digits.end());
    quotient.isNegative = isNegative != other.isNegative;
    quotient.removeLeadingZeros();
    return quotient;
}

BigInt BigInt::operator%(const BigInt& other) const {
    BigInt quotient = *this / other;
    BigInt remainder = *this - quotient * other;
    remainder.removeLeadingZeros();
    return remainder;
}



// ----- Comparision Operators --------
bool BigInt::operator==(const BigInt& other) const {
    return (isNegative == other.isNegative && digits == other.digits);
}

bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}

bool BigInt::operator<(const BigInt& other) const {
    if (isNegative != other.isNegative) return isNegative;
    int cmp = compareAbs(*this, other);
    return isNegative ? cmp > 0 : cmp < 0;
}

bool BigInt::operator>(const BigInt& other) const {
    return other < *this;
}

 
// Static function to sort a vector of BigInt
void BigInt::sortBigIntVector(vector<BigInt>& v) {
    sort(v.begin(), v.end(), [](const BigInt& a, const BigInt& b) { return a < b; });
}

ostream& operator<<(ostream& os, const BigInt& num) {
    if (num.isNegative) os << '-';
    for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
        os << *it;
    }
    return os;
}

istream& operator>>(istream& is, BigInt& num) {
    string input;
    is >> input;
    num = BigInt(input);
    return is;
}

BigInt fact(BigInt n){
    BigInt x = 1;
    for(BigInt i = 2;i<n+1;i=i+1){
        x = x*i;
    }
    return x;
}

BigInt nCr(BigInt n, BigInt r){
    return (fact(n)/fact(r))/(fact(n-r));
}