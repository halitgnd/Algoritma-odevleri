/*Soru1:
===============================================================================|
 * ÖDEV: Tek Yönlü Bağlı Liste (Singly Linked List) Fonksiyonları
 * ============================================================================
 *
 * 1. addOrdered(Node** head, int value):
 *    - Elemanı listenin sırasını (küçükten büyüğe) bozmayacak konuma ekler.
 *    - Başa, araya veya sona ekleme durumlarını yönetir.
 * 2. removeNode(Node** head, int value):
 *    - Verilen değere sahip ilk düğümü zincirden çıkarır, free eder.
 *    - Baş düğümün silinmesi durumunda head işaretçisini günceller.
 * 3. count(Node* head):
 *    - Listedeki toplam düğüm sayısını sayar ve döndürür.
 * 4. printList(Node* head):
 *    - Düğümleri baştan sona ekrana yazdırır (örn: 4 -> 5 -> 6 -> NULL).
 * 5. clear(Node** head):
 *    - Listedeki tüm düğümleri tek tek free eder, bellek sızıntısını önler.
 *    - head işaretçisini en son NULL yapar.
 ==============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "addOrder.h"
#include "printList.h"
#include "removeNode.h"
#include "sumList.h"
#include "Count.h"
#include "Clear.h"

int main () {
  node* head = NULL;

  printf("=== 1. TEST: SIRALI EKLEME (addOrder) ===\n");
  // Ödev metnindeki sıralı ekleme örneği: 23, 11, 5, 9, 6, 4, 12, 24
  const int eklenecekler[] = {23, 11, 5, 9, 6, 4, 12, 24};
  const int boyut = sizeof(eklenecekler) / sizeof(eklenecekler[0]);

  for (int i = 0; i < boyut; i++) {
   addOrder(&head, eklenecekler[i]);
  }

  // Beklenen cikti: 4 -> 5 -> 6 -> 9 -> 11 -> 12 -> 23 -> 24 -> NULL
  printList(head);
  printf("Dugum sayisi: %d\n", Count(head));
  sumList(head);

  printf("\n=== 2. TEST: DUGUM SILME (removeNode) ===\n");

  // Durum A: Bastaki dugumu sil (4)
  printf("Bastan eleman siliniyor (4)...\n");
  removeNode(&head, 4);
  printList(head);

  // Durum B: Aradan dugum sil (11)
  printf("Aradan eleman siliniyor (11)...\n");
  removeNode(&head, 11);
  printList(head);

  // Durum C: Sondan dugum sil (24)
  printf("Sondan eleman siliniyor (24)...\n");
  removeNode(&head, 24);
  printList(head);

  // Durum D: Listede olmayan elemani silmeyi dene (99)
  printf("Olmayan eleman silinmeye calisiliyor (99)...\n");
  removeNode(&head, 99);
  printList(head);

  printf("Guncel Dugum Sayisi: %d \n", Count(head));
  sumList(head);

  printf("\n=== 3. TEST: BELLEK TEMIZLEME (Clear) ===\n");
  Clear(&head);

  printf("Temizlendikten sonra liste: =>");
  printList(head);
  printf("Temizlendikten sonra dugum sayisi: %d \n", Count(head));

  return 0;
 }

