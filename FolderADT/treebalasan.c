#include "treebalasan.h"
#include <stdlib.h>
#include <stdio.h>

// void CreateTree (Balasan root, BinTree left_tree, BinTree right_tree, BinTree *p) {
//     *p = NewTree(root, left_tree, right_tree);
// }
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(Balasan val) {
    Address node = (Address) malloc(sizeof(TreeNode));
    if (node != NULL) {
        ROOT(node) = val;
        CHILDREN(node) = NULL;
        SIBLING(node) = NULL;
    }
    return node;
}
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void addSiblingToRoot(Balasan Val, BinTree* targetedRoot) {
    Address newRoot = newTreeNode(Val);
    (*targetedRoot)->sibling = newRoot;  
}

void addChildrenToRoot(Balasan Val, BinTree* targetedRoot) {
    Address newRoot = newTreeNode(Val);
    (*targetedRoot)->children = newRoot;
}

void addChildrenAt(int id, BinTree* treeResult, Balasan val) {
    if (*treeResult == NULL) {
        return;
    }
    if ((*treeResult)->info.id == id) {
        BinTree newChild = newTreeNode(val);
        newChild->sibling = (*treeResult)->children;
        (*treeResult)->children = newChild;
        return;
    }
    if ((*treeResult)->children != NULL) {
        addChildrenAt(id, &((*treeResult)->children), val);
    }
    if ((*treeResult)->sibling != NULL) {
        addChildrenAt(id, &((*treeResult)->sibling), val);
    }
}

int findHighestID(BinTree mainRoot) {
    if (mainRoot == NULL) {
        return INT_MIN; 
    }

    int max = (mainRoot)->info.id;

    int siblingMax = findHighestID((mainRoot)->sibling);
    int childrenMax = findHighestID((mainRoot)->children);

    if (siblingMax > max) {
        max = siblingMax;
    }
    if (childrenMax > max) {
        max = childrenMax;
    }

    return max;
}

void deallocTreeNode (Address p) {
    free(p);
}
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

// boolean isTreeEmpty (BinTree p) {
//     return (p == NULL);
// }
// /* Mengirimkan true jika p adalah pohon biner yang kosong */

// boolean isOneElmt (BinTree p) {
//     if (isTreeEmpty(p)) {
//         return false;
//     } else {
//         return isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
//     }
// }
// /* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

// boolean isUnerLeft (BinTree p) {
//     if (isTreeEmpty(p) || isOneElmt(p)) {
//         return false;
//     } else {
//         return isTreeEmpty(RIGHT(p)) && !isTreeEmpty(LEFT(p));
//     }
// }
// /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
//    hanya mempunyai subpohon kiri */

// boolean isUnerRight (BinTree p) {
//     if (isTreeEmpty(p) || isOneElmt(p)) {
//         return false;
//     } else {
//         return isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
//     }
// }
// /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
//    hanya mempunyai subpohon kanan */

// boolean isBinary (BinTree p) {
//     if (isTreeEmpty(p)) {
//         return false;
//     } else {
//         return !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
//     }
// }
// /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
//   mempunyai subpohon kiri dan subpohon kanan */

// /* ****** Display Tree ***** */
// void printPreorder(BinTree p) {
//     putchar('(');
//     if (!isTreeEmpty(p)) {
//         printf("%d", ROOT(p));
//         printPreorder(LEFT(p));
//         printPreorder(RIGHT(p));
//     }
//     putchar(')');
// }
// /* I.S. p terdefinisi */
// /* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (A()()) adalah pohon dengan 1 elemen dengan akar A
//    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

// void printInorder(BinTree p) {
//     putchar('(');
//     if (!isTreeEmpty(p)) {
//         printInorder(LEFT(p));
//         printf("%d", ROOT(p));
//         printInorder(RIGHT(p));
//     }
//     putchar(')');
// }
// /* I.S. p terdefinisi */
// /* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (()A()) adalah pohon dengan 1 elemen dengan akar A
//    ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

// void printPostorder(BinTree p) {
//     putchar('(');
//     if (!isTreeEmpty(p)) {
//         printPostorder(LEFT(p));
//         printPostorder(RIGHT(p));
//         printf("%d", ROOT(p));
//     }
//     putchar(')');
// }
// /* I.S. p terdefinisi */
// /* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (()()A) adalah pohon dengan 1 elemen dengan akar A
//    ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

// void printIndent(BinTree p, int h, int l) {
//     if (!isTreeEmpty(p)) {
//         int maxIndent = h * l;
//         int i;
//         for (i = 0; i < maxIndent; i++) {
//             printf(" ");
//         }
//         printf("%d\n", ROOT(p));
//         printIndent(LEFT(p), h, l + 1);
//         printIndent(RIGHT(p), h, l + 1);
//     }
// }

// void printTree(BinTree p, int h) {
//     printIndent(p, h, 0);
// }
// /* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
// /* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
// /* Penulisan akar selalu pada baris baru (diakhiri newline) */
// /* Contoh, jika h = 2: 
// 1) Pohon preorder: (A()()) akan ditulis sbb:
// A
// 2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
// A
//   B
//   C
// 3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
// A
//   B
//     D
//   C
//     E
// Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
// */