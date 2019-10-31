/*
 * ntc_sensor.h
 *
 * Created: 31.10.2019 
 *  Author: Cemal BAYRAKTAR
 *
 *	10K NTC i�in kullan�lmal�d�r.
 *	10K diren� ve 10K NTC ile gerilim b�l�c� yap�ld�ktan sonra NTC �zerindeki gerilim ADC0 kanal�na ba�land�.
 */ 


#ifndef NTC_SENSOR_H_
#define NTC_SENSOR_H_
#include <stdint.h>					//uint16_t kulland���m�z i�in include etmemiz gerekti.

	char printbuffT [4];			//float sonucu stringe �evirip LCD'yazd�rmak i�in kullan�lacak. ("dtostrf()" fonksiyonu i�in laz�m)
	volatile float adc_sonuc;		//Sens�rden gelen analog i�aretin dijital �evrim sonucunu tutar.Normalde cevrim sonucu tam say�d�r,fakat b�lme i�lemleri do�ru ��kmas� i�in float olmal�. 
	volatile float V;				//Analog-Dijital �evrim sonucun Voltaj kar��l���.
	volatile float Tk,Tc;			//Kelvin ve Celsius s�cakl�k de�erleri.
	volatile uint16_t R;			//NTC potans de�eri
	
	
	
	void ntc_sensor_init();			//adc ayarlar�n�n yap�ld��� fonksiyon.		
	float get_ntc_sensor_olcum();	//�l��len s�cakl�k de�erini C derece olarak getirir.
	
	

#endif /* NTC_SENSOR_H_ */