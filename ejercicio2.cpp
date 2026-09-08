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
                Cajon(string p, Cajon* c): pal(p), sig(c), cantPals(1) {}
                int getCant() {
                    return this->cantPals;
                }
                string getPal(){
                    return pal;
                }
                void sumCant(){
                    this->cantPals++;
                }
                Cajon* getSig(){
                    return this->sig;
                }
        };
        int largoTabla;
        int cantCajones;
        int maxCajon;
        Cajon** tabla;
        int* primos;

        int hash(string p){
            int hash = 1;
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
        string ordenarPal(string pal){
            int* aux = new int[26];
            for(int i = 0; i < 26; i++){
                aux[i] = 0;
            }
            for(int i = 0; i < pal.size(); i++){
                aux[pal.at(i)-97]++;
            }
            string ret = "";
            for(int i = 0; i < 26; i++){
                while(aux[i] > 0){
                    ret += i+'a'; //Esto es Orden constante xq el while va a hacer la cantidad de iteraciones letras tenga la palabra
                    aux[i]--;
                }
            }
            delete [] aux;
            return ret;
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
            std::string pal = ordenarPal(p);
            int bucket = normalizar(hash(pal));
            Cajon* cajon = this->tabla[bucket];
            bool encontre = false;
            while(cajon && !encontre){
                if(cajon->getPal().compare(pal) == 0){
                    cajon->sumCant();
                    encontre = true;
                    if(cajon->getCant() > this->maxCajon){
                        this->maxCajon = cajon->getCant();
                    }
                }
                cajon = cajon->getSig();
            }
            if(!encontre){
                this->cantCajones++;
                Cajon* nuevo = new Cajon(pal, this->tabla[bucket]);
                this->tabla[bucket] = nuevo;
                if(this->maxCajon == 0){
                    this->maxCajon = 1;
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
            Cajon* cajon = this->tabla[bucket];
            while(cajon){
                if(cajon->getPal().compare(ordenarPal(p)) == 0){
                    return cajon->getCant();
                }
                cajon = cajon->getSig();
            }
            return 0;
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
    std::cout << cajones->getCantCajones() << " " << cajones->getMaxCajon() << endl;
    return 0;
}