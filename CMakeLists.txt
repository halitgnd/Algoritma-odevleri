cmake_minimum_required(VERSION 3.20)
project(Algoritma_odevleri C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Her main.c dosyasını, bulunduğu klasördeki yardımcı C dosyalarıyla
# birlikte ayrı bir çalıştırılabilir hedef olarak oluştur.
file(GLOB_RECURSE MAIN_FILES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/Hafta-*/main.c"
)

foreach(MAIN_FILE IN LISTS MAIN_FILES)
    file(STRINGS "${MAIN_FILE}" MAIN_FUNCTION_LINES
            REGEX "^[ \t]*(int|void)[ \t]+main[ \t]*\\(")
    if(NOT MAIN_FUNCTION_LINES)
        message(WARNING "main.c içinde main fonksiyonu bulunamadı, atlanıyor: ${MAIN_FILE}")
        continue()
    endif()

    get_filename_component(MAIN_DIR "${MAIN_FILE}" DIRECTORY)
    file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "${MAIN_DIR}/*.c")

    file(RELATIVE_PATH TARGET_PATH "${CMAKE_CURRENT_SOURCE_DIR}" "${MAIN_DIR}")
    string(REPLACE "/" "_" TARGET_NAME "${TARGET_PATH}")
    string(REPLACE "-" "_" TARGET_NAME "${TARGET_NAME}")
    string(REPLACE " " "_" TARGET_NAME "${TARGET_NAME}")

    add_executable("${TARGET_NAME}" ${SOURCE_FILES}
            Hafta-06/C/Soru-1/main.c)
endforeach()
