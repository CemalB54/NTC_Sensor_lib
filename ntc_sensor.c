/*
 * ntc_sensor.c
 *
 * Created: 31.10.2019 
 *  Author: Cemal BAYRAKTAR
 */ 
#include "ntc_sensor.h"
#include <avr/io.h>
#include <math.h>

const float a =  0.003434;		//NTC denklemindeki a,b,c katsayý deðerleri.
const float b = -0.000171;
const float c =  0.0000019;


void ntc_sensor_init(){
	ADCSRA  |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));		//adc frekans 125khz ayarlandý
	ADMUX   |= (1<<REFS0);								//referans gerilimi seçildi
	ADCSRA  |= (1<<ADEN);								//adc açýldý
	ADCSRA  |= (1<<ADSC);								//ilk çevrim yapýlýp hazýr hale getirildi...
}

int adc_cevrimi_yap(){
	ADMUX   &= 0x40;					//kanal 0 seçildi.
	ADCSRA  |= (1<<ADSC);				//çevirim baþlatýþýyor.
	while(ADCSRA & (1<<ADSC));			//çevrim bitene kadar bekler
	return ADCW;						//çevrim sonucu
}

float get_ntc_sensor_olcum(){
	
	adc_sonuc = adc_cevrimi_yap();								//adc çevrim sonucu float deðiþkene atýldý. (float olmasa idi V deðerinin küsüratýný doðru hesaplamýyor)
	V  = (adc_sonuc*5)/1024;									//O an ki ölçülen Voltaj.
	R  = (uint16_t)((10000*V)/(5-V));							//O an ki Rntc deðeri.
	Tk = 1 / ( a + (b*log(R)) + (c*log(R)*log(R)*log(R)) );		//T kelvin.
	Tc = Tk - 273.15;											//T celcius.
	
	return Tc;
}