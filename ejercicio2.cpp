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
        int* primos;

        int hash(string p){
            int hash = 1; //Seria mejor que el array fuera un atributo del hash mismo??
            for(int i = 0; i < p.size(); i++){
                hash = hash * this->primos[p[i] - 97];
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
            this->largoTabla = primoSup(esperados*2);
            this->tabla = new Cajon*[this->largoTabla];
            for(int i = 0; i < this->largoTabla; i ++){
                this->tabla[i] = NULL;
            }
            this->cantCajones = 0;
            this->maxCajon = 0;
            this->primos = new int[26];
            int n = 1;
            for(int i = 0; i < 26; i ++){
                this->primos[i] = primoSup(n);
                if(this->primos[i] == this->largoTabla){
                    n = primos[i];
                    this->primos[i] = primoSup(n);
                }
                n = primos[i];
            }
        }
        void agregarCajon(string p){
            int bucket = normalizar(hash(p));
            Cajon* cajon = this->tabla[bucket];
            if(!cajon){
                this->cantCajones++;
                Cajon* nuevo = new Cajon(p, 1, NULL);
                this->tabla[bucket] = nuevo;
                if(this->maxCajon == 0){
                    this->maxCajon++;
                }
            }else{
                int cant = cajon->getCant()+1;
                Cajon* nuevo = new Cajon(p, cant, cajon);
                this->tabla[bucket] = nuevo;
                if(cant > this->maxCajon){
                    this->maxCajon++;
                }
            }
            
            
        }
        int getMaxCajon(){
            return this->maxCajon;
        }
        int getCantCajones(){
            return this->cantCajones;
        }
        int consultaPal(string p){
            int bucket = normalizar(hash(p));
            if(this->tabla[bucket]){
                //std::cout << "el bucket de " << p << " es" << bucket << " ";
                return (this->tabla[bucket]->getCant());                
            }else{
                return 0;
            }

        }

};

int main()
{
    int n = 0;
    std::cin >> n;
    Cajonera* cajones = new Cajonera(n);
    for(int i = 0; i < n; i++){
        std::string pal;
        std::cin >> pal;
        cajones->agregarCajon(pal);
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        std::string pal;
        std::cin >> pal;
        std::cout << cajones->consultaPal(pal) << "\n";
    }
    std::cout << cajones->getCantCajones() << " " << cajones->getMaxCajon();
    return 0;
}