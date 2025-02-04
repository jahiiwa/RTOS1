#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

// Konfigurasi pin SPI untuk SD Card
#define SD_CS 5  // Pastikan menggunakan pin yang sesuai dengan modul SD Card

// Nama file untuk penyimpanan data
const char* filename = "/AirPurifier_FilterMain.txt";

// Fungsi untuk menulis data ke SD Card
void writeDataToSD() {
    File file = SD.open(filename, FILE_APPEND);  // Mode APPEND (Tambahkan data ke file)
    
    if (!file) {
        Serial.println("Gagal membuka file, mencoba membuat file baru...");
        file = SD.open(filename, FILE_WRITE);  // Buat file baru jika belum ada
        if (!file) {
            Serial.println("Gagal membuat file!");
            return;
        }
    }

    // Format data yang akan disimpan
    String dataString = String(mhz_inlet) + " ppm, " + 
                        String(mhz_outlet) + " ppm, " + 
                        String(mof_inlet) + " ppm, " + 
                        String(mof_outlet) + " ppm, " + 
                        String(t) + " C, " + 
                        String(h) + " %, " +
                        String(output) + " pwm";

    // Tulis data ke file
    file.println(dataString);
    file.close();  // Tutup file setelah selesai menulis
    
    Serial.println(dataString);
}

void SD_Setup() {
    // Inisialisasi SD Card
    if (!SD.begin(SD_CS)) {
        Serial.println("SD Card gagal diinisialisasi!");
        return;
    }
    Serial.println("SD Card berhasil diinisialisasi!");
}
