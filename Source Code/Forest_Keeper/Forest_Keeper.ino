#include <ESP8266WiFi.h>
#include <DHT.h>
#include <MQ7.h>

//서버에 전송하기 위한 초기설정
const char* server = "api.thingspeak.com";
String apiKey = "4A18X4EP968MLP3W";
const char* MY_SSID = "GENYF WIFI";//와이파이 이름
const char* MY_PWD = "genyfwifi";//와이파이 비밀번호

const int flame_pin1 = D1;
const int flame_pin2 = D2;
const int flame_pin3 = D3;
const int flame_pin4 = D4;
const int dht11_pin = D5;
const int sound_pin = D6;
const int vibration_pin = D7;
const int mq7_pin = A0;

#define DHTTYPE DHT11
DHT dht11(dht11_pin, DHTTYPE);
MQ7 mq7(A0, 5.0);

void setup()
{
	Serial.begin(115200);
	delay(10);
	dht11.begin();

	//와이파이 연결
	Serial.print("Connecting to " + *MY_SSID);

	WiFi.begin(MY_SSID, MY_PWD);

	while (WiFi.status() != WL_CONNECTED) {
		delay(1000);
		Serial.print(".");
	}

	Serial.println("\nConnected\n");
}

void loop()
{
	int Flame = 1, Sound = 1, Vibration = 0;
	double Humi = 0, Temp = 0, mq7ppm = 0;

	for (int i = 0; i < 10; i++)
	{
		int Tflame = 1;
		int Tflame_1 = digitalRead(flame_pin1);
		int Tflame_2 = digitalRead(flame_pin2);
		int Tflame_3 = digitalRead(flame_pin3);
		int Tflame_4 = digitalRead(flame_pin4);
		int TSound = digitalRead(sound_pin);
		int TVibration = digitalRead(vibration_pin);

		double THumi = dht11.readHumidity();
		double TTemp = dht11.readTemperature();
		double Tmq7ppm = mq7.getPPM();

		if (Tflame_1 == 0 || Tflame_2 == 0 || Tflame_3 == 0 || Tflame_4 == 0)
		{
			Tflame = 0;

			if (Tflame == 0)
			{
				Flame = 0;
			}
		}

		if (TSound == 0) 
		{
			Sound = 0;
		}
		
		if (TVibration == 1)
		{
			Vibration = 1;
		}

		Humi += THumi;
		Temp += TTemp;
		mq7ppm += Tmq7ppm;

		delay(1000);
	}

	Humi = Humi / 10;
	Temp = Temp / 10;
	mq7ppm = mq7ppm / 10;

	ServerUpload(Flame, Humi, Temp, mq7ppm, Sound, Vibration);

	delay(3000);
}

void ServerUpload(int Flame, double Humi, double Temp, double mq7ppm, int Sound, int Vibration)
{
	WiFiClient client;//Wifi 연결

	Serial.println("Flame :  " + String(Flame));
	Serial.println("Humi :" + String(Humi) + "%");
	Serial.println("Temp :" + String(Temp) + "C");
	Serial.println("CO :" + String(mq7ppm) + "ppm");
	Serial.println("Sound :" + String(Sound));
	Serial.println("Vibration :" + String(Vibration));

	if (client.connect(server, 80)) { // 서버에 전송
		Serial.println("WiFi Client connected");

		String postStr = apiKey;
		postStr += "&field1=";
		postStr += String(Flame);
		postStr += "&field2=";
		postStr += String(Humi);
		postStr += "&field3=";
		postStr += String(Temp);
		postStr += "&field4=";
		postStr += String(mq7ppm);
		postStr += "&field5=";
		postStr += String(Sound);
		postStr += "&field6=";
		postStr += String(Vibration);
		postStr += "\r\n\r\n";

		client.print("POST /update HTTP/1.1\n");
		client.print("Host: api.thingspeak.com\n");
		client.print("Connection: close\n");
		client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
		client.print("Content-Type: application/x-www-form-urlencoded\n");
		client.print("Content-Length: ");
		client.print(postStr.length());
		client.print("\n\n");
		client.print(postStr);
	}
	Serial.print("Waiting...\n\n\n");
	client.stop();
}