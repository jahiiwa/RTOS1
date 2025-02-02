// Deklarasi variabel
//const char* portal_url = "https://zahiraaulia.pythonanywhere.com/get_wifi "; // Ganti dengan URL database Anda
String ssid = "punya jahi";
String pass = "jahirara"; // Variabel untuk menyimpan SSID dan password

// Fungsi untuk mengambil SSID dan password dari database
// bool fetchWiFiCredentials(String &ssid, String &pass) {
//   HTTPClient http;
//   http.begin(portal_url);
//   int httpCode = http.GET();

//   if (httpCode == HTTP_CODE_OK) {
//     String payload = http.getString();
//     StaticJsonDocument<512> doc;
//     if (deserializeJson(doc, payload) == DeserializationError::Ok) {
//       ssid = doc["ssid"].as<String>();
//       pass = doc["password"].as<String>();
//       http.end();
//       return true;
//     }
//   }
//   http.end();
//   return false;
// }