#include <DHT.h>  // Include the DHT sensor library

// Define the pin numbers
#define DHTPIN 2       // Pin for DHT11 data
#define LED1_PIN 9     // Pin for LED 1 (temperature high)
#define LED2_PIN 10    // Pin for LED 2 (temperature low)

// Define the DHT sensor type
#define DHTTYPE DHT11  // Change to DHT22 if using a DHT22 sensor

// Create an instance of the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  
  // Initialize the DHT sensor
  dht.begin();
  
  // Set LED pins as output
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // Initially turn off both LEDs
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);  // DHT11 requires a 2-second interval between readings
  
  // Read the humidity and temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Temperature in Celsius
  float f=dht.readTemperature(true);

  // Check if the readings are valid
  if (isnan(humidity) || isnan(temperature))  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  float hif=dht.computeHeatIndex(f, humidity);
  float hic=dht.computeHeatIndex(temperature, humidity, false);
  // Print the values to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("  Temperature: ");
  Serial.print(temperature);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");


  // Control LEDs based on temperature
  if (temperature > 30) {
    // If temperature is greater than 25°C, turn on LED1
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);  // Turn off LED2
  } 
  else if (temperature < 15) {
    // If temperature is lower than 18°C, turn on LED2
    digitalWrite(LED1_PIN, LOW);  // Turn off LED1
    digitalWrite(LED2_PIN, HIGH);
  } 
  else {
    // If temperature is between 18°C and 25°C, turn off both LEDs
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  }
}
