#include <TinyGPS++.h>
#include <HardwareSerial.h>

TinyGPSPlus gps;
// ESP32'nin ikinci donanımsal seri portunu (Serial2) kullanacağız
// RX pini = 16, TX pini = 17
HardwareSerial gpsSerial(2);

void setup() {
  // Bilgisayar ile haberleşme için Seri Port'u başlat (Hata ayıklama için)
  Serial.begin(115200);
  
  // GPS modülü ile haberleşme için Serial2'yi başlat
  // NEO-6M modüller genellikle varsayılan olarak 9600 baud hızında çalışır
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17); // RX: 16, TX: 17

  Serial.println("ESP32 - GPS Entegrasyon Testi Başlatıldı.");
  Serial.println("Uydu sinyali aranıyor... (Bu birkaç dakika sürebilir)");
  Serial.println("--------------------------------------------------");
}

void loop() {
  // GPS modülünden yeni veri geldikçe...
  while (gpsSerial.available() > 0) {
    // Gelen veriyi TinyGPS++ kütüphanesine işlemesi için gönder
    if (gps.encode(gpsSerial.read())) {
      // Veri başarıyla çözümlendiğinde (yeni bir NMEA cümlesi tamamlandığında)
      // Ekrana bilgileri yazdır.
      printGPSData();
    }
  }

  // Eğer 5 saniye boyunca hiç GPS verisi gelmezse, bir uyarı yazdır
  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println("HATA: GPS modülünden veri alınamıyor. Bağlantıları (TX/RX) kontrol edin.");
    delay(50000); // 5 saniye bekle
  }
}

// GPS verilerini Seri Port Ekranı'na yazdırmak için bir fonksiyon
void printGPSData() {
  Serial.print("Konum: ");
  if (gps.location.isValid()) {
    Serial.print(gps.location.lat(), 6); // Enlem
    Serial.print(", ");
    Serial.print(gps.location.lng(), 6); // Boylam
  } else {
    Serial.print("GEÇERSİZ");
  }

  Serial.print("  Uydu Sayısı: ");
  if (gps.satellites.isValid()) {
    Serial.print(gps.satellites.value());
  } else {
    Serial.print("GEÇERSİZ");
  }

  Serial.print("  Hız (km/s): ");
  if (gps.speed.isValid()) {
    Serial.print(gps.speed.kmph());
  } else {
    Serial.print("GEÇERSİZ");
  }

  Serial.println();
}