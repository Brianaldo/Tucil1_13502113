# Tucil1-13520113
## Author
```
Nama    : Brianaldo Phandiarta
NIM     : 13520113
```
## Tugas Kecil IF2211 Strategi Algoritma
Program kecil (sederhana) dalam bahas C++ yang mengimplementasikan algoritma Brute Force untuk mencari solusi word search puzzle dengan alur sebagai berikut:
1. Program akan menerima input file sesuai dengan spesifikasi yang akan diubah kedalam bentuk matrix dan list of word
2. Program akan mulai mencocokan character demi character dimulai dari ujung kiri atas
3. Program akan melakukan penyocokan sesuai dengan arah mata angin (dimulai dari timur dan berputar searah jarum jam)
4. langkah 2 dan 3 akan diulang hingga puzzle selesai

## Directories

    Tucil1_13520113
        ├── bin             # Executable files
        ├── doc             # Documentation files (Laporan tugas kecil)
        ├── src             # Source files
        ├── test            # Test cases
        └── README.md

## How To Run
1. Pastikan berada pada directory terluar
    ```
    ../Tucil1_13520113/
    ```
2. Compile
    ```
    $ g++ -std=c++11 src/main.cpp -o bin/main
    ```
3. Masukkan file test case ke dalam folder test 
4. Run
    ```
    $ ./bin/main
    ```
5. Masukkan nama file lengkap dengan ekstensinya (contoh: "tes.txt")
