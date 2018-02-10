# UploadDataUsingNodeMCUandPushingbox
Merupakan Sebuah project sederhana untuk melakukan input data sensor LM35 ke google sheet menggunakan bantuan api pushingbox.
Cara kerja dari program ini yaitu LM35 akan mendeteksi suhu, kemudian akan mengirimkan data analog untuk dibaca oleh NodeMCU, lalu NodeMCU akan mengirimkan data hasil pembacaan suhu tersebut ke google sheet yang sudah diatur sebelumnya dengan menggunakan perantara api pushingbox.


Program ini disadur untuk kemudian dimodifikasi dari :
http://roboticbasics.blogspot.co.id/2016/06/sensor-suhu-lm35-lengkap-dengan-program-arduino.html
https://www.hackster.io/detox/transmit-esp8266-data-to-google-sheets-8fc617
