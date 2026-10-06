cmake_minimum_required(VERSION 3.20)
project(Algoritma_odevleri C)

set(CMAKE_C_STANDARD 11)

add_executable(Hafta04_Example1
        Hafta-04/C/Example-1/main.c
        Hafta-04/C/Example-1/insertOrdered.c
        Hafta-04/C/Example-1/displayForward.c
        Hafta-04/C/Example-1/displayBackward.c
        Hafta-04/C/Example-1/ClearList.c
)
add_executable(Hadta03_Soru1
        Hafta-03/C/Soru-1/main.c
        Hafta-03/C/Soru-1/addOrder.c
        Hafta-03/C/Soru-1/Clear.c
        Hafta-03/C/Soru-1/Count.c
        Hafta-03/C/Soru-1/printList.c
        Hafta-03/C/Soru-1/removeNode.c
        Hafta-03/C/Soru-1/sumList.c
        Hafta-04/C/Soru-1/addSongToEnd.h
        Hafta-04/C/Soru-1/addSongToEnd.c
        Hafta-04/C/Soru-1/Song.h
        Hafta-04/C/Soru-1/removeSong.h
        Hafta-04/C/Soru-1/removeSong.c
)
add_executable(Hafta03_Soru2
        Hafta-03/C/Soru-2/main.c
        Hafta-03/C/Soru-2/Count.c
        Hafta-03/C/Soru-2/deleteAt.c
        Hafta-03/C/Soru-2/insertAt.c
        Hafta-03/C/Soru-2/printList.c
        Hafta-03/C/Soru-2/Clear.c
)
add_executable(Hafta04_Soru1
        Hafta-04/C/Soru-1/main.c
        Hafta-04/C/Soru-1/addSongToEnd.c
        Hafta-04/C/Soru-1/removeSong.c
        Hafta-04/C/Soru-1/playNext.c
        Hafta-04/C/Soru-1/playPrevious.c
        Hafta-04/C/Soru-1/displayPlayList.c

)