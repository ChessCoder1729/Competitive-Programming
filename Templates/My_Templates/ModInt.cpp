struct mint {
  ll value;
  static const ll mod_value = mod;
 
  mint(ll v = 0) { value = v % mod; if (value < 0) value += mod;}
  mint(ll a, ll b) : value(0){ *this += a; *this /= b;}
 
  mint& operator+=(mint const& b) {value += b.value; if (value >= mod) value -= mod; return *this;}
  mint& operator-=(mint const& b) {value -= b.value; if (value < 0) value += mod;return *this;}
  mint& operator*=(mint const& b) {value = (ll)value * b.value % mod;return *this;}
 
  friend mint mexp(mint a, ll e) {
    mint res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend mint inverse(mint a) { return mexp(a, mod - 2); }
  friend mint frac(mint a, mint b) {return (a*inverse(b));}
  mint& operator/=(mint const& b) { return *this *= inverse(b); }
  friend mint operator+(mint a, mint const b) { return a += b; }
  friend mint operator-(mint a, mint const b) { return a -= b; }
  friend mint operator-(mint const a) { return 0 - a; }
  friend mint operator*(mint a, mint const b) { return a *= b; }
  friend mint operator/(mint a, mint const b) { return a /= b; }
  friend std::istream& operator>>(std::istream &in, mint & a) {return in >> a.value;}
  friend std::ostream& operator<<(std::ostream& os, mint const& a) {return os << a.value;}
  friend bool operator==(mint const& a, mint const& b) {return a.value == b.value;}
  friend bool operator!=(mint const& a, mint const& b) {return a.value != b.value;}
};