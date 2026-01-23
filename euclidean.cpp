#include <iostream>
#include <vector>
using namespace std;

double abso(double value) {
    return (value < 0) ? -value : value;
}

double sqrt(double value) {
    double guess = value / 2.0;
    const double epsil = 1e-10;

    while (true) {
        double nextguess = (guess + value / guess) / 2.0;
        if (abso(nextguess - guess) < epsil) {
            break;
        }
        guess = nextguess;
    }

    return guess;
}


double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}


// --- DEFINISI FUNGSI ---

// Fungsi 1: Untuk mengisi elemen vektor

void inputVektor(vector<double>& vec, string namaVektor) {
    cout << "Masukkan elemen-elemen vektor " << namaVektor << " (total " << vec.size() << " elemen):" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "Elemen ke-" << (i + 1) << ": ";
        cin >> vec[i];
    }
}

// Fungsi 2: Menghitung Norma Euclidean (Panjang Vektor)
double hitungNorma(const vector<double>& vec) {
    double sum = 0.0;
    for (int i = 0; i < vec.size(); i++) {
        sum += power(vec[i], 2); // Menggunakan fungsi pow dari <cmath>
    }
}

// Fungsi 3: Menghitung Dot Product
double hitungDotProduct(const vector<double>& u, const vector<double>& v) {
    double dot = 0.0;
    for (int i = 0; i < u.size(); i++) {
        dot += u[i] * v[i];
    }
    return dot; 
}

// Fungsi 4: Menampilkan Interpretasi (Logika if-else)
void analisisVektor(double dotProduct, double normaU, double normaV) {
    // Hindari pembagian dengan nol
    if (normaU == 0 || normaV == 0) {
        cout << "Interpretasi: Salah satu vektor adalah vektor nol (analisis sudut tidak valid)." << endl;
        return;
    }

    // Hitung cosinus theta
    double cosTheta = dotProduct / (normaU * normaV);
    
    // Toleransi untuk perbandingan float/double (epsilon)
    double epsilon = 1e-9; 

    cout << "\n--- HASIL ANALISIS ---" << endl;
    
    if (abso(cosTheta - 1.0) < epsilon) {
        cout << "Vektor sejajar dan berarah sama." << endl;
    } else if (abso(cosTheta + 1.0) < epsilon) {
        cout << "Vektor sejajar dan berarah berlawanan." << endl;
    } else if (abso(cosTheta) < epsilon) {
        cout << "Vektor saling tegak lurus (orthogonal)." << endl;
    } else {
        cout << "Vektor tidak sejajar dan tidak tegak lurus." << endl;
    }
}

// --- FUNGSI UTAMA (MAIN) ---
int main() {
    int n;
    
    cout << "Program Operasi & Analisis Vektor Euclidean" << endl;
    cout << "===========================================" << endl;
    
    // 1. Input Dimensi (R^n)
    cout << "Masukkan dimensi vektor (n): ";
    cin >> n;

    // Validasi dimensi
    if (n < 2) {
        cout << "Dimensi minimal 2." << endl;
        return 1;
    }

    // 2. Persiapkan Vektor (Resize sesuai dimensi n)
    vector<double> u(n);
    vector<double> v(n);

    // 3. Panggil fungsi input
    inputVektor(u, "u");
    inputVektor(v, "v");

    // 4. Lakukan Perhitungan
    double normU = hitungNorma(u);
    double normV = hitungNorma(v);
    double dotProd = hitungDotProduct(u, v);

    // 5. Tampilkan Hasil Perhitungan (Soal Poin 1)
    cout << "Norma ||u|| \t: " << normU << endl;
    cout << "Norma ||v|| \t: " << normV << endl;
    cout << "Dot Product \t: " << dotProd << endl;

   ~
    analisisVektor(dotProd, normU, normV);

    return 0;
}
