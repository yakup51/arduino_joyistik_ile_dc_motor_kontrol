const int motor = 11; // motor için pin tanımla
const int pot = A3; // potansiyometre için pin tanımla
int xPin = A0; // joystickin x-ekseni için pin tanımla
int butonPin = 2; // joystickin butonu için pin tanımla
int xPozisyon; // joystickin x-pozisyonunu saklamak için bir değişken bildir
int butonDurum; // joystickin buton durumunu saklamak için bir değişken bildir
int kirmizi=3; // kırmızı LED için pin tanımla
int yesil=4; // yeşil LED için pin tanımla
void setup()  
{  
pinMode(motor, OUTPUT); // motor pinini çıkış olarak ayarla
pinMode(kirmizi,OUTPUT); // kırmızı LED pinini çıkış olarak ayarla
pinMode(yesil,OUTPUT); // yeşil LED pinini çıkış olarak ayarla
Serial.begin(9600); // seri haberleşme başlat
pinMode(xPin, INPUT); // x-ekseni pinini giriş olarak ayarla
pinMode(butonPin, INPUT_PULLUP); // buton pinini giriş ve yukarı çekme direnci olarak ayarla
}    

void loop()  
{  
xPozisyon = analogRead(xPin); // x-ekseni pininden analog değer oku ve xPozisyon değişkenine ata
butonDurum = digitalRead(butonPin); // buton pininden dijital değer oku ve butonDurum değişkenine ata
  int reading = xPozisyon;  // okunan değeri reading değişkenine ata 
  int spd = map(reading, 0, 1023, 0, 100); // reading değerini 0-1023 aralığından 0-100 aralığına eşleştir ve spd değişkenine ata
  int spd_1=map(reading,0,1023,0,255); // reading değerini 0-1023 aralığından 0-255 aralığına eşleştir ve spd_1 değişkenine ata
  if(butonDurum==1) // eğer buton durumu 1 ise (yani basılmamış ise)
  {
  analogWrite(motor, spd); // motor pinine spd değerinde analog sinyal gönder (motor hızını ayarla)
  digitalWrite(yesil,1); // yeşil LED'i yak
  digitalWrite(kirmizi,0); // kırmızı LED'i söndür
  }
  else // eğer buton durumu 0 ise (yani basılı ise)
  {
  analogWrite(motor, spd_1); // motor pinine spd_1 değerinde analog sinyal gönder (motor hızını ayarla)
  digitalWrite(kirmizi,1); // kırmızı LED'i yak
  digitalWrite(yesil,0); // yeşil LED'i söndür
  }
}  
