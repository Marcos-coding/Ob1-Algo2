#include <cassert>
#include <complex>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

class Cajonera {
    private:
        class Cajon {
            private:
                int cantPals;
                string pal;
                Cajon* sig;
            public: 
                Cajon(string p, int cant, Cajon* c): pal(p), sig(c), cantPals(cant) {}
                int getCant() {
                    return this->cantPals;
                }
        };
        int largoTabla;
        int cantCajones;
        int maxCajon;
        Cajon** tabla;

        int hash(string p){
            int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101}; //Saque de google como hardcodear el array
            int hash = 1;
            for(int i = 0; i < p.size(); i++){
                hash = hash * primos[p[i] - 97];
            }
            return hash;
        }
        int normalizar(int h){
            return abs(h % largoTabla);
        }
        bool esPrimo(int num) { //Copy paste del repo de clase
            if (num < 2) return false;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) return false;
            }
            return true;
        }

        int primoSup(int num) { //del repo de clase
            while (!esPrimo(++num));
            return num;
        }
    public:
        Cajonera(int esperados){
            this->largoTabla = primoSup(esperados*2); //Esto esta mal, resulta en factor de carga 1
            this->tabla = new Cajon*[this->largoTabla];
            for(int i = 0; i < this->largoTabla; i ++){
                this->tabla[i] = NULL;
            }
        }
        void agregarCajon(string p){
            int bucket = normalizar(hash(p));
            Cajon* cajon = this->tabla[bucket];
            if(!cajon){
                cantCajones++;
            }
            int cant = cajon->getCant()+1;
            Cajon* nuevo = new Cajon(p, cant, cajon);
            this->tabla[bucket] = nuevo;
            if(cant > maxCajon){
                maxCajon++;
            }
        }
        int getMaxCajon(){
            return this->maxCajon;
        }
        int getCantCajones(){
            return this->cantCajones;
        }
        int consultaPal(string p){
            int bucket = hash(p);
            return this->tabla[bucket]->getCant();
        }

};

int main()
{
    // TODO
    return 0;
}