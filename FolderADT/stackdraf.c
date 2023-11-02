#include <stdio.h>
#include "stackdraf.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackDraf(StackDraf *S) {
    /* I.S. sembarang; */
    /* F.S. Membuat sebuah StackDraf S yang kosong berkapasitas MaxEl */
    /* jadi indeksnya antara 0.. MaxEl */
    /* Ciri StackDraf kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackDraf(StackDraf S) {
    /* Mengirim true jika StackDraf kosong: lihat definisi di atas */
    return (Top(S) == Nil);
}
boolean IsFullStackDraf(StackDraf S) {
    /* Mengirim true jika tabel penampung nilai elemen StackDraf penuh */
    return Top(S) == MaxEl-1;
}

/* ************ Menambahkan sebuah elemen ke StackDraf ************ */
void PushStackDraf(StackDraf * S, ElTypeDraf X) {
    /* Menambahkan X sebagai elemen StackDraf S. */
    /* I.S. S mungkin kosong, tabel penampung elemen StackDraf TIDAK penuh */
    /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen StackDraf ************ */
void PopStackDraf(StackDraf * S, ElTypeDraf* X) {
    /* Menghapus X dari StackDraf S. */
    /* I.S. S  tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    Top(*S) -= 1;
}