#include <RTClib.h>  // Library untuk RTC DS3231

RTC_DS3231 rtc;  // Objek untuk RTC DS3231

void RTCS() {
  rtc.begin();
}

// Fungsi untuk mendapatkan waktu dalam berbagai format
String get_date_time(int choose) {
  DateTime now = rtc.now();  // Ambil waktu dari modul RTC DS3231

  // Format bulan dan hari agar selalu 2 digit
  String string_month = (now.month() < 10) ? "0" + String(now.month()) : String(now.month());
  String string_day = (now.day() < 10) ? "0" + String(now.day()) : String(now.day());

  // Pilihan format pengembalian data
  if (choose == 0) {
    return String(now.year()) + "-" + string_month + "-" + string_day + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  } else if (choose == 1) {
    return String(now.year()) + "-" + string_month + "-" + string_day;
  } else if (choose == 2) {
    return String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  }

  return "";  // Default jika choose tidak sesuai
}

// Fungsi untuk mendapatkan waktu dengan presisi menit dan detik
String get_precission_minute_second(int minute, int seconds) {
  DateTime now = rtc.now();

  // Format jam, menit, dan detik agar selalu 2 digit
  String string_hour = (now.hour() < 10) ? "0" + String(now.hour()) : String(now.hour());
  String string_minute = (minute < 10) ? "0" + String(minute) : String(minute);
  String string_second = (seconds < 10) ? "0" + String(seconds) : String(seconds);

  return get_date_time(1) + " " + string_hour + ":" + string_minute + ":" + string_second;
}

// Fungsi untuk mendapatkan waktu dengan presisi detik
String get_precission_second(int seconds) {
  DateTime now = rtc.now();

  // Format jam, menit, dan detik agar selalu 2 digit
  String string_hour = (now.hour() < 10) ? "0" + String(now.hour()) : String(now.hour());
  String string_minute = (now.minute() < 10) ? "0" + String(now.minute()) : String(now.minute());
  String string_second = (seconds < 10) ? "0" + String(seconds) : String(seconds);

  return get_date_time(1) + " " + string_hour + ":" + string_minute + ":" + string_second;
}