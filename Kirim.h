#include <Arduino.h>
#include <FirebaseESP32.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define API_KEY "AIzaSyB1JxZubcScClFMztBuv3rrnREqLMSCURg"
#define DATABASE_URL "https://air-purifier-filter-main-default-rtdb.asia-southeast1.firebasedatabase.app/" 

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

String jsonString;

// Fungsi untuk menambahkan key-value ke dalam JSON
void addJson(String key, String value) {
  if (jsonString.length() > 1) jsonString += ",";
  jsonString += "\"" + key + "\":\"" + String(value) + "\"";
}

// Fungsi untuk mendapatkan JSON lengkap
String getJson() {
  return "{" + jsonString + "}";
}

// Fungsi untuk mengirim data ke API
void Kirim_raw() {
  if (!Firebase.ready()) {
    Serial.println("❌ Firebase not ready! Retrying...");
  return;
  }
  FirebaseJson json;
  json.set("mhz_inlet", mhz_inlet);
  json.set("mhz_outlet", mhz_outlet);
  json.set("mof_inlet", mof_inlet);
  json.set("mof_outlet", mof_outlet);
  json.set("temperature", t);
  json.set("humidity", h);

  // Pastikan data yang dimasukkan dalam JSON benar
  String jsonString;
  json.toString(jsonString, true);
  Serial.println("📡 JSON yang akan dikirim:");
  Serial.println(jsonString);

  // Kirim data ke Firebase
  if (Firebase.setJSON(fbdo, "/sensor_data", json)) {
    Serial.println("✅ Data berhasil dikirim ke Firebase!");
  } else {
    Serial.print("❌ Gagal mengirim data ke Firebase: ");
    Serial.println(fbdo.errorReason());
  }
}

