/*
 * ntc_sensor.c
 *
 * Created: 31.10.2019 
 *  Author: Cemal BAYRAKTAR
 */ 
#include "ntc_sensor.h"
#include <avr/io.h>
#include <math.h>

const float a =  0.003434;		//NTC denklemindeki a,b,c katsay� de�erleri.
const float b = -0.000171;
const float c =  0.0000019;


void ntc_sensor_init(){
	ADCSRA  |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));		//adc frekans 125khz ayarland�
	ADMUX   |= (1<<REFS0);								//referans gerilimi se�ildi
	ADCSRA  |= (1<<ADEN);								//adc a��ld�
	ADCSRA  |= (1<<ADSC);								//ilk �evrim yap�l�p haz�r hale getirildi...
}

int adc_cevrimi_yap(){
	ADMUX   &= 0x40;					//kanal 0 se�ildi.
	ADCSRA  |= (1<<ADSC);				//�evirim ba�lat���yor.
	while(ADCSRA & (1<<ADSC));			//�evrim bitene kadar bekler
	return ADCW;						//�evrim sonucu
}

float get_ntc_sensor_olcum(){
	
	adc_sonuc = adc_cevrimi_yap();								//adc �evrim sonucu float de�i�kene at�ld�. (float olmasa idi V de�erinin k�s�rat�n� do�ru hesaplam�yor)
	V  = (adc_sonuc*5)/1024;									//O an ki �l��len Voltaj.
	R  = (uint16_t)((10000*V)/(5-V));							//O an ki Rntc de�eri.
	Tk = 1 / ( a + (b*log(R)) + (c*log(R)*log(R)*log(R)) );		//T kelvin.
	Tc = Tk - 273.15;											//T celcius.
	
	return Tc;
}