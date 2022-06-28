/**
 * \file dynamichetero.h
 *
 * Ez a fájl tartalmazza a DynamicHetero template osztály deklarációját és inline függvényeit.
 */

#ifndef DYNAMICHETERO_HPP_INCLUDED
#define DYNAMICHETERO_HPP_INCLUDED

#include "memtrace.h"
/**
 * DynamicHetero template osztály, heterogén kollekció tárolásához használható.
 * A data pointer mutat a dinamikusan foglalt területre, ahol az ősosztályra mutató pointerek vannak,
 * a size adattag pedig a tárolt elemek száma.
 * Elvárás, hogy a tárolt típusnak legyen clone() függvénye (a másoló konstruktor és az értékadó operátor miatt)
 */
template<typename T>
class DynamicHetero {
    T** data;           ///< az ősosztályra mutató pointereket tartalmazó dinamikusan foglalt területre mutat
    int size;           ///< a tárolt elemek száma

public:
    /**
     * Iterátor osztály a DynamicHetero osztályhoz.
     * Az actual adattag mutat a tömb aktuális elemére.
     */
    class iterator {
        T** actual;     ///< a tömb aktuális elemére mutat

    public:
        /// Konstruktor a tömb egy elemére mutató pointerrel
        /// @param actual - a tömb egyik elemére mutató pointer
        iterator(T** actual = 0) : actual(actual) {}

        /// Preinkremens operátor
        /// @return Az iterátor referenciája
        iterator& operator++() {
            actual++;
            return *this;
        }
        /// Posztinkremens operátor
        /// @return Az iterátor régebbi értéke
        iterator operator++(int) {
            iterator clone = *this;
            ++(*this);
            return clone;
        }

        /// Dereferálás
        /// @return A tömb adott eleme, amire az iterátor mutat
        T* operator*() const {
            return *actual;
        }

        /// Összehasonlító operátor
        /// @param rhs - a jobboldali operandus
        /// @return Logikai igaz, ha ugyanarra az elemre mutatnak
        bool operator==(iterator rhs) const {
            return actual == rhs.actual;
        }
        /// Összehasonlító operátor
        /// @param rhs - a jobboldali operandus
        /// @return Logikai igaz, ha nem ugyanarra az elemre mutatnak
        bool operator!=(iterator rhs) const {
            return actual != rhs.actual;
        }
    };

    /// A tömb első elemére mutató iterátort adja vissza
    /// @return A tömb első elemére mutató iterátor
    iterator begin() const {
        return data;
    }
    /// A tömb utolsó utáni elemére mutató iterátort adja vissza
    /// @return A tömb utolsó utáni elemére mutató iterátor
    iterator end() const {
        return data + size;
    }

    /// Paraméter nélküli konstruktor
    DynamicHetero() : data(0), size(0) {}

    /// Destruktor
    ~DynamicHetero() {
        delete_data();
    }

    /// Törli a tömb teljes tartalmát és kinullázza az adattagokat
    void delete_data() {
        for (int i = 0; i < size; i++)
            delete data[i];
        if (data != 0)
            delete[] data;
        data = 0;
        size = 0;
    }

    /// Értékadó operátor
    /// @param dh - a DynamicHetero objektum, aminek az értékét adja a baloldali operandusnak
    /// @return A baloldali új értékekkel rendelkező DynamicHetero objektum referenciája
    DynamicHetero& operator=(const DynamicHetero& dh) {
        if (this != &dh) {
            delete_data();
            size = dh.size;
            data = new T*[size];
            for (int i = 0; i < size; i++)
                data[i] = dh.data[i]->clone();
        }
        return *this;
    }

    /// Másoló konstruktor
    /// @param dh - a DynamicHetero objektum, amit lemásol
    DynamicHetero(const DynamicHetero& dh) : data(0), size(0) {
        *this = dh;
    }

    /// Indexelő operátor
    /// @param i - a tárolt elem indexe
    /// @return A megfelelő indexű elem referenciája
    T*& operator[](int i) {
        return data[i];
    }

    /// Indexelő operátor konstans objektumhoz
    /// @param i - a tárolt elem indexe
    /// @return A megfelelő indexű elem
    T* operator[](int i) const {
        return data[i];
    }

    /// A tárolt elemek számát adja vissza
    /// @return A tárolt elemek száma
    int getsize() const {
        return size;
    }

    /// Hozzáad egy új elemet a tömbhöz
    /// @param p - egy ősosztályra mutató pointer
    void push(T* p) {
        T** newdata = new T*[size+1];
        for (int i = 0; i < size; i++) {
            newdata[i] = data[i];
        }
        newdata[size] = p;
        if (data != 0)
            delete[] data;
        data = newdata;
        size++;
    }

    /// Kitörli a megadott indexű elemet a tömbből
    /// @param i - a törlendő elem indexe
    void pop(int i) {
        if (i >= size)
            throw "Data doesn't exist!";
        T** newdata = new T*[size-1];
        int k;
        for (k = 0; k != i; k++) {
            newdata[k] = data[k];
        }
        delete data[i];
        i++;
        while(i < size) {
            newdata[k++] = data[i++];
        }
        delete[] data;
        data = newdata;
        size--;
    }
};

#endif // DYNAMICHETERO_HPP_INCLUDED
