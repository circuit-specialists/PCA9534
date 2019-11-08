# PCA9534 I/O Expander

PCA9534 GPIO expander library for Particle devices with Particle like API calls. It makes working with PCA9534 I/O expander pins easier, with familiar functions like `pinMode()` and `digitalWrite()`. Refer to the [datasheet](pca9534.pdf) for more information about the chip.

## Usage

![Hardware connection](images/hardware_connection.png "Hardware connection setup")

Connect an LED to PCA9534 pin 0 chip, add the PCA9534 library to your project and follow this simple example:

```Arduino
#include "PCA9534.h"

#define GPIO_PIN_LED 0

PCA9534 gpio;

void setup() {
  gpio.begin();
  gpio.pinMode(GPIO_PIN_LED, OUTPUT);
}

void loop() {
  gpio.digitalWrite(GPIO_PIN_LED, LOW); // LED On
  delay(500);
  gpio.digitalWrite(GPIO_PIN_LED, HIGH); // LED Off
  delay(500);
}
```

See the examples folder for more details.

## Documentation

### `PCA9534`
Creates a new PCA9534 class to manage a PCA9534 chip.

```Arduino
#include "PCA9534.h"
...
...
PCA9534 gpio;
...
...
void setup() {
  gpio.begin();
}
```

### `begin([i2caddr])`
Initializes the device and performs initial I2C setup. This method should be called before any others are used.

#### Parameters:
| Name | Type | Description |
|------|------|-------------|
| `i2caddr` | `uint8_t` | Sets the slave address of the PCA9534, defaults to 0x20. |

```Arduino
void setup() {
  gpio.begin(0x20);
}
```

### `pinMode(pin, mode)`
Configures the specified pin to behave either as an input, inverted input, or output.

#### Parameters:
| Name | Type | Description |
|------|------|-------------|
| `pin` | `uint8_t` | Pin number whose mode you wish to set. |
| `mode` | `uint8_t` | Pin mode one of: `INPUT`, `INPUT_INVERTED`, or `OUTPUT`. |

```Arduino
void setup() {
  gpio.begin();
  gpio.pinMode(0, OUTPUT);
}
```

### `digitalWrite(pin, value)`
Writes a `HIGH` or a `LOW` value to a digital pin.

#### Parameters:
| Name | Type | Description |
|------|------|-------------|
| `pin` | `uint8_t` | Pin number whose value you wish to set. |
| `value` | `uint8_t` | Pin value one of: `HIGH`, or `LOW`. |

```Arduino
void loop() {
  gpio.digitalWrite(0, LOW);
  delay(500);
  gpio.digitalWrite(0, HIGH);
  delay(500);
}
```

### `digitalRead(pin)`
Reads the value from a specified digital pin, either `HIGH` or `LOW`.

*Note: when using `INPUT_INVERTED` on `pinMode()`, you will get the inverted status.*

#### Parameters:
| Name | Type | Description |
|------|------|-------------|
| `pin` | `uint8_t` | Pin number whose value you wish to get. |

#### Returns:
`uint8_t` - The status of the pin either HIGH or LOW.

```Arduino
void loop() {
  uint8_t buttonStatus = gpio.digitalRead(1);
  if (buttonStatus == HIGH) {
    gpio.digitalWrite(0, LOW); // LED On
  } else {
    gpio.digitalWrite(0, HIGH); // LED Off
  }
}
```

## LICENSE
Copyright 2017 Abdulrahman Saleh Khamis (original author) Licensed under the MIT license
Copyright 2019 Jake Pring (modifier) Additions/Modifications licensed as GPLv3
