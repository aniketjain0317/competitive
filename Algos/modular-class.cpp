// CREDITS: CF - madhur4127
struct Modular {
  int value;
  int mod(int &v) {return (v % MOD + MOD)%MOD;}

  Modular(int v = 0) { value = mod(v);}
  Modular(int a, int b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value = value + b.value; value = mod(value); return *this;}
  Modular& operator-=(Modular const& b) {value = value - b.value; value = mod(value); return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value; value = mod(value); return *this;}

  friend Modular mexp(Modular a, int e)
  {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }
  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }

  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}

  friend Modular& operator++(Modular& a, intt) {return a += 1;}
  friend Modular operator++(Modular const& a, intt) {return Modular(a)++;}
  friend Modular& operator--(Modular& a, intt) {return a -= 1;}
  friend Modular operator--(Modular const& a, intt) {return Modular(a)--;}
};
typedef Modular mo;
