/*
 * ntc_sensor.h
 *
 * Created: 31.10.2019 
 *  Author: Cemal BAYRAKTAR
 *
 *	10K NTC için kullanýlmalýdýr.
 *	10K direnç ve 10K NTC ile gerilim bölücü yapýldýktan sonra NTC üzerindeki gerilim ADC0 kanalýna baðlandý.
 */ 


#ifndef NTC_SENSOR_H_
#define NTC_SENSOR_H_
#include <stdint.h>					//uint16_t kullandýðýmýz için include etmemiz gerekti.

	char printbuffT [4];			//float sonucu stringe çevirip LCD'yazdýrmak için kullanýlacak. ("dtostrf()" fonksiyonu için lazým)
	volatile float adc_sonuc;		//Sensörden gelen analog iþaretin dijital çevrim sonucunu tutar.Normalde cevrim sonucu tam sayýdýr,fakat bölme iþlemleri doðru çýkmasý için float olmalý. 
	volatile float V;				//Analog-Dijital çevrim sonucun Voltaj karþýlýðý.
	volatile float Tk,Tc;			//Kelvin ve Celsius sýcaklýk deðerleri.
	volatile uint16_t R;			//NTC potans deðeri
	
	
	
	void ntc_sensor_init();			//adc ayarlarýnýn yapýldýðý fonksiyon.		
	float get_ntc_sensor_olcum();	//ölçülen sýcaklýk deðerini C derece olarak getirir.
	
	

#endif /* NTC_SENSOR_H_ */