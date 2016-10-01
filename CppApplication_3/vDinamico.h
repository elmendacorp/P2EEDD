/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vDinamico.h
 * Author: Fran
 *
 * Created on 1 de octubre de 2016, 17:44
 */

#ifndef VDINAMICO_H
#define VDINAMICO_H

template <typename T>
class vDinamico {
public:
    vDinamico();
    vDinamico(unsigned tam, const T & dato);
    vDinamico(const vDinamico<T>& orig);
    vDinamico(const vDinamico<T>&orig, unsigned inicio, unsigned fin);

    int lee(unsigned pos) {
        return v[pos];
    }

    void escribe(unsigned pos, T dato) {
        v[pos] = dato;
    }

    T & operator=(unsigned pos) {
        return v[pos];
    }

    T& operator[](unsigned pos) {
        return v[pos];
    }
    void inserta(unsigned pos, T & dato);
    T elimina(unsigned pos);
    void aumenta(T dato);
    T disminuye();

    unsigned tama() {
        return tamal;
    }
    void ordenar();
    T busca(T dato);
    T busquedaBin(T dato);
    virtual ~vDinamico();
private:
    int tamal, tamaf;
    int *v;
};

template <typename T>
vDinamico<T>::vDinamico() {
    tamal = 0;
    tamaf = 1;
    v = new T [tamaf];
}

template <typename T>
vDinamico<T>::vDinamico(unsigned tam, const T& dato) {
    unsigned tamcalculado = 2;
    while (tamcalculado <= tam) {
        tamcalculado *= 2;
    }
    v = new T [tamaf = tamcalculado];
    tamal = 0;
    for (unsigned i = 0; i < tamaf; ++i) {
        v[i] = dato;
    }
}

template <typename T>
vDinamico<T>::vDinamico(const vDinamico<T>& orig) {
    if (tamaf < orig.tamal) {
        tamaf = orig.tamaf;
    }
    delete [] v;
    v = new T [tamaf];
    for (unsigned i = 0; i < orig.tamal; ++i) {
        v[i] = orig.v[i];
    }
}

template<typename T>
vDinamico<T>::vDinamico(const vDinamico<T>& orig, unsigned inicio, unsigned fin) {
    if (tamaf < (fin - inicio)) {
        unsigned tamcalculado = 2;
        while (tamcalculado <= (fin - inicio)) {
            tamcalculado *= 2;
        }
        tamaf = tamcalculado;
    }
    delete [] v;
    v = new T [tamaf];
    for (unsigned i = inicio; i <= fin; ++i) {
        v[i - inicio] = orig.v[inicio];
    }
}

template <typename T>
void vDinamico<T>::inserta(unsigned pos, T& dato) {
    v[pos] = dato;
}

template <typename T>
void vDinamico<T>::aumenta(T dato) {
    while (v[tamal] != 0 && tamal < tamaf) {//si se han hecho inserciones aleatorias comprobamos no machacar el dato
        ++tamal;
    }
    vDinamico temp(this);
    if (tamal == tamaf) {
        tamaf *= 2;
        delete [] v;
        v = new T [tamaf];
    }
    for (unsigned i = 0; i < temp.tama(); ++i) {

    }

}

#endif /* VDINAMICO_H */

