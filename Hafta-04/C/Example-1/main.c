#include <stdio.h>
#include <stdlib.h>
#include "StudentNode.h"
#include "ClearList.h"
#include "insertOrdered.h"
#include "displayForward.h"
#include "displayBackward.h"


int main(void) {
    Node* studentList = NULL;

    // Karışık sıra ile öğrenci ekleyelim (Sıralamayı doğrulamak için)
    insertOrdered(&studentList, 105, "Ahmet Yilmaz");
    insertOrdered(&studentList, 101, "Zeynep Kaya");
    insertOrdered(&studentList, 110, "Mehmet Demir");
    insertOrdered(&studentList, 103, "Ayse Celik");

    // Listeleri yazdır
    displayForward(studentList);
    displayBackward(studentList);

    // Belleği serbest bırak
    ClearList(&studentList);

    return 0;
}