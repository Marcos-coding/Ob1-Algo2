#include <cassert>
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

        int hash(string p){ ///Hacer
            return 0;
        }
        
    public:
        Cajonera(int esperados){
            this->largoTabla = esperados; //Esto esta mal, resulta en factor de carga 1
            this->tabla = new Cajon*[this->largoTabla];
            for(int i = 0; i < this->largoTabla; i ++){
                this->tabla[i] = NULL;
            }
        }
        void agregarCajon(string p){
            int bucket = hash(p); //Falta el modulo
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