#include "pinutils.h"

ScopedPin::ScopedPin(uint8_t pin_number, uint8_t alive_value)
: pin_number(pin_number), scope_left_value((alive_value == HIGH) ? LOW : HIGH)
{
    digitalWrite(pin_number, alive_value);
}

ScopedPin::~ScopedPin()
{
    digitalWrite(pin_number, scope_left_value);
}


ScopedTogglePin::ScopedTogglePin(uint8_t pin_number) : pin_number(pin_number)
{
    toggle();
}

ScopedTogglePin::~ScopedTogglePin()
{
    toggle();
}

void ScopedTogglePin::toggle()
{
    if(digitalRead(pin_number))
        digitalWrite(pin_number, 0);
    else
        digitalWrite(pin_number, 1);
}


TogglePin::TogglePin(uint8_t pin_number) : pin_number(pin_number)
{
}

void TogglePin::toggle()
{
    if(digitalRead(pin_number))
        digitalWrite(pin_number, 0);
    else
        digitalWrite(pin_number, 1);
}