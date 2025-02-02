#include <Arduino.h>
#include <analogWrite.h>
#include "esp32-hal-ledc.h"
#include <Fuzzy.h>

Fuzzy *fuzzy = new Fuzzy();

// Pin untuk LED
const int ledHijau = 26;  // LED hijau untuk kipas pelan
const int ledKuning = 25; // LED kuning untuk kipas standar
const int ledMerah = 33;  // LED merah untuk kipas cepat

void Kipas_setup(){
  analogWriteFrequency(4, 20000);

  // Inisialisasi pin LED sebagai output
  pinMode(ledHijau, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  // Konfigurasi Fuzzy Logic untuk Input CO2
  FuzzyInput *co2 = new FuzzyInput(1);
  FuzzySet *rendah = new FuzzySet(350, 350, 1300, 2300);
  co2->addFuzzySet(rendah);
  FuzzySet *sedang = new FuzzySet(1300, 2300, 3000, 4050);
  co2->addFuzzySet(sedang);
  FuzzySet *tinggi = new FuzzySet(3000, 4050, 5050, 5050);
  co2->addFuzzySet(tinggi);
  fuzzy->addFuzzyInput(co2);

  // Konfigurasi Fuzzy Logic untuk Output Kipas
  FuzzyOutput *kipas = new FuzzyOutput(1);
  FuzzySet *pelan = new FuzzySet(0, 0, 85, 125);       // Kategori pelan
  kipas->addFuzzySet(pelan);
  FuzzySet *standar = new FuzzySet(85, 125, 170, 210); // Kategori sedang
  kipas->addFuzzySet(standar);
  FuzzySet *cepat = new FuzzySet(170, 210, 255, 255);  // Kategori cepat
  kipas->addFuzzySet(cepat);
  fuzzy->addFuzzyOutput(kipas);

  // Aturan Fuzzy Logic
  FuzzyRuleAntecedent *ifCo2Rendah = new FuzzyRuleAntecedent();
  ifCo2Rendah->joinSingle(rendah);
  FuzzyRuleConsequent *thenKipasPelan = new FuzzyRuleConsequent();
  thenKipasPelan->addOutput(pelan);
  FuzzyRule *fuzzyRule01 = new FuzzyRule(1, ifCo2Rendah, thenKipasPelan);
  fuzzy->addFuzzyRule(fuzzyRule01);

  FuzzyRuleAntecedent *ifCo2Sedang = new FuzzyRuleAntecedent();
  ifCo2Sedang->joinSingle(sedang);
  FuzzyRuleConsequent *thenKipasStandar = new FuzzyRuleConsequent();
  thenKipasStandar->addOutput(standar);
  FuzzyRule *fuzzyRule02 = new FuzzyRule(2, ifCo2Sedang, thenKipasStandar);
  fuzzy->addFuzzyRule(fuzzyRule02);

  FuzzyRuleAntecedent *ifCo2Tinggi = new FuzzyRuleAntecedent();
  ifCo2Tinggi->joinSingle(tinggi);
  FuzzyRuleConsequent *thenKipasCepat = new FuzzyRuleConsequent();
  thenKipasCepat->addOutput(cepat);
  FuzzyRule *fuzzyRule03 = new FuzzyRule(3, ifCo2Tinggi, thenKipasCepat);
  fuzzy->addFuzzyRule(fuzzyRule03);
}