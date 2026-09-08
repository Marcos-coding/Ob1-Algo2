#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HeapMin.cpp"

using namespace std;

int main()
{
    long n;
    cin >> n;

    if(n == 1){
        cout << 0 << endl;
    }
    else {
        HeapMin archivos = HeapMin(n);
        long x;
        
        for (long i = 0; i < n; i++){
            cin >> x;
            archivos.insertar(x);
        }
        
        long long suma = 0;
        long long arch1;
        long long arch2;
        long long nuevoArch;

        while(archivos.cantElementos() > 1){
            arch1 = archivos.eliminar();
            arch2 = archivos.eliminar();
            nuevoArch = arch1 + arch2;

            archivos.insertar(nuevoArch);
            suma += nuevoArch;
        }
        cout << suma << endl;
    }
    return 0;
}