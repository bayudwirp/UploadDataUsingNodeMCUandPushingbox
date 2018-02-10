// Sintaks program dibawah ini, disadur dari
// http://roboticbasics.blogspot.co.id/2016/06/sensor-suhu-lm35-lengkap-dengan-program-arduino.html
// https://www.hackster.io/detox/transmit-esp8266-data-to-google-sheets-8fc617

#include "ESP8266WiFi.h"

const char WEBSITE[] = "api.pushingbox.com"; 		//alamat web api pushingbox
const String devid = "vBFF6AEFD72CC6CC"; 			//device ID yang didapat dari pushingbox

const char* MY_SSID = "ckj597";
const char* MY_PWD =  "169341189ckj597";

float suhu_lm35;
int pin_analog_lm35 = 0;


void setup()
{
  Serial.begin(115200);								//Baudrate yang digunakan 115200
  Serial.print("Menghubungkan ke "+*MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  Serial.println("Menghubungkan koneksi");

  while (WiFi.status() != WL_CONNECTED) 			//Proses Koneksi ke Access Point. Dilakukan hingga terkoneksi.
    {
      delay(1000);
      Serial.print(".");
    }
  Serial.println("WiFi Terhubung");
  Serial.println("");
  Serial.println("SSID dan Password tepat. Koneksi WiFi terhubung");
  Serial.println("");
}


void loop()
{
  delay(1000); 												//Beri delay pengiriman selama 1 detik (1000ms)

  suhu_lm35 = analogRead(pin_analog_lm35); 					//membaca nilai adc sensor
  suhu_lm35 = (suhu_lm35 / 1024.0)* 5000;					//konversi data analog menjadi nilai milivolt
  suhu_lm35 = (suhu_lm35/10); 							   //konversi kedalam derajat celsius dengan persamaan 1derajat/10mv
  float celData = suhu_lm35;
  Serial.print("Temperatur : ");
  Serial.print((byte)celData);
  Serial.println(" *C ");

  WiFiClient client; 										//Proses mengirimkan data ke pushingbox

	if (client.connect(WEBSITE, 80))
	  { 
		 client.print("GET /pushingbox?devid=" + devid
	   + "&data_suhu=" + (String) celData
		 );
	  client.println(" HTTP/1.1"); 
	  client.print("Host: ");
	  client.println(WEBSITE);
	  client.println("User-Agent: ESP8266/1.0");
	  client.println("Connection: close");
	  client.println();
	  }
}
Setelah beres memprogram, maka langkah selanjutnya yaitu mengupload program dan menjalan program
