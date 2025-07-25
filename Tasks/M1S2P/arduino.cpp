// The code is designed to toggle an LED on and off when the user presses it,
// but the simulation behaviour corresponds to the light being toggled only when the user
// holds their finger down on the button, no toggle. There's also some pretty
// noticeable latency, so the sleep(500) creates a janky experience.

// Here we instaniate constants for pins 2 (I/O interrupt) and 13 (LED)
const uint8_t BTN_PIN = 2;
const uint8_t LED_PIN = 13;

// Unsigned ints for tracking previous button state, and the current led
// state. Both are initialised to LOW.
uint8_t buttonPrevState = LOW;
uint8_t ledState = LOW;

// Swtup helper function for configuring the pins to behave as intended
void setup()
{
    // The button interrupt, configuring BTN_PIN with an internal pull-up resistor
    // for reliable HIGH/LOW signal, doesn't need a resistor
    pinMode(BTN_PIN, INPUT_PULLUP);
    // Configure the LED_PIN to be an output
    pinMode(LED_PIN, OUTPUT);
    // Initialise a serial monitor for debugging and logging at the baud rate matching
    // Arduino Uno's
    Serial.begin(9600);
}

void loop()
{
    // Read in the current button state, initialised to LOW in setup(),
    // and set new unsigned int buttonState to its current value
    uint8_t buttonState = digitalRead(BTN_PIN);

    // Print for reference, let's us see the state for our button and LED,
    // and the previous state of the button
    Serial.print(buttonState);
    Serial.print(buttonPrevState);
    Serial.print(ledState);
    Serial.println("");

    // A check for buttonState against its previous state,
    // toggle LED if they're not the same
    if (buttonState == LOW && buttonPrevState == HIGH) // when pushed, if previous state was not, so single push toggle on button down only
    {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState); // write the inverse of ledState to LED_PIN
        Serial.print("LED state change: ");
        Serial.print(ledState);
        Serial.println("");
        Serial.print("Btn state change: ");
        Serial.print(buttonState);
        Serial.println("");
        delay(15); // much snappier but still long enough for stability
    }

    buttonPrevState = buttonState; // update previous state to reflect current state for next iteration

    // Pause code execution for 500 millis after each iteration to prevent rapid toggling,
    // makes it easier to observe in simulation
    // delay(500);
}